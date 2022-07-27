#include "Isosceles_Triangle.h"


Isosceles_Triangle::Isosceles_Triangle(int a, int b, int c, int A, int B, int C) {

	this->a = a;
	this->b = b;
	this->c = c;
	this->A = A;
	this->B = B;
	this->C = C;

	this->figure = "Isosceles Triangle ";

	if (a != c || A != C) {
		throw FigureEx(figure + "(sides " + std::to_string(a) + ", "
			+ std::to_string(b) + ", " + std::to_string(c) + "; angles "
			+ std::to_string(A) + ", " + std::to_string(B) + ", " + std::to_string(C) + ")");
	}

}