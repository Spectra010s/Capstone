# Codebase Explanation: RF Controlled Car (Receiver)


This document explains structure and function of the how the [**receiver.ino**](./receiver.ino) works, which acts as the 'brain' of the robot. Its sole purpose is to listen for wireless commands from the companion Transmitter (Joystick) unit and convert those commands into motor movements using the L298N motor driver.

---

## Hardware Required

- Arduino Uno (receiver)

- MX-RM-5V RF receiver

- L298N motor driver

- 2 DC motors

- LEDs for direction indicators

- Breadboard & jumper wires

- Power source

---


## 1. Hardware and Pin Configuration

This code assumes the use of an Arduino board (e.g., Uno or Nano) and an MX-RM-5V 433 MHz RF Receiver module connected to an L298N Motor Driver.

| Component | Pin | Function |
|---|---|---|
| RF Receiver | D2 | Data (Interrupt 0) |
|Motor 1 (Left) | ENA (9) | PWM Speed Control |
| Motor 1 (Left) | IN1 (5), IN2 (6) | Direction Control |
| Motor 2 (Right) | ENB (10) | PWM Speed Control |
|Motor 2 (Right) | IN3 (7), IN4 (8) | Direction Control |
| LED Pins | D3, D4 | Visual indicators |



## 1. Libraries and Hardware Configuration

### RCSwitch Library

- **#include <RCSwitch.h>**: This library handles the encoding and transmission of simple **On-Off Keying (OOK)** radio frequency signals, commonly used with inexpensive 433 MHz RF modules (like the FS1000A).

- **mySwitch.enableReceive(0)**: Activates the RF receiver module on **Interrupt 0**, which corresponds to **Digital Pin 2** on most Arduinos. The receiver's DATA pin must be connected here.
- **mySwitch.setProtocol(1)** / **mySwitch.setPulseLength(180)**: **Crucial**. These radio settings must **EXACTLY MATCH** those defined on the Transmitter unit to successfully decode the signal.

### Motor Driver (L298N) Pins

The L298N is configured to control two independent motors (Motor 1 and Motor 2) using six digital pins and two Pulse Width Modulation (PWM) pins for speed control.

| Component   | Pin     | Function |
| :------ | :-------- | :---------- |
| **Motor 1 (Left)**  | ENA (9)          | PWM Speed Control                |
|                     | IN1 (5), IN2 (6) | Direction Control                |
| **Motor 2 (Right)** | ENB (10)         | PWM Speed Control                |
|                     | IN3 (7), IN4 (8) | Direction Control                |
| **LED Pins**        | D3, D4           | Visual indicators for direction. |

---

## 2. Command Codes and Movement Logic

### Unique RF Codes

The code defines the same set of unique unsigned long integers as the Transmitter. These are the "words" the receiver listens for:

| Code Constant    | Action                             |
| :--------------- | :-------------- |
| *CODE_STOP*      | Stops the robot.                   |
| *CODE_FORWARD*    | Moves straight ahead.              |
| *CODE_BACKWARD*    | Moves straight back.               |
| *CODE_LEFT*        | Turns left (swing turn).           |
| *CODE_RIGHT*       | Turns right (swing turn).          |
| *CODE_PIVOT_LEFT*  | Spins left in place (point turn).  |
| *CODE_PIVOT_RIGHT* | Spins right in place (point turn). |

### Main Loop (`loop()`)

1.  **Check Availability**: `if (mySwitch.available())` checks if a complete RF command packet has been successfully received and decoded.
2.  **Read and Debug**: `mySwitch.getReceivedValue()` retrieves the command code (e.g., 100001). This value, along with debugging information, is printed to the Serial Monitor.
3.  **Execute Command**: A sequence of `if/else if` statements compares the `receivedValue` against the predefined **CODE_XXX** constants.
4.  **Motor and LED Control**: Once a match is found, the corresponding **movement function** (`moveForward`, `turnLeft`, etc.) is called, and the status LEDs are updated.
5.  **Reset**: `mySwitch.resetAvailable()` clears the internal buffer, preparing the receiver to listen for the next command.

---

## 3. Motor Control Functions (The Missing Brain Cells)

These functions abstract the low-level pin manipulations required by the L298N driver, translating high-level commands into physical action.

### Helper Function

- `void setMotor(int in1, int in2, int ena, int dir1, int dir2, int speed)`: This is the **low-level wrapper** that writes the direction (`dir1`/`dir2`) and speed (`speed`) values to a single motor's pins.

### Movement Implementation

Each movement function uses `setMotor` to command both the Left (Motor 1) and Right (Motor 2) wheels:

- **`moveForward()` / `moveBackward()`**: Both motors are driven in the same direction.
- **`stopMotors()`**: Sets all IN pins to LOW and PWM (ENA/ENB) to 0, applying a **brake** to the motors for a fast stop.
- **`turnLeft()` / `turnRight()`**: One motor is driven forward while the other motor is stopped or braked (resulting in a wide, **swing turn**).
- **`pivotLeft()` / `pivotRight()`**: One motor is driven forward while the other is driven backward at the same speed (resulting in a tight, **point turn**).



> Notes

- Ensure motor driver and motors are connected correctly to prevent damage.

- LEDs are optional but provide visual feedback.

- Adjust `DEFAULT_SPEED` as needed for your motors.

- Protocol and pulse length must match transmitter settings.
