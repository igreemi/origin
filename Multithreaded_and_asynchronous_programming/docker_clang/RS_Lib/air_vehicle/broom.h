﻿#pragma once
#include "../air_vehicle.h"

class Broom : public Air_Vehicle
{
public:
	Broom();
	Broom(int distance);
	double ReductionFactor();
};