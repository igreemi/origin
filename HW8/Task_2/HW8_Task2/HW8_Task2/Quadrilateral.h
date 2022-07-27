#pragma once
#include "Figure.h"
class Quadrilateral :
	public Figure
{
protected:
	int d, D;
public:

	Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D, int side);

	Quadrilateral();

	std::string print() override;


};