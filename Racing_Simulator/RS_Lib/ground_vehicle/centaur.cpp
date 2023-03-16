#include "centaur.h"

Centaur::Centaur(int distance)
{
	this->distance = distance;
	this->name = "Кентавр";

	this->speed = 15;
	this->pause_distance = 8;

	this->pause_count = static_cast<int>((distance / speed) / pause_distance);
	this->pause_time = (pause_count * 2);

	this->travel_time = (distance / speed) + pause_time;

}