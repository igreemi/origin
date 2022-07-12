#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

class addres {
private:
	std::string sity;
	std::string street;
	int home_num = 0;
	int apart_num = 0;
public:

	std::string out_add() {
		return sity + ", " + street + ", " + std::to_string(home_num) + ", " + std::to_string(apart_num);
	}

	addres(std::string sity, std::string street, int home, int apart) {
		this->sity = sity;
		this->street = street;
		this->home_num = home;
		this->apart_num = apart;
	}
	addres() {

	}

};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);

	std::string sity;
	std::string street;
	int home_num = 0;
	int apart_num = 0;

	int size;
	//-----------------------ЧТЕНИЕ---------------------------
	std::ifstream fin("in.txt");
	if (!fin.is_open()) {
		std::cout << "Не удалось открыть фаил!" << std::endl;
		return 1;
	}

	fin >> size;

	addres* arr = new addres[size];

	for (int i = 0; i < size; i++) {
	fin >> sity;
	fin >> street;
	fin >> home_num;
	fin >> apart_num;
	arr[i] = addres(sity, street, home_num, apart_num);
	}
	fin.close();
	//-------------------------ЗАПИСЬ----------------------------

	std::ofstream fout("out.txt");
	if (!fout.is_open()) {
		std::cout << "Не удалось открыть фаил!" << std::endl;
		return 1;
	}

	fout << size << std::endl;

	for (int i = size - 1; i >= 0; i--) {

		fout << arr[i].out_add() << std::endl;
	}
	fout.close();

	delete[] arr;

	return 0;
}
