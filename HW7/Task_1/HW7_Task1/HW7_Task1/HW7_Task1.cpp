#include <iostream>
#include <Windows.h>

#define MODE 1

#ifndef MODE
#error "Определите MODE.";
#endif

#if MODE == 1

int add(int a, int b) { return (a + b); }

#endif

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);

#if MODE == 1

	std::cout << "Работаю в боевом режиме" << std::endl;

	int a, b;

	std::cout << "Введите число 1: ";
	std::cin >> a;

	std::cout << "Введите число 2: ";
	std::cin >> b;

	std::cout << "Результат сложения: " << add(a, b) << std::endl;

#elif MODE == 0

	std::cout << "Работаю в режиме тренировки.";


#else 

	std::cout << "Не известный режим. Завершаем работу.";
	return 1;

#endif
	
	return 0;
}
