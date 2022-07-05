#include <iostream>

struct address {

	std::string city; 
	std::string street;
	int num_home;
	int num_appart;
	int index;

};

void print_address(address p) {
	std::cout << "Город: " << p.city << std::endl;
	std::cout << "Улица: " << p.street << std::endl;
	std::cout << "Номер дома: " << p.num_home << std::endl;
	std::cout << "Номер квартиры: " << p.num_appart << std::endl;
	std::cout << "Индекс: " << p.index << std::endl;

}

int main()
{
	setlocale(LC_ALL, "Russian");

	address p = { "Москва", "Арбат", 12, 8, 123456 };
	print_address(p);

	std::cout << std::endl;

	address dp = { "Ижевск", "Пушкина", 59, 143, 953769 };
	print_address(dp);

	return 0;
}
