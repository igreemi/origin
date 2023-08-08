#include <iostream>
#include <vector>
#include <thread>
#include <future>


template<typename It, typename Func>
void parallel_for_each(It begin, It end, Func function)
{
	auto curr_size = std::distance(begin, end);

	if (curr_size <= 25)
	{
		std::for_each(begin, end, function);
	}
	else
	{
		auto mid = begin;

		std::advance(mid, curr_size / 2);

		auto ft = std::async(std::launch::async, parallel_for_each<It, Func>, begin, mid, function);
		auto ft2 = std::async(std::launch::async, parallel_for_each<It, Func>, mid, end, function);

		ft.get();
		ft2.get();
	}
}

void sum(int& i)
{
	i += i;

	std::cout << "id " << std::this_thread::get_id() << " | " << i << " | ";
}

int main()
{
	std::vector<int> vec(50, 2);

	for (auto i : vec)
	{
		std::cout << i << " ";
	}

	std::cout << std::endl;
	std::cout << std::endl;

	parallel_for_each(vec.begin(), vec.end(), sum);

	std::cout << std::endl;
	std::cout << std::endl;

	for (auto i : vec)
	{
		std::cout << i << " ";
	}

	std::cout << std::endl;

	return 0;
}
