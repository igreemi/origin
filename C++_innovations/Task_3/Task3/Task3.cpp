#include <iostream>
#include <functional>
#include <cmath>

void Sin(double s)
{
	std::cout << " sin: " << sin(s);
}

void Cos(double c)
{
	std::cout << " cos: " << cos(c);
}

void Tan(double t)
{
	std::cout << " tan: " << tan(t);
}


int main()
{

	std::vector<double> angles = { 30 * 3.1415926 / 180, 60 * 3.1415926 / 180, 90 * 3.1415926 / 180 };


	std::vector<std::function<void(double)>> functions = { Sin, Cos, Tan };


	for (const auto& angle : angles) {
		std::cout << angle << ": ";
		for (const auto& function : functions)
			function(angle);
		std::cout << std::endl;
	}
	return 0;
}
