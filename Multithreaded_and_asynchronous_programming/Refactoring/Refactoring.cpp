#include <iostream>
#include"shape.h"
#include "transform.h"

int main()
{
    std::cout << "Hello World!\n";
    std::cout << std::endl;

    Shape sh(3, 10, 30, 30, 15);
    transform tr(sh);
    tr.shift(2, 3, 4);

    std::cout << sh.getType();
    return 0;
}