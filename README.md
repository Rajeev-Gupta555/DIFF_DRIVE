# Arduino Open Loop Differential Drive Control

This GitHub repository contains Arduino code for controlling a differential drive robot using open-loop control. The code consists of several files, each implementing different movement patterns for the robot. The code is organised into classes to define motors and the robot itself.

## Table of Contents

- [Introduction](#introduction)
- [Setup](#setup)
- [Files](#files)
- [Usage](#usage)
- [Movement Patterns](#movement-patterns)
- [Contributing](#contributing)

## Introduction

This repository provides Arduino code to control a differential drive robot using open-loop control. The robot's movement is achieved by controlling the speed and direction of two individual motors.

## Setup

Components used:
1. Arduino uno
2. L298 Motor Driver
3. 2 DC motors
4. Jumper wires and chassis

Make sure to connect the motors to the appropriate pins on the Arduino and set up the motor drivers as required by your hardware.

## Files

The repository contains the following files:
These files define the `_Motor` class, which is used to control individual motors. It provides methods to set the motor's speed and direction. An another class `Diff_drive` is also defined, which represents the robot. This class uses two instances of the `Motor` class to control the left and right motors of the robot.

3. **square.ino**: This Arduino sketch demonstrates how to make the robot move in a square pattern.

4. **circle.ino**: This sketch demonstrates how to make the robot move in a circular pattern.

5. **only_forw.ino**: This sketch demonstrates how to make the robot move in a straight line.

6. **forw_back.ino**: This sketch demonstrates continuous forward and backward movement of the robot.

## Usage

1. Upload the required Arduino sketch to your Arduino board.
2. Define the pwm and direction pins for the respective motors.
3. Ensure that the connections to the motors and motor drivers are correctly set up.
4. Power on the robot and observe its movement based on the selected pattern.

## Movement Patterns

### Square Movement

The `square.ino` sketch moves the robot in a square pattern by controlling the motors to turn at 90-degree angles.

### Circular Movement

The `circle.ino` sketch moves the robot in a circular pattern by varying the speed of the motors on different sides.

### Straight Line Movement

The `only_forw.ino` sketch moves the robot in a straight line by keeping the speed of both motors equal.

### Forward-Backward Movement

The `forw_back.ino` sketch continuously moves the robot forward and backward by alternating the motor directions.

## Contributing

Contributions to this repository are welcome. If you have improvements or additional movement patterns to add, feel free to submit a pull request.

---

Feel free to use and modify the provided code according to your needs. If you have any questions or suggestions, please don't hesitate to open an issue or contact the repository owner. Happy robotics experimenting!
