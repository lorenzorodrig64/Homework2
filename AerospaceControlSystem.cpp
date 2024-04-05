#include "AerospaceControlSystem.h"

void AerospaceControlSystem::addSensor(Sensor* input) 
{
	sensorList.push_back(input); // adds sensors to sensor vector
}

void AerospaceControlSystem::monitorAndAdjust() 
{
	for (auto sensor : sensorList)
	{
		sensor->gatherdata();
		sensor->processdata(); // calls on functions of each object on vector
		std::cout << "Adjusting controls based on sensor data." << std::endl;
	}
}