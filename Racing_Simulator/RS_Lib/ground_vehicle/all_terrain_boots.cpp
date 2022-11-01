#include "all_terrain_boots.h"

AllTerrainBoots::AllTerrainBoots(int distance)
{
	this->distance = distance; // - расстояние
	this->name = "Ботинки-вездеходы"; // - название транспорта

	this->speed = 6; // - скорость транспорта
	this->pause_distance = 60; // - Время движения до отдыха

	this->pause_count = (distance / speed) / pause_distance; // - счетчик остановок
	this->pause_time = 10 + (pause_count - 1) * 5; // - Время отдыха

	this->travel_time = (distance / speed) + pause_time; // - общее время движения

}