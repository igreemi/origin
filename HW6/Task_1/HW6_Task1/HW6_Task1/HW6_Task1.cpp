#include <iostream>
#include "math_func.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	int a , b;
	int operation;

		std::cout << "Введите первое число: ";
		std::cin >> a;

		std::cout << "Введите второе число: ";
		std::cin >> b;

	std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
	std::cin >> operation;

	if (operation <= 5 && operation >= 1) {
		switch (operation)
		{
		case 1:
			std::cout << a << " плюс " << b << " = " << addition(a, b) << std::endl;
			break;

		case 2:
			std::cout << a << " минус " << b << " = " << subtraction(a, b) << std::endl;
			break;

		case 3:
			std::cout << a << " умножить на " << b << " = " << multiplication(a, b) << std::endl;
			break;

		case 4:
			std::cout << a << " разделить на " << b << " = " << division(a, b) << std::endl;
			break;

		case 5:
			std::cout << a << " в степени " << b << " = " << exponentiation(a, b) << std::endl;
			break;
		}
	}
	else {
		std::cout << "Не верный ввод!" << std::endl;
		return 1;
	}

	return 0;
}
