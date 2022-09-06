#include <iostream>
#include <Windows.h>
#include "Leaver.h"

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    Task3::Leaver leave;
    std::string name;
    std::cout << "¬ведите им€: ";
    std::cin >> name;
    std::cout << leave.leave(name) << std::endl;
    system("pause");
}