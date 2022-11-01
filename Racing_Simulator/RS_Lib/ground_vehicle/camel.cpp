#include "camel.h"

Camel::Camel(int distance)
{
	this->distance = distance; // - расстояние
	this->name = "Верблюд"; // - название транспорта
	
	this->speed = 10; // - скорость транспорта
	this->pause_distance = 30; // - Время движения до отдыха
	
	this->pause_count = (distance / speed) / pause_distance; // - счетчик остановок
	this->pause_time = 5 + (pause_count - 1) * 8; // - Время отдыха

	this->travel_time = (distance / speed) + pause_time; // - общее время движения
	
}