﻿#include <iostream>
#include <string>
#include <windows.h>
int function(std::string str, int forbidden_length) {

    if (str.length() == forbidden_length) {
        throw std::length_error( "Вы ввели слово ( " + str + " ) запретной длины ( " + std::to_string(forbidden_length) + " )! До свидания!");

    }
        return str.length();

}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    int forbidden_length;
    std::string str;
    int func_len;
    std::cout << "Введите запретную длинну: ";
    std::cin >> forbidden_length;

 try {
     do {
         std::cout << "Введите слово: ";
         std::cin >> str;

         func_len = function(str, forbidden_length);

         std::cout << "Длина слова \"" << str << "\" равна " << func_len << std::endl;
     } while (func_len != forbidden_length);
    }
    catch (std::length_error ex)
    {
        std::cout << ex.what() << std::endl;
        
    }

    return 0;
}