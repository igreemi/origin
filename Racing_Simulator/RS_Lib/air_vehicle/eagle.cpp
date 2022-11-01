#include "eagle.h"

int Eagle::ReductionFactor()
{

		return distance * 0.06;

}
Eagle::Eagle(int distance)
{
	this->distance = distance; // - расстояние
	this->name = "Орел"; // - название транспорта

	this->speed = 8; // - скорость транспорта

	this->travel_time = (distance - ReductionFactor()) / speed; // - общее время движения

}