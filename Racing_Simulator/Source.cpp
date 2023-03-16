#include <iostream>
#include <string>
#include "RS_Lib/vehicle.h"

#include "RS_Lib/ground_vehicle.h"
#include "RS_Lib/ground_vehicle/camel.h"
#include "RS_Lib/ground_vehicle/speed_camel.h"
#include "RS_Lib/ground_vehicle/centaur.h"
#include "RS_Lib/ground_vehicle/all_terrain_boots.h"

#include "RS_Lib/air_vehicle.h"
#include "RS_Lib/air_vehicle/magic_carpet.h"
#include "RS_Lib/air_vehicle/eagle.h"
#include "RS_Lib/air_vehicle/broom.h"

void quick_sort(Vehicle* arr, int size) {

	int left = 0;
	int right = size - 1;

	Vehicle mid = arr[size / 2];

	do {

		while (arr[left].TravelTime() < mid.TravelTime()) {
			left++;
		}

		while (arr[right].TravelTime() > mid.TravelTime()) {
			right--;
		}

		if (left <= right) {

			std::swap(arr[left], arr[right]);

			left++;
			right--;
		}
	} while (left <= right);

	if (right > 0) {

		quick_sort(arr, right + 1);
	}
	if (left < size) {

		quick_sort(&arr[left], size - left);
	}
}

bool Proverka(Vehicle* arr, int count, Vehicle name)
{
	for (int i = 0; i < count; i++) {
		if (arr[i].GetName() == name.GetName()) {
			return false;
		}
	}
	return true;
}

void PrintList(Vehicle* arr, int count) {
	int a = 1;
	for (int i = 0; i < count; ++i) {
		std::cout << a << ". \x1B[33m" << arr[i].GetName() << "\033[0m. " << "Время: " << arr[i].TravelTime() << std::endl;
		++a;
	}
}

int GameMod(int t)
{
	if (t == 1)
	{
		return 1;
	}
	else if (t == 2)
	{
		return 2;
	}
	else if (t == 3)
	{
		return 3;
	}
	return 0;
}

void ErrorFun(int num)
{
	if (num == 0)
	{
		std::cout << "\x1B[31m Не верно! \033[0m" << std::endl;
		std::cout << std::endl;
	}
	else
		if (num == 1)
		{
			std::cout << "\x1B[31m Не верный тип гонки! \033[0m" << std::endl;
			std::cout << std::endl;
		}
		else
			if (num == 2)
			{
				std::cout << "\x1B[31m Не верный тип транспорта! \033[0m" << std::endl;
				std::cout << std::endl;
			}
			else
				if (num == 3)
				{
					std::cout << "\x1B[31m Должно быть зарегистрированно хотя бы 2 транспортных средства! \033[0m" << std::endl;
					std::cout << std::endl;
				}
}

void NameDuplication(Vehicle& name)
{
	std::cout << "\x1B[33m" << name.GetName() << "\033[0m" << "\x1B[31m уже зарегестрирован!\033[0m" << std::endl;
}

void transportList()
{
	std::cout << "1.\x1B[36m Верблюд \033[0m" << std::endl;
	std::cout << "2.\x1B[36m Верблюд-быстроход \033[0m" << std::endl;
	std::cout << "3.\x1B[36m Кентавр \033[0m" << std::endl;
	std::cout << "4.\x1B[36m Ботинки-вездеходы \033[0m" << std::endl;
	std::cout << "5.\x1B[36m Ковер-самолет \033[0m" << std::endl;
	std::cout << "6.\x1B[36m Орел \033[0m" << std::endl;
	std::cout << "7.\x1B[36m Метла \033[0m" << std::endl;
	std::cout << "0.\x1B[36m Закончить регистрацию \033[0m" << std::endl;
}

