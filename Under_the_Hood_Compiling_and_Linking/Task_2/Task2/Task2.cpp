#include <iostream>
//#include "linking_error.h"//указан не существующий фаил


void syntax_error(int a, int b)
{
	for (i = 0; i < b; i++)
	{
		std::cout << c = a + b << ;
	}
}// обьявить переменную i и c, в строке вывода убрать оператор << или дописать std::endl 


void semantic_error(int a, int b)
{
	for (unsigned int i = 10; i >= 0; --i)
	{

		std::cout << a + b << std::endl;
	}
}//заменить оператор >= на >, в противном случае цикл не завершится

class linking_error {
public:
	linking_error() {};
	int sum(int a, int b) {
		return a + b;
	}
}; //не определен конструктор

int main()
{
	std::cout << "Hello World!\n";

	semantic_error(3, 6);
	linking_error a;

}
