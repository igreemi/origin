#include <iostream>
#include <Windows.h>

#define MODE 1

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);

#if MODE == 0

	std::cout << "Работаю в режиме тренировки.";

#elif MODE == 1

	std::cout << "Работаю в боевом режиме" << std::endl;

	int a, b;

	std::cout << "Введите число 1: ";
	std::cin >> a;

	std::cout << "Введите число 1: ";
	std::cin >> b;

#include "add_func.h"

	std::cout << "Результат сложения: " << add(a, b) << std::endl; 
#else 

	std::cout << "Не известный режим. Завершаем работу.";
	return 1;
#endif

	return 0;
}
