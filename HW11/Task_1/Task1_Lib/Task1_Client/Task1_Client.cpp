#include <iostream>
#include <Windows.h>
#include "Greeter.h"
int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    Task1_Lib::Greeter greet;
    std::string name;

    std::cout << "Введите имя: ";
    std::cin >> name;
    std::cout << "Здравствуйте, " << greet.greet(name) << "! " << std::endl;

    system("pause");

    return 0;
}
