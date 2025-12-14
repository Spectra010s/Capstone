# Codebase Explanation: RF Controlled Car (Transmitter)

This document explains the structure and function of the how the [`transmitter.ino`](./transmitter.ino) works, including wiring, joystick logic, and RF code. The codebase is designed to read input from an **analog joystick module** and transmit corresponding movement commands wirelessly using a **433 MHz RF transmitter module** via the **RCSwitch library**.

---

## Hardware Required

- Arduino Nano (transmitter)

- FS1000A RF transmitter

- Joystick module (VRX, VRY, SW)

- Breadboard & jumper wires

- Power source

---

## 1. Libraries and Hardware Configuration

### RCSwitch Library

- **#include <RCSwitch.h>**: This library handles the encoding and transmission of simple **On-Off Keying (OOK)** radio frequency signals, commonly used with inexpensive 433 MHz RF modules (like the FS1000A).
- **mySwitch.enableTransmit(10)**: Configures **Digital Pin 10** as the output pin connected to the DATA line of the RF transmitter module.
- **mySwitch.setProtocol(1)** and **mySwitch.setPulseLength(180)**: These settings define the specific timing and structure of the radio signal. They **must match** the settings used by the companion receiving unit (robot/vehicle) to ensure successful decoding.


### Pin Connection Description


Arduino Pin | Component Pin | Function |
|---|---|---|
A0 | VRX | Joystick X-axis |
A1 | VRY | Joystick Y-axis |
  D2 | SW | Horn button / optional LED |
   D10 | DATA | RF Transmitter Data |
       

### Pin Definitions

- **VRX_PIN (A0)**: Analog input for the **X-axis** (horizontal) movement.
- **VRY_PIN (A1)**: Analog input for the **Y-axis** (vertical) movement.
- **SW_PIN (2)**: Digital input for the joystick **button/switch**, configured with `INPUT_PULLUP`.

---

## 2. RF Transmission Codes

A set of unique, distinct **unsigned long integer codes** are defined. Each code corresponds to a specific movement or state. These codes are sent wirelessly, and the receiver must be programmed to recognize them.

| Code Constant        | Value (Example) | Action                                         |
| :------------------- | :-------------- | :--------------------------------------------- |
| **CODE_STOP**        | 100000          | Vehicle stops (default state).                 |
| **CODE_FORWARD**     | 100001          | Straight forward movement.                     |
| **CODE_BACKWARD**    | 100002          | Straight backward movement.                    |
| **CODE_LEFT**        | 100003          | Turn left while moving (forward or backward).  |
| **CODE_RIGHT**       | 100004          | Turn right while moving (forward or backward). |
| **CODE_PIVOT_LEFT**  | 100005          | Pivot left (turn in place).                    |
| **CODE_PIVOT_RIGHT** | 100006          | Pivot right (turn in place).                   |

---

## 3. Joystick Logic and Control Flow

The `loop()` function continuously reads the joystick and determines the command:

### Deadzone Filtering

- **JOYSTICK_DEADZONE (50)**: This value establishes a safety margin around the center reading (512 on a 0-1023 range). Readings within this range are treated as **centered** to prevent **joystick drift** from sending unwanted movement commands.

### Movement Determination

The core logic uses nested `if/else if/else` statements to prioritize the movement based on the Y-axis (vertical/throttle) first, then the X-axis (horizontal/steering).

1.  **Y-Axis Check (Vertical Movement):**
    - **Forward** ($\text{yValue} < 512 - \text{DEADZONE}$): Executes forward-related steering logic.
    - **Backward** ($\text{yValue} > 512 + \text{DEADZONE}$): Executes backward-related steering logic.
    - **Centered** (Else block): Executes pivot/stop logic (X-axis movement when Y is centered).

2.  **X-Axis Check (Steering/Pivot):**
    - When **Y is NOT centered** (Forward/Backward movement):
      - If X is left/right of the deadzone, **CODE_LEFT** or **CODE_RIGHT** is sent (turning while driving).
      - If X is centered, **CODE_FORWARD** or **CODE_BACKWARD** is sent (straight driving).
    - When **Y IS centered** (Stop state):
      - If X is left/right of the deadzone, **CODE_PIVOT_LEFT** or **CODE_PIVOT_RIGHT** is sent.
      - If X is centered, **CODE_STOP** is sent.

### Transmission and Timing

- **mySwitch.send(codeToSend, 24)**: Transmits the final determined code with a bit length of 24.
- **Serial.println(codeToSend)**: Provides debugging output showing the code currently being transmitted.
- **delay(100)**: Controls the transmission rate, allowing the receiver time to process signals and preventing excessive power consumption or radio interference.

> Notes

- Adjust `JOYSTICK_DEADZONE` if your joystick drifts.

- Pulse length and protocol may vary depending on RF modules.

- Horn button or LEDs can be triggered via `SW_PIN`.



