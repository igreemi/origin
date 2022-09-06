#pragma once
#include "Figure.h"
 class Triangle :
	public Figure
{
public:

	TASK4LIBEXPORTS_API	Triangle(int a, int b, int c, int A, int B, int C);

	TASK4LIBEXPORTS_API	Triangle();

	TASK4LIBEXPORTS_API	std::string get_side() override;

	TASK4LIBEXPORTS_API	std::string get_angle() override;

};

