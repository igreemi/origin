#pragma once
#include "air_vehicle.h"

class Eagle : public Air_Vehicle
{
public:
	Eagle(int distance);
	int ReductionFactor();
};