#pragma once
#include "air_vehicle.h"

class MagicCarpet : public Air_Vehicle
{
public:
	MagicCarpet(int distance);
	int ReductionFactor();
};