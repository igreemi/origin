#include "camel.h"

Camel::Camel()
{
}

Camel::Camel(int distance)
{
	this->distance = distance;
	this->name = "Верблюд";
	
	this->speed = 10;
	this->pause_distance = 30;
	
	this->pause_count = static_cast<int>((distance / speed) / pause_distance);
	this->pause_time = 5 + ((pause_count - 2) * 8);

	this->travel_time = (distance / speed) + pause_time;
	
}