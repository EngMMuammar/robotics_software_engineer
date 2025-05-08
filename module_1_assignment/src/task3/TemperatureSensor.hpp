#ifndef TEMPERATURE_SENSOR_HPP
#define TEMPERATURE_SENSOR_HPP

#include "Sensor.hpp"

class TemperatureSensor : public Sensor<double> {
public:
    TemperatureSensor(double temp) : Sensor(temp) {}
    void show() {
        std::cout << "Temperature: " << value << "°C" << std::endl;
    }
};

#endif
