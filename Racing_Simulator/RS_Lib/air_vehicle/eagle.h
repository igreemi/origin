#pragma once
#include "air_vehicle.h"

class Eagle : public Air_Vehicle
{
public:
	Eagle(int distance);
	double ReductionFactor();
};