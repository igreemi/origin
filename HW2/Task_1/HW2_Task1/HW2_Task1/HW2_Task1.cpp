#include <iostream>

enum class MONTH {
    January = 1,
    February = 2,
    March = 3,
    April = 4,
    May = 5,
    June = 6,
    July = 7,
    August = 8,
    September = 9,
    October = 10,
    November = 11,
    December = 12,
    close = 0
};


int main()
{
    setlocale(LC_ALL, "Russian");

    MONTH month;
    int num = 0; 

    do {
        std::cout << "Введите номер месяца: ";
        std::cin >> num;
        month = static_cast<MONTH>(num);
        switch (month)
        {
        case MONTH::close: std::cout << "До свидания" << std::endl; break;
        case MONTH::January: std::cout << "Январь" << std::endl; break;
        case MONTH::February: std::cout << "Февраль" << std::endl; break;
        case MONTH::March: std::cout << "Март" << std::endl; break;
        case MONTH::April: std::cout << "Апрель" << std::endl; break;
        case MONTH::May: std::cout << "Май" << std::endl; break;
        case MONTH::June: std::cout << "Июнь" << std::endl; break;
        case MONTH::July: std::cout << "Июль" << std::endl; break;
        case MONTH::August: std::cout << "Август" << std::endl; break;
        case MONTH::September: std::cout << "Сентябрь" << std::endl; break;
        case MONTH::October: std::cout << "Октябрь" << std::endl; break;
        case MONTH::November: std::cout << "Ноябрь" << std::endl; break;
        case MONTH::December: std::cout << "Декабрь" << std::endl; break;
        default: std::cout << "Неправильный номер!" << std::endl; break;
        }
    } while (num != 0);
 
    return 0;
}

