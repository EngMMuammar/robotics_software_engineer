#ifndef ACTUATOR_H
#define ACTUATOR_H

#include <string>

class Actuator {
protected:
    std::string name;

public:
    Actuator(std::string name);
    virtual ~Actuator() = default;

    std::string getName();
    virtual void activate() = 0;
    virtual void deactivate() = 0;
};

class ArmActuator : public Actuator {
public:
    ArmActuator(std::string name);
    void move(int angle);
    void activate() override;
    void deactivate() override;
};

class WheelActuator : public Actuator {
public:
    WheelActuator(std::string name);
    void rotate(int degrees);
    void activate() override;
    void deactivate() override;
};

#endif
