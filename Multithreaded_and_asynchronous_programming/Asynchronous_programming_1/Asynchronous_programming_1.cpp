#include <iostream>
#include <future>
#include <vector>
#include <thread>

int min_element(const std::vector<int> & vec, int i)
{
	int min_i = i;

	for (int j = i + 1; j < vec.size(); j++)
	{
		if (vec[j] < vec[min_i])
		{
			min_i = j;
		}
	}
	return min_i;
}

void selectionSort(std::vector<int>& vec)
{
	for (int i = 0; i < vec.size() - 1; i++)
	{
		std::promise<int> minProm;

		std::future<int> minFt = minProm.get_future();

		std::thread t([&vec, i, &minProm]() 
			{
		minProm.set_value(min_element(vec, i));
			});

		int min = minFt.get();

		t.join();

		std::swap(vec[i], vec[min]);
	}
}

int main()
{
	std::vector<int> vec = { 93, 5, 25, 7, 12, 45, 22, 90 };

	std::cout << "Source Vector: ";

	for (int i : vec) {
		std::cout << i << " ";
	}

	std::cout << std::endl;

	selectionSort(vec);

	std::cout << "Sorted vector: ";

	for (int i : vec) {
		std::cout << i << " ";
	}

	std::cout << std::endl;

	return 0;
}
