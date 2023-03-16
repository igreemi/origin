#include "speed_camel.h"

SpeedCamel::SpeedCamel(int distance)
{
	this->distance = distance;
	this->name = "Верблюд-быстроход";

	this->speed = 40;
	this->pause_distance = 10;

	this->pause_count = static_cast<int>((distance / speed) / pause_distance);
	this->pause_time = 5 + 6.5 + (pause_count - 2) * 8;

	this->travel_time = (distance / speed) + pause_time;

}