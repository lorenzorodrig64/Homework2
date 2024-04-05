#ifndef AEROSPACECONTROLSYSTEM
#define AEROSPACECONTROLSYSTEM

#include <iostream>
#include <vector>
#include "Sensor.h"

class AerospaceControlSystem
{
	std::vector<Sensor*> sensorList; // vector used since provides easy way to plug in sensors
public:
	void addSensor(Sensor* input);
	void monitorAndAdjust();
};

#endif