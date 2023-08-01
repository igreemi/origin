#pragma once

#include <mutex>
#include <thread>

class Data
{
private:

	int dt;

	std::mutex mtx;

public:

	Data(int value) : dt(value) {}

	int getDt();

	void setDt(int value);

	std::mutex& getMtx();

};
