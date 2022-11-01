#pragma once

#include <string>

class Vehicle
{
protected:
	std::string name;
	int type_of_transport;
	double speed;
	double distance;
	double travel_time;
public:
	Vehicle();
	std::string GetName();
	double TravelTime();
	int TypeOfTransport();
};


