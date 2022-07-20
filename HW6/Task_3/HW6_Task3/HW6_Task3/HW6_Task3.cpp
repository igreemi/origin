#include <iostream>
#include <windows.h>
#include <string>

#include "Figure.h"

#include "Triangle.h"
#include "Right_Triangle.h"
#include "Isosceles_Triangle.h"
#include "Equilateral_Triangle.h"

#include "Quadrilateral.h"
#include "Rectangl.h"
#include "Square.h"
#include "Parallelogram.h"
#include "Rhombus.h"


void print_info(Figure* figure) {

	std::cout << figure->figure_name() << std::endl;
	std::cout << "Стороны: " << figure->get_side() << std::endl;
	std::cout << "Углы: " << figure->get_angle() << std::endl;

}
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);

	Triangle triangle(60, 50, 70, 10, 20, 30);
	Right_Triangle right_triangle(10, 20, 30, 40, 50);
	Isosceles_Triangle iso_triangle(20, 40, 50, 60);
	Equilateral_Triangle eq_triangle(50);

	print_info(&triangle);
	std::cout << std::endl;

	print_info(&right_triangle);
	std::cout << std::endl;

	print_info(&iso_triangle);
	std::cout << std::endl;

	print_info(&eq_triangle);
	std::cout << std::endl;

	//----------------------------------------
	Quadrilateral quadrilateral(60, 50, 60, 50, 90, 90, 90, 90);
	Rectangl rectangle(20, 40, 20, 40);
	Square square(10, 10, 10, 10);
	Parallelogram parallelogram(20, 30, 80, 100);
	Rhombus rhombus(60, 120, 60);

	print_info(&quadrilateral);
	std::cout << std::endl;

	print_info(&rectangle);
	std::cout << std::endl;

	print_info(&square);
	std::cout << std::endl;

	print_info(&parallelogram);
	std::cout << std::endl;

	print_info(&rhombus);
	std::cout << std::endl;



	return 0;
}
