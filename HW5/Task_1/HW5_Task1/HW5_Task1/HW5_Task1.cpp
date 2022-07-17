#include <iostream>

class Figure {
private:
	int number_of_sides;
	std::string figure_name;
public:

	Figure(int num, std::string name) {
		number_of_sides = num;
		figure_name = name;
	}

	void get_figure_name() {
	std::cout << figure_name << ": ";
	}

	void get_num_of_sides() {
	std::cout << number_of_sides << std::endl;
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
	figure.get_figure_name();
	figure.get_num_of_sides();

	Triangle triangle(3, "Треугольник");
	triangle.get_figure_name();
	triangle.get_num_of_sides();

	Quadrangle quadrangle(4, "Четырехугольник");
	quadrangle.get_figure_name();
	quadrangle.get_num_of_sides();

	return 0;
}

