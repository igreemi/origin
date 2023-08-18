#pragma once

#include "vehicle.h"

class Ground_Vehicle : public Vehicle
{
protected:

	double pause_time = 0.0;
	double pause_distance = 0.0;
	int pause_count = 0;

public:
	Ground_Vehicle();
};