#include "Figure.h"

Figure::Figure(int a, int b, int c, int A, int B, int C, int side) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->A = A;
	this->B = B;
	this->C = C;
	figure = "Figure";
	side_num = side;

	if (side_num != 0) {
		throw FigureEx(figure + "(sides " + std::to_string(a) + ", "
			+ std::to_string(b) + ", " + std::to_string(c) + "; angles "
			+ std::to_string(A) + ", " + std::to_string(B) + ", " + std::to_string(C) + ")");
	}
}

Figure::Figure() {

}

std::string Figure::print() {
	return figure + "(sides " + std::to_string(a)+ ", " 
		+ std::to_string(b) + ", " + std::to_string(c) + "; angles " 
		+ std::to_string(A) + ", " + std::to_string(B) + ", " + std::to_string(C) + ")";
}

