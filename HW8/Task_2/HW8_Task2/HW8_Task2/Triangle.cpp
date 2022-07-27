#include "Triangle.h"

Triangle::Triangle(int a, int b, int c, int A, int B, int C, int side) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->A = A;
	this->B = B;
	this->C = C;
	figure = "Triangle";
	side_num = side;

	if (side_num != 3 || (A) + (B) + (C) != 180 ) {
		throw FigureEx(figure + "(sides " + std::to_string(a) + ", "
			+ std::to_string(b) + ", " + std::to_string(c) + "; angles "
			+ std::to_string(A) + ", " + std::to_string(B) + ", " + std::to_string(C) + ")");
	}

}

Triangle::Triangle() {}

std::string Triangle::print() {
	return figure + "(sides " + std::to_string(a) + ", "
		+ std::to_string(b) + ", " + std::to_string(c) + "; angles "
		+ std::to_string(A) + ", " + std::to_string(B) + ", " + std::to_string(C) + ")";
}