#include "broom.h"

double Broom::ReductionFactor()
{
	int redFact = (distance / 1000);
	return static_cast<double>(distance * redFact / 100);

}
Broom::Broom()
{
}
Broom::Broom(int distance)
{
	this->distance = distance;
	this->name = "Метла";

	this->speed = 20;

	this->travel_time = (distance - ReductionFactor()) / speed;

}