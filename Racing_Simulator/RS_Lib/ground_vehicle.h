#pragma once

#include "vehicle.h"

class Ground_Vehicle: public Vehicle
{
	protected:

		double pause_time; // - Время отдыха
		double pause_distance; // - Время движения до отдыха
		int pause_count; // - счетчик остановок

public:
		Ground_Vehicle();
};