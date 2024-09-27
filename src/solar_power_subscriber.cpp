#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

class SolarPowerSubscriber : public rclcpp::Node
{
public:
    SolarPowerSubscriber() : Node("solar_power_subscriber")
    {
        subscription_ = this->create_subscription<std_msgs::msg::Float32>(
            "solar_power_data", 10, std::bind(&SolarPowerSubscriber::solar_power_callback, this, std::placeholders::_1));
    }

private:
    void solar_power_callback(const std_msgs::msg::Float32::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "Received Solar Power: %.2f W", msg->data);

        if (msg->data < 5.0)
        {
            RCLCPP_WARN(this->get_logger(), "WARNING: Solar power is too low! Potential issue detected.");
        }
    }

    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr subscription_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SolarPowerSubscriber>());
    rclcpp::shutdown();
    return 0;
}
