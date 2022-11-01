#include "speed_camel.h"

SpeedCamel::SpeedCamel(int distance)
{
	this->distance = distance; // - расстояние
	this->name = "Верблюд-быстроход"; // - название транспорта

	this->speed = 40; // - скорость транспорта
	this->pause_distance = 10; // - Время движения до отдыха

	this->pause_count = (distance / speed) / pause_distance; // - счетчик остановок
	this->pause_time = 5 + 6.5 + (pause_count - 2) * 8; // - Время отдыха

	this->travel_time = (distance / speed) + pause_time; // - общее время движения

}