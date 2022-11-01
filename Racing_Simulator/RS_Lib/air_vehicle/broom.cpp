#include "broom.h"

double Broom::ReductionFactor()
{
	int redFact = distance / 1000;
	return (distance * redFact / 100);

}
Broom::Broom(int distance)
{
	this->distance = distance; // - расстояние
	this->name = "Метла"; // - название транспорта

	this->speed = 20; // - скорость транспорта

	this->travel_time = (distance - ReductionFactor()) / speed; // - общее время движения

}