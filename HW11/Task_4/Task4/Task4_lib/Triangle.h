#pragma once
#include "Figure.h"
 class Triangle :
	public Figure
{
public:

	TASK4LIB_EXPORTS_API	Triangle(int a, int b, int c, int A, int B, int C);

	TASK4LIB_EXPORTS_API	Triangle();

	TASK4LIB_EXPORTS_API	std::string get_side() override;

	TASK4LIB_EXPORTS_API	std::string get_angle() override;

};

