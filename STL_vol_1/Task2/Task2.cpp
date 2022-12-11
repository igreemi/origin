#include <iostream>
#include <set>
#include <vector>

int main()
{
	std::cout << "[IN]: " << std::endl;
	int s;
	std::cin >> s;
	std::cout << std::endl;
	std::vector<int> arr(s);

	for (auto& elem : arr)
	{
		std::cin >> elem;
	}

	std::set<int> arrOut;

	for (auto& elem : arr)
	{
		arrOut.insert(elem);
	}

	std::set <int>::reverse_iterator it;

	std::cout << "[OUT]:" << std::endl;

	for (it = arrOut.rbegin(); it != arrOut.rend(); it++)
	{
		std::cout << *it << std::endl;
	}

	return 0;

}
