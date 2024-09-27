#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"
#include <cstdlib> 
#include <ctime>   

class SolarPowerPublisher : public rclcpp::Node
{
public:
    SolarPowerPublisher() : Node("solar_power_publisher")
    {
        publisher_ = this->create_publisher<std_msgs::msg::Float32>("solar_power_data", 10);
        timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&SolarPowerPublisher::publish_solar_data, this));

        
        std::srand(std::time(nullptr));
    }

private:
    void publish_solar_data()
    {
        auto message = std_msgs::msg::Float32();
        float current = static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / 10.0));  // Aram
        float voltage = static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / 100.0)); // Feszultseg

        //Teljesitmeny
        float power = current * voltage;
        message.data = power;

        RCLCPP_INFO(this->get_logger(), "Publishing Solar Power: %.2f W", message.data);
        publisher_->publish(message);
    }

    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SolarPowerPublisher>());
    rclcpp::shutdown();
    return 0;
}
