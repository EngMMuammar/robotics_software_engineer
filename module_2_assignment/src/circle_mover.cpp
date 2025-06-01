#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

class CircleMover : public rclcpp::Node {
public:
    CircleMover() : Node("circle_mover") {
        declare_parameter("radius", 1.0);
        double radius = get_parameter("radius").as_double();
        linear_ = 2.0;
        angular_ = linear_ / radius;

        pub_ = create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
        timer_ = create_wall_timer(std::chrono::milliseconds(100), std::bind(&CircleMover::move, this));
    }

private:
    void move() {
        geometry_msgs::msg::Twist msg;
        msg.linear.x = linear_;
        msg.angular.z = angular_;
        pub_->publish(msg);
    }

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_;
    rclcpp::TimerBase::SharedPtr timer_;
    double linear_, angular_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CircleMover>());
    rclcpp::shutdown();
    return 0;
}
