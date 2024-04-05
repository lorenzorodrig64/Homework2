#include "SensorFactory.h"

Sensor* SensorFactory::createSensor(std::string input)
{
	if (input == "temperature")
	{
		return new temperature_sensor();
	}
	else if (input == "pressure")
	{
		return new pressure_sensor();
	}
	else if (input == "altitude")
	{
		return new altitude_sensor();
	}
	else
	{
		return nullptr;
	}

}