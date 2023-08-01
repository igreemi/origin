#include "Data.h"

int Data::getDt()
{
	return dt;
}

void Data::setDt(int value)
{
	dt = value;
}

std::mutex& Data::getMtx()
{
	return mtx;
}
