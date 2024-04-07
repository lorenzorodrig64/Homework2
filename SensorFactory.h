#ifndef SENSORFACTORY
#define SENSORFACTORY

#include <iostream>
#include <string>
#include "Sensor.h"

class SensorFactory
{
public:
	static Sensor* createSensor(std::string input); // static function which takes in a string and returns a Sensor class pointer
};

#endif