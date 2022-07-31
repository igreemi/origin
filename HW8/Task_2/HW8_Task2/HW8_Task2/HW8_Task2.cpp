#include <iostream>

#include "FigureEx.h"

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

	std::cout << figure->print() << " created." << std::endl;

}
int main()
{
	setlocale(LC_ALL, "Russian");

	try {
		Figure figure(0, 0, 0, 0, 0, 0, 0);

		print_info(&figure);
		std::cout << std::endl;

		Triangle triangle(60, 50, 70, 60, 60, 60, 3);
		Right_Triangle right_triangle(10, 20, 30, 80, 50, 90);
		Isosceles_Triangle iso_triangle(20, 10, 20, 60, 50, 60);
		Equilateral_Triangle eq_triangle(50, 50, 50, 60, 60, 60);


		print_info(&triangle);
		std::cout << std::endl;

		print_info(&right_triangle);
		std::cout << std::endl;

		print_info(&iso_triangle);
		std::cout << std::endl;

		print_info(&eq_triangle);
		std::cout << std::endl;

		//----------------------------------------
		Quadrilateral quadrilateral(60, 50, 60, 50, 90, 90, 90, 90, 4);
		Rectangl rectangle(20, 40, 20, 40, 90, 90, 90, 90);
		Square square(10, 10, 10, 10, 90, 90, 90, 90);
		Parallelogram parallelogram(20, 30, 20, 30, 50, 60, 50, 60);
		Rhombus rhombus(60, 60, 60, 60, 70, 80, 70, 80);

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

	}
	catch (FigureEx& ex)
	{
		std::cout << ex.what() << " not created." << std::endl;
	}

	return 0;
}