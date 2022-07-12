#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

class address {
private:
	std::string sity;
	std::string street;
	int home_num = 0;
	int apart_num = 0;
public:

	std::string out_add() {
		return sity + ", " + street + ", " + std::to_string(home_num) + ", " + std::to_string(apart_num);
	}

	std::string sity_sort() {
	  return sity;
	}
	address(std::string sity, std::string street, int home, int apart) {
		this->sity = sity;
		this->street = street;
		this->home_num = home;
		this->apart_num = apart;
	}
	address() {

	}

};

void sort(address* arr, int size) { 
	bool swapped = false;
	do {
		swapped = false;
		for (int i = size - 1; i > 0; i--) {
			if (arr[i].sity_sort() < arr[i - 1].sity_sort()) {
				address temp = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = temp;
				swapped = true;
			}
		}
	} while (swapped);
	}
	
	
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

	address* arr = new address[size];

	for (int i = 0; i < size; i++) {
		fin >> sity;
		fin >> street;
		fin >> home_num;
		fin >> apart_num;
		arr[i] = address(sity, street, home_num, apart_num);
	}
	fin.close();

	//-------------------------ЗАПИСЬ----------------------------

	std::ofstream fout("out.txt");
	if (!fout.is_open()) {
		std::cout << "Не удалось открыть фаил!" << std::endl;
		return 1;
	}

	fout << size << std::endl;

	sort(arr, size);

	for (int i = 0; i < size; i++) {

		fout << arr[i].out_add() << std::endl;
	}
	fout.close();

	delete[] arr;

	return 0;
}
