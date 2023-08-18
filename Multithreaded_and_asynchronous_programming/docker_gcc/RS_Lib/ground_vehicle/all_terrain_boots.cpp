#include "all_terrain_boots.h"

AllTerrainBoots::AllTerrainBoots()
{
}

AllTerrainBoots::AllTerrainBoots(int distance)
{
	this->distance = distance;
	this->name = "Ботинки-вездеходы";

	this->speed = 6;
	this->pause_distance = 60;

	this->pause_count = static_cast<int>((distance / speed) / pause_distance);
	this->pause_time = 10 + (pause_count - 1) * 5;

	this->travel_time = (distance / speed) + pause_time;

}