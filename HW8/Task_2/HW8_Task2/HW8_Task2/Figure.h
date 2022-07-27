#pragma once
#include <string>
#include "FigureEx.h"
class Figure {
protected:
	std::string figure;
	int a, b, c, A, B, C;
	int side_num = 1;
public:
	Figure(int a, int b, int c, int A, int B, int C, int side);
	Figure();

	virtual std::string print();

};