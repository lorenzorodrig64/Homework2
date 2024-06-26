#ifndef SENSOR
#define SENSOR

#include <iostream>
#include <string>

class Sensor // abstract class
{
public:
	virtual void gatherdata() = 0; // virtual function for gathering sensor data
	virtual void processdata() = 0; // virtual function for processing sensor data
};

class temperature_sensor : public Sensor // class for a temperature sensor
{
public:
	void gatherdata();
	void processdata();
};

class pressure_sensor : public Sensor // class for a pressure sensor
{
public:
	void gatherdata();
	void processdata();
};

class altitude_sensor : public Sensor // class for an altitude sensor
{
public:
	void gatherdata();
	void processdata();
};

#endif