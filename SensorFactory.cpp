#include "SensorFactory.h"

Sensor* SensorFactory::createSensor(std::string input)
{
	if (input == "temperature")
	{
		return new temperature_sensor(); // address to a temperature sensor is returned
	}
	else if (input == "pressure")
	{
		return new pressure_sensor(); // address to a pressure sensor is returned
	}
	else if (input == "altitude")
	{
		return new altitude_sensor(); // address to an alititude sensor is returned
	}
	else
	{
		return nullptr;
	}

}