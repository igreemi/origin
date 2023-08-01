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

void loadingPercent(int percent, std::string& loading)
{
	if (static_cast<int>(percent) >= 10 && static_cast<int>(percent) < 20)
	{
		loading = "[#---------]";
	}
	if (static_cast<int>(percent) >= 20 && static_cast<int>(percent) < 30)
	{
		loading = "[##--------]";
	}
	if (static_cast<int>(percent) >= 30 && static_cast<int>(percent) < 40)
	{
		loading = "[###-------]";
	}
	if (static_cast<int>(percent) >= 40 && static_cast<int>(percent) < 50)
	{
		loading = "[####------]";
	}
	if (static_cast<int>(percent) >= 50 && static_cast<int>(percent) < 60)
	{
		loading = "[#####-----]";
	}
	if (static_cast<int>(percent) >= 60 && static_cast<int>(percent) < 70)
	{
		loading = "[######----]";
	}
	if (static_cast<int>(percent) >= 70 && static_cast<int>(percent) < 80)
	{
		loading = "[#######---]";
	}
	if (static_cast<int>(percent) >= 80 && static_cast<int>(percent) < 90)
	{
		loading = "[########--]";
	}
	if (static_cast<int>(percent) >= 90 && static_cast<int>(percent) < 100)
	{
		loading = "[#########-]";
	}
	if (static_cast<int>(percent) >= 100)
	{
		loading = "[##########]";
	}
}

void ccc(int size, int thr_num)
{

	auto start = std::chrono::steady_clock::now();

	consol_parameter cp;

	std::stringstream ss;
	std::string loading = "[----------]";

	ss << "thread num: " << thr_num << " thread id: " << std::this_thread::get_id() << ' ' << std::endl;

	std::string str;
	str = ss.str();
	std::cout << str;

	for (int i = 0; i < size; ++i)
	{
		float percent = ((i + 1) * static_cast<float>(100)) / size;

		std::lock_guard<MySpin> lg(s);

		std::this_thread::sleep_for(std::chrono::milliseconds(200));

		cp.SetPosition(str.size(), thr_num);

		loadingPercent(percent, loading);

		std::cout << loading;

		cp.SetPosition(str.size() + loading.size() + 1, thr_num);

		std::cout << " " << static_cast<int>(percent) << "%";
	}

	auto end = std::chrono::steady_clock::now();

	std::chrono::duration<double> elapsed_seconds = end - start;

	std::cout << " time: " << elapsed_seconds.count() << "\t";

	std::cout << std::endl;

}

int main()
{

	setlocale(LC_ALL, "ru");

	std::vector<std::thread> thr;

	int number_of_threads = 8;
	int calculation_length = 35;

	for (int i = 0; i < number_of_threads; i++)
	{
		thr.push_back(std::thread(ccc, calculation_length, i));
	}

	for (auto& t : thr)
	{
		t.join();
	}

	std::cout << std::endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	//	std::system("pause");

	return 0;

}
