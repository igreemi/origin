#include <iostream>
#include "Data.h"

void lockSwap(Data& dt1, Data& dt2)
{

	std::lock(dt1.getMtx(), dt2.getMtx());

	int temp = dt1.getDt();
	dt1.setDt(dt2.getDt());
	dt2.setDt(temp);

	dt1.getMtx().unlock();
	dt2.getMtx().unlock();

}

void scoped_lockSwap(Data& dt1, Data& dt2)
{

	std::scoped_lock(dt1.getMtx(), dt2.getMtx());

	int temp = dt1.getDt();
	dt1.setDt(dt2.getDt());
	dt2.setDt(temp);

}

void unique_lockSwap(Data& dt1, Data& dt2)
{

	std::unique_lock<std::mutex> m1(dt1.getMtx());
	std::unique_lock<std::mutex> m2(dt2.getMtx());

	int temp = dt1.getDt();
	dt1.setDt(dt2.getDt());
	dt2.setDt(temp);

	m1.unlock();
	m2.unlock();

}

int main()
{

	Data data1(111);

	Data data2(222);

	std::thread t1(lockSwap, std::ref(data1), std::ref(data2));
	t1.join();

	std::cout << "Locked" << std::endl;

	std::cout << "data1: " << data1.getDt() << " | data2: " << data2.getDt() << std::endl;

	std::cout << std::endl;

	std::thread t2(scoped_lockSwap, std::ref(data1), std::ref(data2));
	t2.join();

	std::cout << "Scoped Locked" << std::endl;

	std::cout << "data1: " << data1.getDt() << " | data2: " << data2.getDt() << std::endl;

	std::cout << std::endl;

	std::thread t3(unique_lockSwap, std::ref(data1), std::ref(data2));
	t3.join();

	std::cout << "Unique Locked" << std::endl;

	std::cout << "data1: " << data1.getDt() << " | data2: " << data2.getDt() << std::endl;

	std::cout << std::endl;

}

