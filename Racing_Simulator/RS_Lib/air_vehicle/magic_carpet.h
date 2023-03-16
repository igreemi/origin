#pragma once
#include "air_vehicle.h"

class MagicCarpet : public Air_Vehicle
{
public:
	MagicCarpet(int distance);
	double ReductionFactor();
};