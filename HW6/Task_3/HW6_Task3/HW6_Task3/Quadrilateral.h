#pragma once
#include "Figure.h"
class Quadrilateral :
    public Figure
{
protected:
	int d, D;
public:

	Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D);

	Quadrilateral();

	std::string get_side() override;

	std::string get_angle() override;

};

