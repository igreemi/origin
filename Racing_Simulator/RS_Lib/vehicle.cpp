#include "vehicle.h"

Vehicle::Vehicle() {}

std::string Vehicle::GetName()
{
	return name;
}

double Vehicle::TravelTime()
{
	return travel_time;
}

int Vehicle::TypeOfTransport() {
	return this->type_of_transport;
}
