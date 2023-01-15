#include <iostream>
#include "my_u_ptr.h"
#include <memory>

int main()
{
	My::my_u_ptr<int> ptr = new int(111);

	My::my_u_ptr<double> ptr2 = new double(222);

	std::cout << "*ptr = " << *ptr << " - " << &ptr << std::endl;
	std::cout << "*ptr2 = " << *ptr2 << " - " << &ptr2 << std::endl;
	std::cout << std::endl;

	*ptr = 333;
	*ptr2 = 444;

	My::my_u_ptr<int> ptr3 = new int(666);

	*ptr = *ptr2;
	*ptr2 = *ptr3;

	std::cout << "*ptr = " << *ptr << " - " << & ptr << std::endl;
	std::cout << "*ptr2 = " << *ptr2 << " - " << &ptr2 << std::endl;
	std::cout << "*ptr3 = " << *ptr3 << " - " << &ptr3 << std::endl;

	return 0;
}
