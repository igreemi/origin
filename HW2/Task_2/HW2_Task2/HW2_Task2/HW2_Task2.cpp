#include <iostream>
#include <windows.h>

struct check
{
    int acc_number;
    std::string first_name;
    double sum;
};


void new_sum(check* s) // указатель
{
    s->sum;

}


int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);

    check ch;


    std::cout << "Введите номер счета: ";
    std::cin >> ch.acc_number;

    std::cout << "Введите имя владельца: ";
    std::cin >> ch.first_name;

    std::cout << "Введите баланс: ";
    std::cin >> ch.sum;
    new_sum(&ch);

    std::cout << "Введите новый баланс: ";
    std::cin >> ch.sum;

    std::cout << "Ваш счет: " << ch.acc_number << ", " << ch.first_name << ", " << ch.sum << ". " << std::endl;



    return 0;
}


