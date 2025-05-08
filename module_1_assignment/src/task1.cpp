#include <iostream>
#include <string>

namespace MyRobot {
    class Robot {
    private:
        std::string name;
        double speed;
        double weight;
        double size;
        int number_of_sensors;

    public:
        Robot(std::string n, double s, double w, double sz, int sensors)
            : name(n), speed(s), weight(w), size(sz), number_of_sensors(sensors) {}

        void moveForward() {
            std::cout << name << " is moving forward at speed " << speed << std::endl;
        }

        void moveBackward() {
            std::cout << name << " is moving backward at speed " << speed << std::endl;
        }

        void stop() {
            std::cout << name << " has stopped." << std::endl;
        }
    };
}

int main() {
    MyRobot::Robot myrobot("MyRobot", 2.5, 15.0, 0.5, 4);
    myrobot.moveForward();
    myrobot.moveBackward();
    myrobot.stop();

    return 0;
}
