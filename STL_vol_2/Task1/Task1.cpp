#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>

std::vector<T> unique_vector(std::vector<T>& v)
{

	std::sort(v.begin(), v.end());

	auto last = std::unique(v.begin(), v.end());

	v.erase(last, v.end());

	return v;

}


int main()
{

	std::vector<int> v = { 1, 1, 2, 5, 6, 1, 2, 4 };

	std::cout << "IN: ";

	for (auto& i : v)
	{
		std::cout << i << " ";
	}

	std::cout << std::endl;

	unique_vector(v);

	std::cout << "OUT: ";

	for (auto& i : v)
	{
		std::cout << i << " ";
	}

}
/*
[IN] : 1 1 2 5 6 1 2 4
[OUT] : 1 2 4 5 6
*/