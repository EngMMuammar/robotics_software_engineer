from launch import LaunchDescription
from launch.actions import ExecuteProcess
from launch_ros.actions import Node

def generate_launch_description():
    turtles = [
        (1.0, 10.0, 'turtle2'),
        (3.0, 8.0, 'turtle3'),
        (5.0, 6.0, 'turtle4'),
        (7.0, 4.0, 'turtle5'),
        (9.0, 2.0, 'turtle6'),
    ]

    spawns = [
        ExecuteProcess(
            cmd=[
                'ros2', 'service', 'call', '/spawn',
                'turtlesim/srv/Spawn',
                f'"{{x: {x}, y: {y}, theta: 0.0, name: \\"{name}\\"}}"'
            ],
            shell=True
        )
        for x, y, name in turtles
    ]

    return LaunchDescription([
        Node(package='turtlesim', executable='turtlesim_node', name='sim'),
        *spawns,
        Node(package='module_2_assignment', executable='turtle_backforth', name='backforth')
    ])
