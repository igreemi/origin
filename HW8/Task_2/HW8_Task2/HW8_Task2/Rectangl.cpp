#include "Rectangl.h"


Rectangl::Rectangl(int a, int b, int c, int d, int A, int B, int C, int D) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	this->A = A;
	this->B = B;
	this->C = C;
	this->D = D;

	this->figure = "Rectangle";

	if (a != c || b != d || A != 90 || B != 90 || C != 90) {
		throw FigureEx(figure + "(sides " + std::to_string(a) + ", "
			+ std::to_string(b) + ", " + std::to_string(c) + ", " + std::to_string(d) + "; angles "
			+ std::to_string(A) + ", " + std::to_string(B) + ", " + std::to_string(C) + ", " + std::to_string(D) + ")");
	}
}