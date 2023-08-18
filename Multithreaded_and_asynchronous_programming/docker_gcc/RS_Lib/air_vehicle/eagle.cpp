#include "eagle.h"

double Eagle::ReductionFactor()
{

	return (distance * 0.06);

}
Eagle::Eagle()
{
}
Eagle::Eagle(int distance)
{
	this->distance = distance;
	this->name = "Орел";

	this->speed = 8;

	this->travel_time = (distance - ReductionFactor()) / speed;

}