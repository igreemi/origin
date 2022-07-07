#include <iostream>
#include <windows.h>

class Counter {
private:

	int count = 0;
	//--------------------------------------
public:
	int plus() {
		return count++;
	}

	int minus() {
		return count--;
	}

	int stat() {
		return count;
	}
	//--------------------------------------

	Counter(int num) {
		this->count = num;
	}

	Counter() {

	}

};


int main()
{

	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	int num = 0;
	std::string yes_no;
	std::string symbol;

	std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
	std::cin >> yes_no;

	if (yes_no == "да") {
        
		std::cout << "Введите начальное значение счётчика: ";
		std::cin >> num;

	}
	else

		if (yes_no == "нет") {
			num = 1;
		}
		else

			if (yes_no != "да" && yes_no != "нет") {

				std::cout << "Не верный ввод" << std::endl;
				return 1;

			}
	Counter X(num);
	do {
		std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
		std::cin >> symbol;

		if (symbol == "+") {
			X.plus();
		}
		if (symbol == "-") {
			X.minus();
		}
		if (symbol == "=") {
			std::cout << X.stat() << std::endl;
		}
		if (symbol == "x" || symbol == "х") {
			std::cout << "До свидания!" << std::endl;
			return false;
		}
	} while (true);

	return 0;

}
