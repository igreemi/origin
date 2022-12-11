#include <iostream>
#include <map>
#include <vector>


int main()
{

	std::vector<char> my_vec = { 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', '!' };

	std::cout << "[IN] : ";

	for (auto& elem : my_vec)
	{
		std::cout << elem;
	}

	std::cout << std::endl;

	std::map<char, int> counter;
	for (auto& elem : my_vec)
	{
		counter[elem]++;
	}

	std::multimap<int, char> reverseCount;
	for (auto& elem : counter)
	{
		reverseCount.emplace(elem.second, elem.first);
	}

	std::multimap<int, char>::reverse_iterator it = reverseCount.rbegin();

	std::cout << "[OUT] : " << std::endl;

	while (it != reverseCount.rend())
	{
		std::cout << it->first << ": " << it->second << std::endl;
		++it;
	}

	return 0;
}
