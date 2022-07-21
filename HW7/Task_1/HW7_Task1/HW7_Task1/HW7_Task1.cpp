#include <iostream>
#include <Windows.h>

#define MODE 1


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);

#ifndef MODE
#error "Определите MODE.";

#elif MODE == 0

	std::cout << "Работаю в режиме тренировки.";

#elif MODE == 1

	#define add( a, b) ((a) + (b))
	std::cout << "Работаю в боевом режиме" << std::endl;

	int a, b;

	std::cout << "Введите число 1: ";
	std::cin >> a;

	std::cout << "Введите число 2: ";
	std::cin >> b;

	std::cout << "Результат сложения: " << add(a, b) << std::endl; 
#else 

	std::cout << "Не известный режим. Завершаем работу.";
	return 1;
#endif

	return 0;
}
