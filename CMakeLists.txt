cmake_minimum_required(VERSION 3.5)
project(solar_monitoring)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(solar_power_publisher src/solar_power_publisher.cpp)
ament_target_dependencies(solar_power_publisher rclcpp std_msgs)

add_executable(solar_power_subscriber src/solar_power_subscriber.cpp)
ament_target_dependencies(solar_power_subscriber rclcpp std_msgs)

install(TARGETS
  solar_power_publisher
  solar_power_subscriber
  DESTINATION lib/${PROJECT_NAME})


install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}/
)

ament_package()
