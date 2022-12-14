#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

int main()
{

	std::string str = "Hello World!!";

	std::cout << "[IN] : ";

	std::cout << str << std::endl;

	std::vector<char> my_vec(str.begin(), str.end());

	std::cout << std::endl;

	std::unordered_map<char, int> counter;

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
