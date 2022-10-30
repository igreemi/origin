#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    setlocale(LC_ALL, "Russian");

    std::vector<int> v = { 4, 7, 9, 14, 12 };

    std::cout << "Входные данные: ";
    std::for_each(v.begin(), v.end(), [](const int n) { std::cout << n << ' '; });
    std::cout << '\n';

    std::cout << "Выходные данные: ";
    std::for_each(v.begin(), v.end(), [](int n) { 
        if(n % 2 != 0)
        {
            n *= 3;
        }
        std::cout << n << ' '; 
        });

    return 0;
}
