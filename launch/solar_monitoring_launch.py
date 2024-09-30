from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='my_solar_monitoring',
            executable='solar_power_publisher',
            name='solar_power_publisher',
            output='screen'
        ),
        Node(
            package='my_solar_monitoring',
            executable='solar_power_subscriber',
            name='solar_power_subscriber',
            output='screen'
        ),
    ])
