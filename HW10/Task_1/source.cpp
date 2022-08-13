#include <iostream>
#include "windows.h"
int main() {
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	std::string	name;
	std::cout << "Введите имя: ";
	std::cin >> name;
	std::cout << "Здравствуйте, " << name << " ! " << std::endl;

	system("pause");

	return 0;
}