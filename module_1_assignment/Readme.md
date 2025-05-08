# Module 1 Assignment: Introduction to OOP Concepts in C++ for Robotics

## Project Overview

This repository contains C++ programs that demonstrate basic Object-Oriented Programming (OOP) concepts in a robotics context. The task focuses on simulating a robotic system, incorporating actuators, sensors, and robot behaviors using fundamental OOP principles like classes, inheritance, and polymorphism.

### Learning Outcomes
By completing this assignment, you will:
- Understand and apply basic OOP concepts in C++.
- Simulate robot behaviors, including movement and actuator control.
- Work with class inheritance and polymorphism to handle different types of actuators (e.g., arm and wheel actuators).
- Simulate sensor data and handle different sensor types in the robot's environment.

## Folder Structure

The project is divided into several tasks, each with its own specific functionality:

- **include/**: Contains header files for the robot and actuator classes.
- **src/**: Contains source files for the program, including actuator and robot behavior logic.
- **CMakeLists.txt**: CMake configuration for building the project.
- **package.xml**: ROS package configuration file.
- **README.md**: This documentation file.

## Tasks

### Task 1: Robot Class Implementation
In this task, a `Robot` class is implemented with attributes like `name`, `speed`, `weight`, `size`, and `number_of_sensors`. Methods like `moveForward()`, `moveBackward()`, and `stop()` are implemented to simulate robot movement. Different robots are simulated using namespaces.

### Task 2: Simulating Sensor Readings
A program is created to simulate a robot equipped with temperature and distance sensors. The sensor data is hardcoded, and the program prints sensor readings (e.g., `Temperature: 20°C`, `Distance: 100cm`) to the console.

### Task 3: Sensor Library Design
A simple sensor library is designed with two classes: `TemperatureSensor` and `DistanceSensor`. The sensor readings are simulated and printed. Additionally, a generic template class is used to handle multiple sensor types like double, string, and char data.

### Task 4: Debugging a Multi-File C++ Project
In this task, a multi-file project simulates a robot system with actuators. The actuators (arm and wheel) are represented as classes inheriting from a base `Actuator` class. Methods to activate, deactivate, and manipulate the actuators are implemented. Polymorphism is used for handling different types of actuators. The task also focuses on debugging and fixing compilation issues in a multi-file C++ project.

## Requirements

- **C++14 or later**: The project uses modern C++ features.
- **CMake**: Required to build the project using ROS 2's build system.
- **ROS 2**: Ensure your ROS 2 workspace is set up (if applicable).
- **ament_cmake**: CMake extension for ROS 2 build.

## Building the Project

1. **Clone the repository**:
   ```bash
   git clone https://github.com/EngMMuammar/robotics_software_engineer.git
   cd module_1_assignment

2. **Create a build directory**:
Navigate to your project directory and create a build directory:
   ```bash
   mkdir build
   cd build
   ```

3. **Build the project**:
Run the following commands to configure and build the project using CMake:
   ```bash
   cmake ..
   make
   ```

4. **Run the executables**:
Once the project is built, you can run the corresponding executables for each task