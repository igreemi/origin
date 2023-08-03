#include <iostream>
#include <chrono>
#include <vector>
#include <mutex>
#include <thread>
#include "consol_parameter.h"
#include <string>
#include <sstream>
#include <atomic>

class MySpin
{

private:

	std::atomic_flag flag = ATOMIC_FLAG_INIT;

public:

	void lock()
	{
		while (flag.test_and_set())
		{

		}
	}

	void unlock()
	{
		flag.clear();
	}

};

MySpin s;

void ccc(int calculation_length, int thr_num)
{

	auto start = std::chrono::steady_clock::now();

	consol_parameter cp;

	std::stringstream ss;

	ss << "thread num: " << thr_num << " thread id: " << std::this_thread::get_id() << "\t" << std::endl;

	std::string str;
	str = ss.str();
	std::cout << str;

	for (int i = 0; i < 10; ++i)
	{

		std::lock_guard<MySpin> lg(s);

		std::this_thread::sleep_for(std::chrono::milliseconds(20));

		cp.SetPosition(str.size() + i, thr_num);

		std::cout << "#";

		std::this_thread::sleep_for(std::chrono::milliseconds(calculation_length));

	}

	auto end = std::chrono::steady_clock::now();

	std::chrono::duration<double> elapsed_seconds = end - start;

	std::cout << " time: " << elapsed_seconds.count() << "\t";

	std::cout << std::endl;

}

int main()
{

	setlocale(LC_ALL, "ru");

	consol_parameter cp;

	std::vector<std::thread> thr;

	int number_of_threads = 8;
	int calculation_length = 25;

	for (int i = 0; i < number_of_threads; i++)
	{
		thr.push_back(std::thread(ccc, calculation_length, i));
	}

	for (auto& t : thr)
	{
		t.join();
	}

	cp.SetPosition(0, number_of_threads);

	//	std::system("pause");

	return 0;

}