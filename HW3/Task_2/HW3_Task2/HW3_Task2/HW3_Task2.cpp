#include <iostream>
#include <windows.h>

class Counter {
private:
    int count = 0;
//--------------------------------------
public:
    int plus() {
     return   count++;
    }

    int minus() {
        return count--;
    }

    int stat() {
        return count;
    }
 //--------------------------------------

    Counter(int count) {
        this->count = count;
    }

    Counter() {
        count = 1;
    }
};


int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    int num;
    std::string yes_no;
    std::string symbol;

    Counter count; //переменная класса Counter

    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> yes_no;

    if (yes_no == "да") {
        
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> num; 
        count = num;
        Counter counter(count); // если в конструктор указывать сразу переменную num, то значение count не меняется

    } else

    if (yes_no == "нет") {

        Counter сounter;

    }
    else

    if (yes_no != "да" && yes_no != "нет") {

        std::cout << "Не верный ввод" << std::endl;
        return 1;

    }


    do {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> symbol;

        if (symbol == "+") {
            count.plus();
        }
        if (symbol == "-") {
            count.minus();
        }
        if (symbol == "=") {
            std::cout << count.stat() << std::endl;
        }
        if (symbol == "x" || symbol == "х") {
            std::cout << "До свидания!" << std::endl;
            return false;
        }
    } while (true);

    return 0;
}
