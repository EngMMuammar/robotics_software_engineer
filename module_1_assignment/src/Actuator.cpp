#include "Actuator.h"
#include <iostream>

Actuator::Actuator(std::string name) : name(name) {}

std::string Actuator::getName() {
    return name;
}

ArmActuator::ArmActuator(std::string name) : Actuator(name) {}

void ArmActuator::move(int angle) {
    std::cout << "Moving arm actuator " << name << " to angle " << angle << " degrees." << std::endl;
}

void ArmActuator::activate() {
    std::cout << "Activating arm actuator: " << name << std::endl;
}

void ArmActuator::deactivate() {
    std::cout << "Deactivating arm actuator: " << name << std::endl;
}

WheelActuator::WheelActuator(std::string name) : Actuator(name) {}

void WheelActuator::rotate(int degrees) {
    if (degrees > 360 || degrees < -360) {
        std::cout << "Rotation angle is too large!" << std::endl;
    }
    std::cout << "Rotating wheel actuator " << name << " by " << degrees << " degrees." << std::endl;
}

void WheelActuator::activate() {
    std::cout << "Activating wheel actuator: " << name << std::endl;
}

void WheelActuator::deactivate() {
    std::cout << "Deactivating wheel actuator: " << name << std::endl;
}
