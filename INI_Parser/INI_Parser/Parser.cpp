#include <iostream>
#include <string>

#include "ini_parser.h"

int main()
{
	setlocale(0, "");

	try 
	{
		ini_parser parser("config.ini");
		auto value = parser.get_value<float>("Section1.Mode1");

		std::cout << "value = " << value << std::endl;
	}
	catch (const std::exception& e) 
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
