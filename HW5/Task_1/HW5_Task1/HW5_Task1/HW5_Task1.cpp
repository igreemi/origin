#include <iostream>
#include <string>
class Figure {
private:
	int number_of_sides;
	std::string figure_name;
public:

	Figure(int num, std::string name) {
		number_of_sides = num;
		figure_name = name;
	}

	std::string get_figure_name() {
	return figure_name;
	}

	int get_num_of_sides() {
	return number_of_sides;
	}

};
//--------------------------------------------------------------
class Triangle: public Figure {
public:

	Triangle(int num, std::string name) : Figure(num, name) {

	}

};
//------------------------------------------------------------------
class Quadrangle : public Figure {
public:
	Quadrangle(int num, std::string name) : Figure(num, name) {

	}
};
//------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL, "Russian");

	std::cout << "Колличество сторон: " << std::endl;

	Figure figure(0, "Фигура");
	std::cout << figure.get_figure_name() << ": " << figure.get_num_of_sides() << std::endl;

	Triangle triangle(3, "Треугольник");
	std::cout << triangle.get_figure_name() << ": " << triangle.get_num_of_sides() << std::endl;

	Quadrangle quadrangle(4, "Четырехугольник");
	std::cout << quadrangle.get_figure_name() << ": " << quadrangle.get_num_of_sides() << std::endl;

	return 0;
}

