#include <iostream>
#include "windows.h"
int main() {
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	std::string	name;
	std::cout << "������� ���: ";
	std::cin >> name;
	std::cout << "������������, " << name << " ! " << std::endl;

	system("pause");

	return 0;
}