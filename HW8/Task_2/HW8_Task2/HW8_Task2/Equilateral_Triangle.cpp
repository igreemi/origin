#include "Equilateral_Triangle.h"


Equilateral_Triangle::Equilateral_Triangle(int a, int b, int c, int A, int B, int C) {

	this->a = a;
	this->b = b;
	this->c = c;
	this->A = A;
	this->B = B;
	this->C = C;
	this->figure = "Equilateral Triangle";

	if (A != B || B != C || a != b || b != c) {
		throw FigureEx(figure + "(sides " + std::to_string(a) + ", "
			+ std::to_string(b) + ", " + std::to_string(c) + "; angles "
			+ std::to_string(A) + ", " + std::to_string(B) + ", " + std::to_string(C) + ")");
	}
}