#include <iostream>
#include <string>

class Figure {
protected:
	std::string figure;
	int a = 0, b = 0, c = 0, A = 0, B = 0, C = 0;
public:
	Figure() {

	}

	std::string figure_name() {
		return figure + ": ";
	}

	virtual std::string get_side() {
		return "";
	}

	virtual std::string get_angle() {
		return "";
	}

};

//--------------------------------Triangle---------------------------
class Triangle: public Figure {

public:

	Triangle(int a, int b, int c, int A, int B, int C) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
		this->figure = "Треугольник";

	}

	Triangle() {}

	 std::string get_side() override
	{

		return "a=" + std::to_string(a) + " " + "b=" + std::to_string(b) + " " + "c=" + std::to_string(c);
	}

	 std::string get_angle() override
	{
		return "A=" + std::to_string(A) + " " + "B=" + std::to_string(B) + " " + "C=" + std::to_string(C);
	}

};

class Right_Triangle : public Triangle {

public:
	Right_Triangle(int a, int b, int c, int A, int B) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = 90;
		this->figure = "Прямоугольный треугольник";
	}
};

class Isosceles_Triangle : public Triangle {

public:
	Isosceles_Triangle(int c, int A, int B, int C) {

		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
		this->a = 60;
		this->b = 60;
		this->figure = "Равнобедренный треугольник";
	}
};

class Equilateral_Triangle : public Triangle {

public:
	Equilateral_Triangle(int a) {

		this->a = a;
		this->b = a;
		this->c = a;
		this->A = 60;
		this->B = 60;
		this->C = 60;
		this->figure = "Равносторонний треугольник";
	}
};

//---------------------------------Quadrilateral----------------------

class Quadrilateral : public Figure {
protected:
	int d = 0, D = 0;
public:

	Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
		figure = "Четырехугольник";

	}

	Quadrilateral() {
	}

	std::string get_side() override
	{
		return "a=" + std::to_string(a) + " " + "b=" + std::to_string(b) + " " + "c=" + std::to_string(c) + " " + "d=" + std::to_string(d);
	}

	std::string get_angle() override
	{
	
		return "A=" + std::to_string(A) + " " + "B=" + std::to_string(B) + " " + "C=" + std::to_string(C) + " " + "D=" + std::to_string(D);
	}

};

class Rectangle : public Quadrilateral {
public:
	Rectangle(int a, int b, int c, int d) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = 90;
		this->B = 90;
		this->C = 90;
		this->D = 90;

		this->figure = "Прямоугольник";
	}
};

class Square : public Rectangle {
public:
	Square(int a, int b, int c, int d) : Rectangle(a, b, c, d) {
		this->figure = "Квадрат";
	}
};

class Parallelogram : public Quadrilateral {
public:
	Parallelogram(int a, int b, int A, int B) {
		this->a = a;
		this->b = b;
		this->c = a;
		this->d = b;
		this->A = A;
		this->B = B;
		this->C = A;
		this->D = B;
		this->figure = "Параллелограмм";
	}

};

class Rhombus : public Quadrilateral {
public:
	Rhombus(int a, int A, int B) {
		this->a = a;
		this->b = a;
		this->c = a;
		this->d = a;
		this->A = A;
		this->B = B;
		this->C = A;
		this->D = B;
		this->figure = "Ромб";
	}
};


void print_info(Figure* figure) {

	std::cout << figure->figure_name() << std::endl;
	std::cout << "Стороны: " << figure->get_side() << std::endl;
	std::cout << "Углы: " << figure->get_angle() << std::endl;

}
int main()
{
	setlocale(LC_ALL, "Russian");

	Triangle triangle(60, 50, 70, 10, 20, 30);
	Right_Triangle right_triangle(10, 20, 30, 40, 50);
	Isosceles_Triangle iso_triangle(20, 40, 50,60);
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
	Rectangle rectangle(20, 40, 20, 40);
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
