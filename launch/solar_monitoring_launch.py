from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='solar_monitoring',
            executable='solar_power_publisher',
            name='solar_power_publisher'
        ),
        Node(
            package='solar_monitoring',
            executable='solar_power_subscriber',
            name='solar_power_subscriber'
        )
    ])
