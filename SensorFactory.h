#ifndef SENSORFACTORY
#define SENSORFACTORY

#include <iostream>
#include <string>
#include "Sensor.h"

class SensorFactory
{
public:
	static Sensor* createSensor(std::string input);
};

#endif