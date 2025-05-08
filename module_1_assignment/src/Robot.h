#ifndef ROBOT_H
#define ROBOT_H

#include <string>
#include "Actuator.h"

class Robot {
private:
    std::string name;
    double speed;

public:
    Robot(std::string name, double speed);
    void activateActuator(Actuator& actuator);
    void deactivateActuator(Actuator& actuator);
};

#endif
