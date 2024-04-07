#ifndef AEROSPACECONTROLSYSTEM
#define AEROSPACECONTROLSYSTEM

#include <iostream>
#include <vector>
#include "Sensor.h"

class AerospaceControlSystem
{
	std::vector<Sensor*> sensorList; // vector used since provides easy way to plug in sensors
public:
	void addSensor(Sensor* input); // takes in Sensor pointer and adds it to sensorList
	void monitorAndAdjust(); // calls gatherData() and processData() for each element on sensorList
};

#endif