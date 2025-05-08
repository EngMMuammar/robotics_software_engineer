#include "Robot.h"
#include "Actuator.h"

int main() {
    // Instantiate robot and actuators
    Robot myRobot("Explorer", 5.0);
    ArmActuator arm("Left Arm");
    WheelActuator wheel("Front Left Wheel");

    // Simulate actuator operations
    myRobot.activateActuator(arm);
    arm.move(90);

    myRobot.activateActuator(wheel);
    wheel.rotate(45);

    myRobot.deactivateActuator(arm);
    myRobot.deactivateActuator(wheel);

    return 0;
}