void RaceType(int i, int tmp_i, int count, int distance, int race_type, Vehicle* arr)
{
	if (i > tmp_i && i != tmp_i)
	{

		std::cout << "\x1B[33m" << arr[i - 1].GetName() << "\033[0m" << "\x1B[32m успешно зарегистрирован! \033[0m" << std::endl;
	}
	if (race_type == 1)
	{
		std::cout << "\x1B[36m" << "Гонка для наземного транспорта!Расстояние: " << "\033[0m" << distance << std::endl;
	}
	else
		if (race_type == 2)
		{
			std::cout << "\x1B[36m" << "Гонка для воздушного транспорта! Расстояние: " << "\033[0m" << distance << std::endl;
		}
		else
			if (race_type == 3)
			{
				std::cout << "\x1B[36m" << "Гонка для наземного и воздушного транспорта! Расстояние: " << "\033[0m" << distance << std::endl;
			}

	if (count >= 1)
	{
		std::cout << "Зарегистрированные транспортные средства: ";

		for (int i = 0; i < count; i++)
		{
			if (i >= 1) { std::cout << ", "; }
			std::cout << "\x1B[33m" << arr[i].GetName() << "\033[0m";

		}
		std::cout << std::endl;
	}

}

int main()
{
	setlocale(LC_ALL, "Russian");

	bool restart = true;
	while (restart == true) {
		system("cls");
		std::cout << "\x1B[35m Добро пожаловать в гоночный симулятор! \033[0m" << std::endl;

		std::cout << "1.\x1B[32m Гонка для наземного транспорта \033[0m" << std::endl;
		std::cout << "2.\x1B[32m Гонка для воздушного транспорта \033[0m" << std::endl;
		std::cout << "3.\x1B[32m Гонка для наземного и воздушного транспорта \033[0m" << std::endl;


		int race_type = 0;

		while (race_type <= 0 || race_type > 3)
		{
			std::cout << "Выберите тип гонки: ";
			std::cin >> race_type;
			if (race_type > 0 && race_type <= 3) {
				GameMod(race_type);
			}
			else
			{
				ErrorFun(1);
			}
		}

		std::cout << std::endl;
		system("cls");

		int distance = 0;
		while (distance <= 0) {
			std::cout << "\x1B[36m" << "Укажите длину дистанции(должна быть положительна): " << "\033[0m";
			std::cin >> distance;
			std::cout << std::endl;
		}
		system("cls");

		Camel camel(distance);

		SpeedCamel speed_camel(distance);

		Centaur centaur(distance);

		AllTerrainBoots all_terrain_boots(distance);

		MagicCarpet magic_carpet(distance);

		Eagle eagle(distance);

		Broom broom(distance);

		std::cout << "Должно быть зарегистрированно хотя бы 2 транспортных средства" << std::endl;

		std::cout << std::endl;

		unsigned int size = 7;
		int count = 0;


		Vehicle* arr = new Vehicle[size]();

		int i = 0;
		int tmp_i = 0;
		int reg_start = 0;
		bool start_game = false;

		do
		{
			int end = 1;

			if (count <= 0) {
				std::cout << "1.\x1B[32m Зарегистрировать транспорт \033[0m" << std::endl;
			}
			else
			{
				std::cout << "1.\x1B[32m Зарегистрировать транспорт \033[0m" << std::endl;
				std::cout << "2.\x1B[32m Начать гонку \033[0m" << std::endl;
			}

			std::cout << "Выберите действие: ";
			std::cin >> reg_start;

			std::cout << std::endl;
			system("cls");
			if (reg_start != 1 && count <= 0)
			{
				std::cout << "Введите 1!" << std::endl;
			}
			else
				if (reg_start != 1 && reg_start != 2)
				{
					std::cout << "Введите 1 или 2!" << std::endl;
				}
				else
					if (reg_start == 1)
					{
						do {

							if (race_type == 1)
							{
								RaceType(i, tmp_i, count, distance, race_type, arr);
							}
							if (race_type == 2)
							{
								RaceType(i, tmp_i, count, distance, race_type, arr);
							}
							if (race_type == 3)
							{
								RaceType(i, tmp_i, count, distance, race_type, arr);
							}

							transportList();

							int num;
							std::cout << "Выберите транспорт или 0 для окончания регистрации: ";
							std::cin >> num;
							std::cout << std::endl;
							system("cls");
							if (num < 0 || num > 7) {
								ErrorFun(0);
							}
							else
							{
								switch (num)
								{
								case 1:
									if (Proverka(arr, count, camel) == true) {
										if (camel.TypeOfTransport() == GameMod(race_type) || GameMod(race_type) == 3)
										{
											arr[i] = camel;
											tmp_i = i;
											++i;
											++count;
										}
										else
										{
											ErrorFun(2);
											tmp_i = i;
										}

									}
									else {
										NameDuplication(camel);
										tmp_i = i;
									}
									break;
								case 2:
									if (Proverka(arr, count, speed_camel) == true) {
										if (speed_camel.TypeOfTransport() == GameMod(race_type) || GameMod(race_type) == 3)
										{
											arr[i] = speed_camel;
											tmp_i = i;
											++i;
											++count;
										}
										else
										{
											ErrorFun(2);
											tmp_i = i;
										}
									}
									else {
										NameDuplication(speed_camel);
										tmp_i = i;
									}

									break;
								case 3:
									if (Proverka(arr, count, centaur) == true) {
										if (centaur.TypeOfTransport() == GameMod(race_type) || GameMod(race_type) == 3)
										{
											arr[i] = centaur;
											tmp_i = i;
											++i;
											++count;
										}
										else
										{
											ErrorFun(2);
											tmp_i = i;
										}
									}
									else {
										NameDuplication(centaur);
										tmp_i = i;
									}

									break;
								case 4:
									if (Proverka(arr, count, all_terrain_boots) == true) {
										if (all_terrain_boots.TypeOfTransport() == GameMod(race_type) || GameMod(race_type) == 3)
										{
											arr[i] = all_terrain_boots;
											++i;
											++count;
										}
										else
										{
											ErrorFun(2);
											tmp_i = i;
										}
									}
									else {
										NameDuplication(all_terrain_boots);
										tmp_i = i;
									}

									break;
								case 5:
									if (Proverka(arr, count, magic_carpet) == true) {
										if (magic_carpet.TypeOfTransport() == GameMod(race_type) || GameMod(race_type) == 3)
										{
											arr[i] = magic_carpet;
											++i;
											++count;
										}
										else
										{
											ErrorFun(2);
											tmp_i = i;
										}
									}
									else {
										NameDuplication(magic_carpet);
										tmp_i = i;
									}

									break;
								case 6:
									if (Proverka(arr, count, eagle) == true) {
										if (eagle.TypeOfTransport() == GameMod(race_type) || GameMod(race_type) == 3)
										{
											arr[i] = eagle;
											++i;
											++count;
										}
										else
										{
											ErrorFun(2);
											tmp_i = i;
										}
									}
									else {
										NameDuplication(eagle);
										tmp_i = i;
									}

									break;
								case 7:
									if (Proverka(arr, count, broom) == true) {
										if (broom.TypeOfTransport() == GameMod(race_type) || GameMod(race_type) == 3)
										{
											arr[i] = broom;
											++i;
											++count;
										}
										else
										{
											ErrorFun(2);
											tmp_i = i;
										}
									}
									else {
										NameDuplication(broom);
										tmp_i = i;
									}

									break;
								case 0:
									if (count >= 2)
									{
										end = 0;
									}
									else
									{
										ErrorFun(3);
									}
									break;
								}
							}

						} while (end != 0);
					}
					else
						if (reg_start == 2 && count >= 2)
						{
							start_game = true;
						}
		} while (start_game == false);

		quick_sort(arr, count);

		PrintList(arr, count);

		delete[] arr;

		std::cout << std::endl;
		int res = 0;
		do
		{
			std::cout << "1. Провести еще одну гонку" << std::endl;
			std::cout << "2. Выйти" << std::endl;
			std::cout << "Выберите действие: ";
			std::cin >> res;
			if (res < 1 && res > 2)
			{
				ErrorFun(0);
			}
			else
				if (res == 1)
				{
					restart = true;
				}
				else
					if (res == 2)
					{
						restart = false;
					}
		} while (res != 1 && res != 2);

		system("cls");
	}

	return 0;
}