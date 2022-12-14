#include <iostream>
#include "my_vector.h"

int main()
{

	my_vector::vector<int> arr_v;

	arr_v.push_back(1);
	arr_v.push_back(3);
	arr_v.push_back(5);
	arr_v.push_back(2);
	arr_v.push_back(4);
	arr_v.push_back(6);

	arr_v.at(4) = 22;

	for (auto& i : arr_v)
	{
		std::cout << i << std::endl;
	}

	std::cout << std::endl;

	std::cout << "at(4): " << arr_v.at(4) << std::endl;

	std::cout << "size(): " << arr_v.size() << std::endl;

	std::cout << "capacity(): " << arr_v.capacity() << std::endl;

	my_vector::vector<int> arr_v2 = arr_v;

	arr_v2.push_back(99);
	arr_v2.push_back(88);
	arr_v2.push_back(77);

	arr_v2.at(6) = 123;

	std::cout << std::endl;

	for (auto& i : arr_v2)
	{
		std::cout << i << std::endl;
	}

	std::cout << std::endl;

	std::cout << "at(6): " << arr_v2.at(6) << std::endl;

	std::cout << "size(): " << arr_v2.size() << std::endl;

	std::cout << "capacity(): " << arr_v2.capacity() << std::endl;

	std::cout << std::endl;

	std::cout << "DOUBLE : " << std::endl;

	my_vector::vector<double> arr_v3;

	arr_v3.push_back(rand());
	arr_v3.push_back(rand());
	arr_v3.push_back(rand());
	arr_v3.push_back(rand());
	arr_v3.push_back(rand());
	arr_v3.push_back(rand());
	arr_v3.push_back(rand());
	arr_v3.push_back(rand());
	arr_v3.push_back(rand());

	for (auto& i : arr_v3)
	{
		std::cout << " | " << i << std::endl;
	}

	return 0;

}
