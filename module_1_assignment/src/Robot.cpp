#include "Robot.h"
#include <iostream>

Robot::Robot(std::string name, double speed)
    : name(name), speed(speed) {}

void Robot::activateActuator(Actuator& actuator) {
    std::cout << "Robot " << name << " is activating actuator: " << actuator.getName() << std::endl;
    actuator.activate();
}

void Robot::deactivateActuator(Actuator& actuator) {
    std::cout << "Robot " << name << " is deactivating actuator: " << actuator.getName() << std::endl;
    actuator.deactivate();
}
