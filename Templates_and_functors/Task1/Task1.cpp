#include <iostream>
#include <vector>

template <typename T>
T my_max(T a)
{
	return a * a;
}

template <typename U >
std::vector<U> my_max(std::vector<U>& a)
{

	for (auto& i : a)
	{
		i *= i;
	}
	return a;
}

int main()
{
	int a = 4;
	std::cout << "IN: " << a << std::endl;
	std::cout << "OUT: " << my_max(4) << std::endl;

	std::vector<int> vec{ -1, 4, 8 };

	std::cout << "IN: ";
	for (auto i = 0; i < vec.size(); i++)
	{
		if (i != 0 && i < vec.size())
		{
			std::cout << ", ";
		}
		std::cout << vec[i];
	}
	std::cout << std::endl;

	my_max(vec);

	std::cout << "OUT: ";
	for (auto i = 0; i < vec.size(); i++)
	{
		if (i != 0 && i < vec.size())
		{
			std::cout << ", ";
		}
		std::cout << vec[i];
	}
	std::cout << std::endl;

	return 0;
}
