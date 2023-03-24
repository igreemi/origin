#pragma once
#include "Figure.h"
 class Quadrilateral :
	public Figure
{
protected:
	int d, D;
public:

	TASK4LIB_EXPORTS_API	Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D);

	TASK4LIB_EXPORTS_API	Quadrilateral();

	TASK4LIB_EXPORTS_API	std::string get_side() override;

	TASK4LIB_EXPORTS_API	std::string get_angle() override;

};

