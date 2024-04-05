#include "Sensor.h"

void temperature_sensor :: gatherdata()
{
	std::cout << "Gathering data from temperature Sensor." << std::endl;
}

void temperature_sensor::processdata()
{
	std::cout << "Processing data from temperature Sensor." << std::endl;
}

void pressure_sensor::gatherdata()
{
	std::cout << "Gathering data from pressure Sensor." << std::endl;
}

void pressure_sensor::processdata()
{
	std::cout << "Processing data from pressure Sensor." << std::endl;
}

void altitude_sensor::gatherdata()
{
	std::cout << "Gathering data from altitude Sensor." << std::endl;
}

void altitude_sensor::processdata()
{
	std::cout << "Processing data from altitude Sensor." << std::endl;
}