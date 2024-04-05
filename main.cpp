#include <iostream>
#include "Sensor.h"
#include "SensorFactory.h"
#include "AerospaceControlSystem.h"

int main()
{
	// start of question 1

	std::cout << "########## START OF QUESTION 1 ##########" << std::endl;
	std::cout << std::endl;

	AerospaceControlSystem ctrlSys; // creation of object specified in class

	ctrlSys.addSensor(SensorFactory::createSensor("temperature"));
	ctrlSys.addSensor(SensorFactory::createSensor("pressure"));
	ctrlSys.addSensor(SensorFactory::createSensor("altitude")); // static function in SensorFactory library is used to input pointer into addSensor() of object

	ctrlSys.monitorAndAdjust(); // output

	std::cout << std::endl;
	std::cout << "########## END OF QUESTION 1 ##########" << std::endl;
	std::cout << std::endl;

	// end of question 1

	// start of question 2

	std::cout << "########## START OF QUESTION 2 ##########" << std::endl;
	std::cout << std::endl;



	std::cout << std::endl;
	std::cout << "########## END OF QUESTION 2 ##########" << std::endl;
	std::cout << std::endl;

	// end of question 2

}