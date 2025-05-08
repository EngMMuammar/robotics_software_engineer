#ifndef DISTANCE_SENSOR_HPP
#define DISTANCE_SENSOR_HPP

#include "Sensor.hpp"

class DistanceSensor : public Sensor<int> {
public:
    DistanceSensor(int dist) : Sensor(dist) {}
    void show() {
        std::cout << "Distance: " << value << " cm" << std::endl;
    }
};

#endif
