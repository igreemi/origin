#include "Triangle.h"

Triangle::Triangle(int a, int b, int c, int A, int B, int C) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->A = A;
	this->B = B;
	this->C = C;
	this->figure = "Triangle";

}

Triangle::Triangle() {}

std::string Triangle::get_side()
{

	return "a=" + std::to_string(a) + " " + "b=" + std::to_string(b) + " " + "c=" + std::to_string(c);
}

std::string Triangle::get_angle()
{
	return "A=" + std::to_string(A) + " " + "B=" + std::to_string(B) + " " + "C=" + std::to_string(C);
}
