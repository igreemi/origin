#include <iostream>
#include <string>

class Figure {
protected:
	std::string figure = "Фигура";
	int sides_sum = 0;

	bool check_check = false;
public:
	Figure() {

	}

	virtual void print_info() {
		std::cout << figure + ": " << std::endl;
		if (check() == false) {
			std::cout << "Правильная" << std::endl;

		}
		else {
			std::cout << "Неправильная" << std::endl;

		}
		std::cout << "Количество сторон: " << sides_sum << std::endl;
	}

	virtual bool check() {
		
		if (sides_sum == 0)
		{
			return false;
		}
		else {
			return true;
		}
	}

};

//---------------------------------------------------------------------------------

class Triangle : public Figure {
protected:
	int a = 0, b = 0, c = 0, A = 0, B = 0, C = 0;
public:

	Triangle(int a, int b, int c, int A, int B, int C) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
		this->figure = "Треугольник";
		this->sides_sum = 3;
	}

	Triangle() {}

	 void print_info() override
	 {
		 
		 Figure::print_info();

		std::cout << "Стороны: a=" + std::to_string(a) + " " + "b=" + std::to_string(b) + " " + "c=" + std::to_string(c) << std::endl;

		std::cout << "Углы: A=" + std::to_string(A) + " " + "B=" + std::to_string(B) + " " + "C=" + std::to_string(C) << std::endl;
	}


	 virtual bool check() override {

		if (A + B + C == 180)
		{
			return false;
		}
		else {

			return true;
		}
	}

};

class Right_Triangle : public Triangle {

public:
	Right_Triangle(int a, int b, int c, int A, int B, int C) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
		this->figure = "Прямоугольный треугольник";
		this->sides_sum = 3;
	}

	bool check() override {

		if (Triangle::check() == false && C == 90)
		{
			return false;
		}
		else {
			return true;
		}
	}
};

class Isosceles_Triangle : public Triangle {

public:
	Isosceles_Triangle(int a, int b, int c, int A, int B, int C) {

		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
		this->figure = "Равнобедренный треугольник";
		this->sides_sum = 3;
	}

	bool check() override {

		if (Triangle::check() == false &&  A == C && a == c)
		{
			return false;
		}
		else {
			return true;
		}
	}

};

class Equilateral_Triangle : public Triangle {

public:
	Equilateral_Triangle(int a, int b, int c, int A, int B, int C) {

		this->a = a;
		this->b = a;
		this->c = a;
		this->A = A;
		this->B = B;
		this->C = C;
		this->figure = "Равносторонний треугольник";
		this->sides_sum = 3;
	}

	bool check() override {

		if (Triangle::check() == false &&  A == B && B == C && a == b && b == c)
		{
			return false;
		}
		else {
			return true;
		}
	}

};

//---------------------------------------------------------------------------------

class Quadrilateral : public Figure {
protected:
	int a = 0, b = 0, c = 0, A = 0, B = 0, C = 0, d = 0, D = 0;
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
		this->sides_sum = 4;
	}

	Quadrilateral() {
	}

	void print_info() override
	{
		Figure::print_info();

		std::cout << "Стороны: a=" + std::to_string(a) + " " + "b=" + std::to_string(b) + " " + "c=" + std::to_string(c) + " " + "d=" + std::to_string(d) << std::endl;

		std::cout << "Углы: A=" + std::to_string(A) + " " + "B=" + std::to_string(B) + " " + "C=" + std::to_string(C) + " " + "D=" + std::to_string(D) << std::endl;
	}

	virtual bool check() override {

		if (A + B + C + D == 360)
		{
			return false;
		}
		else {
			return true;
		}
	}

};

class Rectangle : public Quadrilateral {
public:
	Rectangle(int a, int b, int c, int d, int A, int B, int C, int D) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
		this->figure = "Прямоугольник";
		this->sides_sum = 4;
	}

	 bool check() override {

		if (Quadrilateral::check() == false && a == c && b == d && A == 90 && B == 90 && C == 90)
		{
			return false;
		}
		else {
			return true;
		}
	}
};

class Square : public Quadrilateral {
public:
	Square(int a, int b, int c, int d, int A, int B, int C, int D) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
		this->figure = "Квадрат";
		this->sides_sum = 4;
	}

	bool check() override {

		if (Quadrilateral::check() == false &&  a == b && b == c && c == d && A == 90 && B == 90 && C == 90 && D == 90)
		{
			return false;
		}
		else {
			return true;
		}
	}

};

class Parallelogram : public Quadrilateral {
public:
	Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
		this->figure = "Параллелограмм";
		this->sides_sum = 4;
	}

	bool check() override {

			if (Quadrilateral::check() == false &&  a == c && b == d && A == C && B == D)
			{
				return false;
			}
			else {
				return true;
			}
		}

};

class Rhombus : public Quadrilateral {
public:
	Rhombus(int a, int b, int c, int d, int A, int B, int C, int D) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
		this->figure = "Ромб";
		this->sides_sum = 4;
	}

	bool check() override {

		if (Quadrilateral::check() == false &&  a == b && b == c && c == d && A == C && B == D)
		{
			return false;
		}
		else {
			return true;
		}
		
	}

};

void print(Figure* figure) {

	figure->print_info();

}


int main()
{
	setlocale(LC_ALL, "Russian");

	Figure figure;

	print(&figure);
	std::cout << std::endl;

	Triangle triangle(10, 50, 70, 60, 60, 60);
	Right_Triangle right_triangle(10, 20, 30, 60, 40, 80);
	Isosceles_Triangle iso_triangle(10, 20, 10, 50, 60, 50);
	Equilateral_Triangle eq_triangle(30, 30, 30, 60, 60, 60);

	print(&triangle);
	std::cout << std::endl;

	print(&right_triangle);
	std::cout << std::endl;

	print(&iso_triangle);
	std::cout << std::endl;

	print(&eq_triangle);
	std::cout << std::endl;

	//---------------------------------------------------------

	Quadrilateral quad(10, 20, 30, 40, 50, 60, 70, 80);
	Rectangle rect(10, 20, 10, 20, 90, 90, 90, 90);
	Square square(20, 20, 20, 20, 90, 90, 90, 90);
	Parallelogram parall(20, 30, 20, 30, 30, 40, 30, 40);
	Rhombus rhomb(30, 30, 30, 30, 30, 40, 30, 40);

	print(&quad);
	std::cout << std::endl;

	print(&rect);
	std::cout << std::endl;

	print(&square);
	std::cout << std::endl;

	print(&parall);
	std::cout << std::endl;

	print(&rhomb);
	std::cout << std::endl;
}
