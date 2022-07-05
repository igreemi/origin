#include <iostream>

class Calculator {
    double num1;
    double num2;

    double add(double num1, double num2) {
        return num1 + num2;
    }
        double multiply(double num1, double num2) {
            return num1 * num2;
    }
        double subtract_1_2(double num1, double num2) {
            return num2 - num1;
        }
        double subtract_2_1(double num1, double num2) {
            return num1 - num2;
        }
        double divide_1_2(double num1, double num2) {
            return num1 / num2;
        }
        double divide_2_1(double num1, double num2) {
            return num2 / num1;
        }
        bool set_num1(double num1) {
            if (num1 != 0) {
                this->num1 = num1;
                return true;
            }
            return false;
        }
        bool set_num2(double num2) {
            if (num1 != 0) {
                this->num2 = num2;
                return true;
            }
            return false;
        }
};

int main()
{
    std::cout << "Hello World!\n";
}
