#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

class SpiralMover : public rclcpp::Node {
public:
    SpiralMover() : Node("spiral_mover"), speed_(0.5) {
        pub_ = create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
        timer_ = create_wall_timer(std::chrono::milliseconds(100), std::bind(&SpiralMover::move, this));
    }

private:
    void move() {
        geometry_msgs::msg::Twist msg;
        msg.linear.x = speed_;
        msg.angular.z = 1.0;
        pub_->publish(msg);
        speed_ += 0.01;
    }

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_;
    rclcpp::TimerBase::SharedPtr timer_;
    double speed_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SpiralMover>());
    rclcpp::shutdown();
    return 0;
}
