#include "magic_carpet.h"

int MagicCarpet::ReductionFactor()
{
	if (distance < 1000)
	{
		return distance;
	}
	else if (distance < 5000)
	{
		return distance * 0.03;
	}
	else if (distance < 10000)
	{
		return distance * 0.1;
	}
	else if (distance >= 10000)
	{
		return distance * 0.05;
	}
}
MagicCarpet::MagicCarpet(int distance)
{
	this->distance = distance; // - расстояние
	this->name = "Ковер-самолет"; // - название транспорта

	this->speed = 10; // - скорость транспорта

	this->travel_time = (distance - ReductionFactor()) / speed; // - общее время движения

}