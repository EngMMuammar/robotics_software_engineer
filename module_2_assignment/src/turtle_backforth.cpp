#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

class TurtleMover : public rclcpp::Node {
public:
    TurtleMover() : Node("turtle_backforth"), direction_(1.0) {
        for (int i = 3; i <= 5; ++i) {
            auto topic = "/turtle" + std::to_string(i) + "/cmd_vel";
            pubs_.push_back(create_publisher<geometry_msgs::msg::Twist>(topic, 10));
        }
        timer_ = create_wall_timer(std::chrono::seconds(2), std::bind(&TurtleMover::move, this));
    }

private:
    void move() {
        geometry_msgs::msg::Twist msg;
        msg.linear.x = direction_;
        for (auto &pub : pubs_) pub->publish(msg);
        direction_ *= -1;
    }

    std::vector<rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr> pubs_;
    rclcpp::TimerBase::SharedPtr timer_;
    double direction_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TurtleMover>());
    rclcpp::shutdown();
    return 0;
}
