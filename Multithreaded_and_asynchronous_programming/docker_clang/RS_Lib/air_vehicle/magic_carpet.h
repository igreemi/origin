#pragma once
#include "../air_vehicle.h"

class MagicCarpet : public Air_Vehicle
{
public:
	MagicCarpet();
	MagicCarpet(int distance);
	double ReductionFactor();
};