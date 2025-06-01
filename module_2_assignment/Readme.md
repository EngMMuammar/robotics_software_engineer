# Module 2 Assignment: Developing Custom ROS 2 Nodes and Launch Files

## Project Overview

This project involves creating custom ROS 2 C++ nodes and Python launch files to control the Turtlesim simulator. It includes turtle motion control, spawning multiple turtles using services, adjusting behavior with parameters, and debugging node communication using the `UInt8MultiArray` message type.



## Folder Structure

- `launch/`: Python launch files to start the Turtlesim simulator, spawn turtles, and run custom ROS 2 nodes for movement and LED control.
- `src/`: C++ source files implementing turtle movement patterns (circle, spiral, back and forth) and LED state publisher/subscriber nodes.
- `CMakeLists.txt`: Build configuration file specifying how to compile the C++ nodes and link dependencies.
- `package.xml`: ROS 2 package manifest defining package information and dependencies.

## Tasks



### Task 1: Create a Custom ROS 2 Node

In this task, two C++ nodes were implemented to control the Turtlesim turtle’s movement:

- `circle_mover.cpp`: The turtle is moved in a circle using a user-provided radius.
- `spiral_mover.cpp`: The turtle is moved in a logarithmic spiral by adjusting velocities over time.

Velocity commands are published by both nodes to control the turtle’s motion in Turtlesim.


### Task 2: Develop a Launch File

In this task, a Python launch file was created to start the Turtlesim simulation and the custom turtle control nodes simultaneously.

The launch file (`turtle_control.launch.py`) ensures coordinated execution of the Turtlesim node along with the circle and spiral mover nodes, simplifying node management.

**Commands to run the launch file:**
```bash
ros2 launch module_2_assignment turtle_control.launch.py
```




### Task 3: Modify the Turtlesim Simulation Environment

In this task, a Python launch file (`turtle_spawner.launch.py`) was created to spawn 5 turtles diagonally across the Turtlesim window using the `/spawn` service. 

Additionally, the middle 3 turtles were controlled to move back and forth continuously using a custom C++ node (`turtle_backforth.cpp`) that sends velocity commands via ROS 2 services.

**Commands to run the launch file:**
```bash
ros2 launch module_2_assignment turtle_spawner.launch.py
```

### Task 4: Modify Turtle Behavior with Parameters

In this task, ROS 2 parameters were used to dynamically control the speed of the turtles during the simulation. The speed parameter was declared and updated in the custom C++ nodes controlling the turtles’ movement, allowing real-time speed adjustments without restarting the nodes.

**Commands to run the turtle control node with a custom speed parameter:**
```bash
ros2 run module_2_assignment circle_mover --ros-args -p speed:=2.0
```

### Task 5: Debugging a ROS 2 Node Using a Message Type

In this task, debugging and fixing of a ROS 2 package handling the `std_msgs/msg/UInt8MultiArray` message type were performed. The package includes two C++ nodes: a publisher (`led_publisher.cpp`) that publishes LED states, and a subscriber (`led_subscriber.cpp`) that receives and logs these states.

Key issues addressed:
- Correct handling of the `UInt8MultiArray` message type.
- Fixing errors in message publishing and subscribing.
- Correct parameter usage and logging.

**Commands to build the package:**
```bash
colcon build --packages-select module_2_assignment
source install/setup.bash
```

**Commands to run the nodes separately for debugging:**
```bash
ros2 run module_2_assignment led_publisher
ros2 run module_2_assignment led_subscriber
```
**Using the launch file to run both nodes together:**
```bash
ros2 launch module_2_assignment led_control.launch.py

```

**Useful debugging commands:**

- To view active topics:
```bash
ros2 topic list
```
- To echo messages on the LED states topic:
```bash
ros2 topic echo /led_states
```

- To check node parameters:
```bash
ros2 param list /led_publisher
ros2 param get /led_publisher <param_name>

```
- To set or change parameters dynamically:
```bash
ros2 param set /led_publisher <param_name> <value>

```

- To check running nodes and their info:
```bash
ros2 node list
ros2 node info /led_publisher

```

- To check the message interface, you can use:
```bash
ros2 interface show std_msgs/msg/UInt8MultiArray


```
## Learning Outcome

By completing this assignment, you will:
- Understand how to develop and execute custom nodes in ROS 2.
- Learn the utility of launch files in managing the execution of multiple nodes in ROS 2.
- Learn how to interact with ROS 2 services to modify node behavior and simulation environments.
- Understand how to use ROS 2 parameters to control and alter the behavior of nodes in real-time.
---

