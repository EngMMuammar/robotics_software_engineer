#include "TemperatureSensor.hpp"
#include "DistanceSensor.hpp"
#include "Sensor.hpp"

int main() {
    TemperatureSensor tempSensor(22.5);
    DistanceSensor distSensor(150);

    tempSensor.show();
    distSensor.show();

    Sensor<std::string> stringSensor("ON");
    Sensor<char> charSensor('A');

    stringSensor.displayReading();
    charSensor.displayReading();

    return 0;
}
