#pragma once

#include <string>

class Vehicle
{
protected:
	std::string name;
	int type_of_transport = 0;
	double speed = 0.0;
	int distance = 0;
	double travel_time = 0.0;
public:
	Vehicle();
	std::string GetName();
	double TravelTime();
	int TypeOfTransport();
};


