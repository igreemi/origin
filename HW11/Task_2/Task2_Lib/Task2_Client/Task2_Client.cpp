#include <iostream>
#include <Windows.h>
#include <Leaver.h>

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    Task2::Leaver leave;
    std::string name;
    std::cout << "Введите имя: ";
    std::cin >> name;
    std::cout << leave.leave(name) << std::endl;
    system("pause");
}
