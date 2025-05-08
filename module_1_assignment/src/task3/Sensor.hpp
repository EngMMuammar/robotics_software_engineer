#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <iostream>

template <typename T>
class Sensor {
protected:
    T value;

public:
    Sensor(T val) : value(val) {}
    void displayReading() {
        std::cout << "Sensor reading: " << value << std::endl;
    }
};

#endif
