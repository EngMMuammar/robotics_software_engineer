from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(package='turtlesim', executable='turtlesim_node', name='sim'),
        Node(
            package='module_2_assignment',
            executable='spiral_mover',  # Change to 'spiral_mover' or "circle_mover"
            name='circle_node',
            parameters=[{'radius': 2.0}]
        )
    ])
