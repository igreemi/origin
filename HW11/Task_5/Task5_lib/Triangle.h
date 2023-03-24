#pragma once
#include "Figure.h"
 class Triangle :
	public Figure
{
public:

		Triangle(int a, int b, int c, int A, int B, int C);

		Triangle();

		std::string get_side() override;

		std::string get_angle() override;

};

