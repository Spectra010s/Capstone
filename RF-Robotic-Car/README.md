# Capstone - RF Controlled Robotic Car

## Introduction

This project is a simple remote-controlled car built using Arduino, RF modules, Joystick module, and L298N motor driver.
The transmitter uses the Joystick to send control signals via an FS1000A RF pair & Arduino Nano, while the receiver (Arduino Uno & MX-RM-5V pair) interprets these signals and drives the motors.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Repository Structure](#repository-structure)
- [Hardware Used](#hardware-used)
- [How to Upload](#how-to-upload)
- [License](#license)

## Features

- Forward, backward, left, right movement via joystick.
- Independent LED for headlights (toggle from remote).
- Custom made controller
- Direction indicator LED (lights up based on motion).
- Powered by 12V lithium-ion battery pack.

## Repository Structure

- **transmitter/** → Arduino Nano code for the RF remote controller.
- **receiver/** → Arduino Nano code for the robotic car.
- **docs/** → Circuit diagrams, schematics, or images.

## Hardware Used

- Arduino Uno
- Arduino Nano
- FS1000A RF Transmitter
- MX-RM-5V RF Receiver
- Joystick Module
- L298N Motor Driver
- Ready Made Chasis
- Jumper Cables
- 12V Lithium-ion Battery with BMS
- 4 Hobby Gear Motors
- LEDs for direction and lights

## How to Upload

1. Open `transmitter/transmitter.ino` in Arduino IDE → upload to transmitter Nano.
2. Open `receiver/receiver.ino` in Arduino IDE → upload to receiver Nano.

## [License](LICENSE)

This project is licensed under the MIT License.
