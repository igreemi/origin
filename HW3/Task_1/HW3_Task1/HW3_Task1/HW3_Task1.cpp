#include <iostream>

class Calculator {
private:
	double num1 = 0;
	double num2 = 0;
public:

	double add() {
		return num1 + num2;
	}
	double multiply() {
		return num1 * num2;
	}
	double subtract_1_2() {
		return num1 - num2;
	}
	double subtract_2_1() {
		return num2 - num1;
	}
	double divide_1_2() {
		return num1 / num2;
	}
	double divide_2_1() {
		return num2 / num1;
	}
	bool set_num1(double num1) {
		if (num1 != 0) {
			this->num1 = num1;
			return true;
		}

		return false;
	}
	bool set_num2(double num2) {
		if (num2 != 0) {
			this->num2 = num2;
			return true;
		}

		return false;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	Calculator calc;



	while (true) {
		double num1 = 0;
		double num2 = 0;
		bool accepted = false;
		do {
			std::cout << "Введите num1: ";
			std::cin >> num1;
			accepted = calc.set_num1(num1);
			if (!accepted) {
				std::cout << "Неверный ввод!" << std::endl;
			}

		} while (!accepted);


		do {
			std::cout << "Введите num2: ";
			std::cin >> num2;
			accepted = calc.set_num2(num2);
			if (!accepted) {
				std::cout << "Неверный ввод!" << std::endl;
			}

		} while (!accepted);

		std::cout << std::endl;
		std::cout << "num1 + num2 = " << calc.add() << std::endl;
		std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
		std::cout << "num2 - num1 = " << calc.subtract_1_2() << std::endl;
		std::cout << "num1 - num2 = " << calc.subtract_2_1() << std::endl;
		std::cout << "num1 / num2 = " << calc.divide_1_2() << std::endl;
		std::cout << "num2 / num1 = " << calc.divide_2_1() << std::endl;
		std::cout << std::endl;

	}
	return 0;
 }