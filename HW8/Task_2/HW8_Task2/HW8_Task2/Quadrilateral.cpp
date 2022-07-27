#include "Quadrilateral.h"

Quadrilateral::Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D, int side) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	this->A = A;
	this->B = B;
	this->C = C;
	this->D = D;
	figure = "Quadrilateral";
	side_num = side;

	if (side_num != 4 || (A)+(B)+(C)+(D) != 360) {
		throw FigureEx(figure + "(sides " + std::to_string(a) + ", "
			+ std::to_string(b) + ", " + std::to_string(c) + ", " + std::to_string(d) + "; angles "
			+ std::to_string(A) + ", " + std::to_string(B) + ", " + std::to_string(C) + ", " + std::to_string(D) + ")");
	}
}

Quadrilateral::Quadrilateral() {
}

std::string Quadrilateral::print() {
	return figure + "(sides " + std::to_string(a) + ", "
		+ std::to_string(b) + ", " + std::to_string(c) + ", " + std::to_string(d) + "; angles "
		+ std::to_string(A) + ", " + std::to_string(B) + ", " + std::to_string(C) + ", " + std::to_string(D) + ")";
}