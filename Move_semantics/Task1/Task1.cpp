#include <iostream>
#include <vector>

template<typename T>
void move_vectors(std::vector<T>& v1, std::vector<T>& v2)
{
	std::vector<T> v = std::move(v1);
	v1 = std::move(v2);
	v2 = std::move(v);
}

int main()
{
	std::vector <std::string> one = { "test_string1", "test_string2" };
	std::vector <std::string> two;

	move_vectors(one, two);

	std::cout << "two: ";

	for (auto v : two)
	{
		std::cout << v << " ";
	}

	return 0;
}
