#include <iostream>
#include <variant>
#include <stdlib.h>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>

std::variant<int, std::string, std::vector<int>> get_variant() {

	std::variant<int, std::string, std::vector<int>> result;

	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;

}

auto Print = [](const std::variant<int, std::string, std::vector<int>>var)
{
	if (auto* pval = std::get_if<int>(&var))
	{
		std::cout << "Int: " << *pval * 2 << '\n';
	}
	else if (auto* pval = std::get_if<std::string>(&var))
	{
		std::cout << "String: " << *pval << '\n';
	}
	else if (auto* pval = std::get_if<std::vector<int>>(&var))
	{
		std::cout << "Vector: ";
		for (auto vec : *pval)
		{
			std::cout << vec << ' ';
		}
	}

};

int main()
{

	Print(get_variant());

	return 0;
}
