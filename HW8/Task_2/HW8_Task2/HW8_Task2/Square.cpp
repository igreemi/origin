#include "Square.h"


Square::Square(int a, int b, int c, int d, int A, int B, int C, int D) : Rectangl(a, b, c, d, A, B, C, D) {
	this->figure = "Square";

	if (a != b || b != c || c != d || A != 90 || B != 90 || C != 90 || D != 90) {
		throw FigureEx(figure + "(sides " + std::to_string(a) + ", "
			+ std::to_string(b) + ", " + std::to_string(c) + ", " + std::to_string(d) + "; angles "
			+ std::to_string(A) + ", " + std::to_string(B) + ", " + std::to_string(C) + ", " + std::to_string(D) + ")");
	}
}