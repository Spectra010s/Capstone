# Capstone - RF Controlled Robotic Car

<p align="center">
  <img src="https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white" alt="Arduino Badge"/>
  <img src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="C++ Badge"/>
  <img src="https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge" alt="License Badge"/>
</p>


A remote-controlled robotic car built using the Arduino platform. This project features a custom joystick-based transmitter and a receiver-equipped chassis, communicating wirelessly over a 433MHz RF link to perform precise movements.



## Table of Contents

* [Introduction](#introduction)
* [Features](#features)
* [Repository Structure](#repository-structure)
* [Hardware & Software Requirements](#hardware-software-requirements)
  * [Transmitter](#transmitter)
  * [Receiver](#receiver)
  * [Software](#software)
* [Installation & Setup](#installation--setup)
  * [1. Clone the Repository](#1-clone-the-repository)
  * [2. Install the Required Library](#2-install-the-required-library)
  * [3. Assemble the Circuits](#3-assemble-the-circuits)
  * [4. Upload the Code](#4-upload-the-code)
* [Circuit Connections](#circuit-connections)
  * [Transmitter Wiring (Arduino Nano)](#transmitter-wiring-arduino-nano)
  * [Receiver Wiring (Arduino Uno)](#receiver-wiring-arduino-uno)
* [Usage](#usage)
* [Troubleshooting & Common Issues](#troubleshooting-common-issues)
* [Technologies Used](#technologies-used)
* [Author](#author)
* [License](#license)

## Introduction

This project is a simple remote-controlled car built using Arduino, RF modules, Joystick module, and L298N motor driver.
The transmitter uses the Joystick to send control signals via an FS1000A RF pair & Arduino Nano, while the receiver (Arduino Uno & MX-RM-5V pair) interprets these signals and drives the motors.

## Features


- **Wireless Control**: Operates using FS1000A (Transmitter) and MX-RM-5V (Receiver) RF modules for reliable remote communication.
- **Full Range of Motion**: Supports forward, backward, left/right turns, and pivot-on-the-spot rotations.
- **Intuitive Joystick Interface**: A standard analog joystick provides proportional and intuitive control over the car's movements.
- **Visual Feedback**: Onboard LEDs indicate the car's current movement state (e.g., forward or backward).
- **Robust Motor Control**: Utilizes the L298N H-Bridge Motor Driver for efficient and powerful control of two DC motors.

## Repository Structure


```
RF-Robotic-Car/
├──  Images
│   ├── img.png # visual representative 1
│   └──  vid.mp4
│
├── Transmitter
│   └── transmitter.ino # transmitter file
│
├── Receiver
│   └── receiver.ino   # recivever file
│
├── README.md  # Documentation
└── LICENSE  # license
```

## Hardware & Software Requirements


### Transmitter

- Arduino Nano (or Uno)
- Joystick Module (2-axis with push-button)
- FS1000A RF Transmitter Module
- Breadboard and Jumper Wires

### Receiver

- Arduino Uno
- L298N Motor Driver Module
- MX-RM-5V RF Receiver Module
- 2x DC Geared Motors (with wheels)
- 2x LEDs (e.g., one green, one red)
- Robot Car Chassis
- Power Source (e.g., Li-ion batteries, 7.4V - 9V recommended)

### Software

- [Arduino IDE](https://www.arduino.cc/en/software)
- [RCSwitch Library](https://github.com/sui77/rc-switch)

## Installation & Setup

### 1. Clone the Repository

Clone this project to your local machine.

```bash
git clone https://github.com/Spectra010s/Capstone.git
cd Capstone/RF-Robotic-Car
```

### 2. Install the Required Library

 Open the Arduino IDE, go to **Sketch > Include Library > Manage Libraries...**, and search for and install `RCSwitch`.

### 3. Assemble the Circuits

Wire the components for both the transmitter and receiver as detailed in the "Circuit Connections" section below.

### 4. Upload the Code

- **Transmitter**: Connect the transmitter Arduino (Nano) to your computer, select the correct board and port in the Arduino IDE, and upload the `transmitter/transmitter.ino` sketch.
- **Receiver**: Connect the receiver Arduino (Uno) to your computer, select the correct board and port, and upload the `reciever/reciever.ino` sketch.

## Circuit Connections

### Transmitter Wiring (Arduino Nano)

| Joystick Pin | Arduino Nano Pin | RF Transmitter (FS1000A) Pin | Arduino Nano Pin |
| :----------: | :--------------: | :------------------: | :--------------: |
|     VRX      |        A0        |             VCC              |        5V        |
|     VRY      |        A1        |             GND              |       GND        |
|      SW      |        D2        |             DATA             |       D10        |
|     +5V      |        5V        |                              |                  |
|     GND      |       GND        |                              |                  |

### Receiver Wiring (Arduino Uno)

|  Component   |    Pin    | Arduino Uno Pin | L298N Motor Driver |    Pin     |
| :----------: | :-------: | :-------------: | :----------------: | :--------: |
| RF Receiver  |    VCC    |       5V        |        ENA         |  D9 (PWM)  |
|  (MX-RM-5V)  |    GND    |       GND       |        IN1         |     D5     |
|              |   DATA    |       D2        |        IN2         |     D6     |
| Forward LED  | Anode (+) |       D3        |        IN3         |     D7     |
| Backward LED | Anode (+) |       D4        |        IN4         |     D8     |
|              |           |                 |        ENB         | D10 (PWM)  |
|              |           |                 |    OUT1 & OUT2     |  Motor 1   |
|              |           |                 |    OUT3 & OUT4     |  Motor 2   |
|              |           |                 |        12V         | Power In + |
|              |           |                 |        GND         | Power In - |

_Note: Connect the cathodes of the LEDs to GND via a 220Ω resistor._

## Usage


Once the hardware is assembled and the code is uploaded, power on both the transmitter and the receiver circuits. The car will be in a stationary state.

- **Move Forward**: Push the joystick up.
- **Move Backward**: Pull the joystick down.
- **Turn Right (while moving)**: Push the joystick up and to the right.
- **Turn Left (while moving)**: Push the joystick up and to the left.
- **Pivot Right (on the spot)**: Move the joystick to the right from the center position.
- **Pivot Left (on the spot)**: Move the joystick to the left from the center position.
- **Stop**: Return the joystick to its central, resting position.

> The car's LEDs will light up to indicate forward or backward motion.

## Troubleshooting & Common Issues


If your RF Car isn't moving as expected, check these common issues before revising your code or hardware.

1. No Response (Car is Stationary)
   If the receiver (car) doesn't respond to any joystick input:

- Communication Check: The most likely culprit is an issue with the RF link.
  - Action: Ensure the Arduino Nano (Transmitter) and Arduino Uno (Receiver) are powered on.
  - Action: Verify the DATA pin for both the RF Transmitter (D10 on Nano) and RF Receiver (D2 on Uno) are wired correctly according to the Circuit Connections table.
  - Action: Confirm that the RCSwitch Library is installed correctly in your Arduino IDE.
- Power Check: The L298N Motor Driver often requires a separate, higher voltage supply.
  - Action: Check that the car's 7.4V - 9V battery is connected to the L298N's 12V and GND terminals, and that the battery is charged.
- Code Upload Check: Ensure both the transmitter.ino and receiver.ino sketches have been uploaded successfully to the correct boards (Nano and Uno, respectively).

2. Motors Spin in the Wrong Direction
   If you push the joystick forward but the car moves backward (or vice versa):

- Wiring Issue: The motor polarity is reversed for one or both motors.
  - Action: This is a physical wiring issue. Simply swap the wires connected to the L298N's OUT1 & OUT2 terminals for Motor 1, and/or OUT3 & OUT4 terminals for Motor 2.

3. Only One Motor Responds
   If the car is turning aggressively when you try to go straight:

- Wiring Issue: One motor is disconnected or improperly wired.
  - Action: Verify the connections from the L298N outputs to the non-working motor.
  - Action: Check the motor driver logic pins on the Arduino Uno (D5, D6, D7, D8) to ensure they are firmly connected to the L298N IN1, IN2, IN3, IN4 pins.
- Motor Driver Failure: Less common, but possible, the L298N chip may be faulty.

4. Control is Erratic or Jumpy
   If the car starts and stops unexpectedly or performs commands inaccurately:

- RF Interference: Another device operating near the 433MHz frequency may be causing noise.
  - Action: Try operating the car in a different location, away from heavy Wi-Fi routers or other transmitting devices.
- Joystick Calibration: The joystick may not be returning perfectly to the center position (dead zone).
  - Action: Review the transmitter.ino code and adjust the dead zone (the range of values considered "stop") for the VRX and VRY inputs to prevent accidental movement.

## Technologies Used

|    Technology    |                     Description                     |
| :--------------: | :-------------------------------------------------: |
|   **Arduino**    |   Open-source electronics platform for hardware.    |
|    **C/C++**     | The programming language used for Arduino sketches. |
|  **RF Modules**  |   FS1000A & MX-RM-5V for wireless communication.    |
| **L298N Driver** | An H-Bridge motor driver for controlling DC motors. |

## Author


**Adetayo Adeloye (Spectra010s)**

- **Twitter**: [@Spectra010s](https://twitter.com/Spectra010s)
- **LinkedIn**: [Adeloye Adetayo](https://www.linkedin.com/in/adeloye-adetayo-273723253)
- **Email**: [spectra010s@gmail.com](mailto:spectra010s@gmail.com)
- **Telegram**: [@Spectra010s](https://t.me/Spectra010s)

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.