#include <iostream>
#include <memory>
#include <Windows.h>
#include "client_base.h"

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	//	setlocale(LC_ALL, "Russian");

	try {

		std::string host = "localhost";
		std::string port = "5432";
		std::string nameDb = "test";
		std::string user = "postgres";
		std::string pass = "123";

		std::unique_ptr<client_base> cb(new client_base());

		cb->connectDB(host, port, nameDb, user, pass);

		cb->createTables();

		char menu = '0';

		while (menu != '7')
		{
			std::string first_name, last_name, email, phone, search;

			int id;

			menu = 0;

			std::cout << "----------------MENU----------------" << std::endl;
			std::cout << " 1) Create a new client " << std::endl;
			std::cout << " 2) Add client phone " << std::endl;
			std::cout << " 3) Update customer details " << std::endl;
			std::cout << " 4) Delete customer phone " << std::endl;
			std::cout << " 5) Delete client " << std::endl;
			std::cout << " 6) Client Search " << std::endl;
			std::cout << " 7) Exit " << std::endl;

			std::cout << " Enter menu number: ";

			std::cin >> menu;

			if (menu > '0' && menu < '8')
			{
				switch (menu)
				{
				case '1':

					std::cout << "Enter First Name: ";
					std::cin >> first_name;

					std::cout << "Enter Last Name: ";
					std::cin >> last_name;

					std::cout << "Enter Email: ";
					std::cin >> email;

					cb->addNewClient(first_name, last_name, email);

					break;
				case '2':

					std::cout << " Enter customer email: ";
					std::cin >> email;

					id = cb->getClientIdByEmail(email);

					if (id > 0)
					{
						std::cout << " Enter a new customer number: ";
						std::cin >> phone;

						cb->addPhoneToClient(id, phone);
					}
					break;

				case '3':

					std::cout << " Enter customer email: ";
					std::cin >> email;

					id = cb->getClientIdByEmail(email);

					if (id > 0)
					{
						std::cout << "Enter new first name: ";
						std::cin >> first_name;

						std::cout << "Enter new last name: ";
						std::cin >> last_name;

						std::cout << "Enter new email: ";
						std::cin >> email;

						cb->updateClient(id, first_name, last_name, email);
					}
					break;

				case '4':

					std::cout << " Enter customer email: ";
					std::cin >> email;

					id = cb->getClientIdByEmail(email);

					if (id > 0)
					{
						std::cout << " Delete customer phone: ";
						std::cin >> phone;

						cb->deletePhoneToClient(id, phone);
					}
					break;

				case '5':

					std::cout << " Enter customer email: ";
					std::cin >> email;

					id = cb->getClientIdByEmail(email);

					if (id > 0)
					{
						cb->deleteClient(id);
					}
					break;

				case '6':

					std::cout << " Enter the client's first name, last name, email or phone: " << std::endl;
					std::cin >> search;

					cb->searchClient(search);

					break;

				default:

					break;
				}
				system("pause");
			}
			system("cls");
		}
	}
	catch (pqxx::sql_error e)
	{
		std::cout << "SQL error: " << e.what() << std::endl;
	}
	catch (const std::exception ex)
	{
		std::cout << "General error: " << ex.what() << std::endl;
	}

	return 0;
}
