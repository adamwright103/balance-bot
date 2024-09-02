# Balance Bot

Welcome to my Balance Bot project! The goal of this project is to experiment with the principles of control systems,
understand basic electronic principles, and further my R&D abillities.

## Project Overview

The Balance Bot is a self-balancing robot with the following key features:

- **Two-Wheeled Design**: The robot is equipped with two wheels, which allow it to move and balance on its own.
- **PID Control System**: The robot uses a PID control algorithm to maintain its balance. The system continuously
  adjusts the motor speeds to keep the robot upright.
- **Sensor Integration**: The bot utilizes sensors like accelerometers and gyroscopes to monitor its orientation and
  make real-time adjustments.
- **Microcontroller**: The bot is controlled by an Arduino Uno that processes the MPU6050 and executes the PID control
  algorithm.

## Features

- **Self-Balancing**: The main feature of the Balance Bot is its ability to stay upright on its own.
- **Real-Time Feedback**: The robot continuously monitors its position and adjusts motor speeds accordingly.
- **Customizable PID Parameters**: The PID control parameters can be fine-tuned to achieve optimal balance and
  stability.

## Getting Started

### List of Materials

- 1x Arduino Uno
- 2x 12V DC motors with encoders (JGA25-370)
- 1x MPU6050
- 1x L928N Motor driver
- 3x 18650 batteries
- 1x series 18650 battery holder

### Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/adamwright103/balance-bot.git

### Credits

- [MPU6050 Datasheet](https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Datasheet1.pdf)
- [Arduino and MPU6050 Accelerometer and Gyroscope Tutorial](https://howtomechatronics.com/tutorials/arduino/arduino-and-mpu6050-accelerometer-and-gyroscope-tutorial/#google_vignette)
    - Author: [Dejan](https://howtomechatronics.com/author/howtom12_wp/)
- [How to Use a Three-Axis Accelerometer for Tilt Sensing](https://wiki.dfrobot.com/How_to_Use_a_Three-Axis_Accelerometer_for_Tilt_Sensing)
