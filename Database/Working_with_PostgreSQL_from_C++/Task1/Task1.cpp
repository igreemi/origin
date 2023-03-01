#include <iostream>
//#include <pqxx/pqxx>
#include <Windows.h>
#include "client_base.h"

int main()
{
	SetConsoleOutputCP(CP_UTF8);
//	  setlocale(LC_ALL, "Russian");

	try {
		client_base cb;

		std::string client_id;
		std::string first_name, last_name, email;

		pqxx::connection c(

			"host = localhost "
			"port = 5432 "
			"dbname = test "
			"user = postgres "
			"password = 123 "

		);

		pqxx::work tx{ c };

//			cb.createTables(tx);


		c.prepare("insert_client", "INSERT INTO Clients(first_name, last_name, email) VALUES($1, $2, $3)");
		c.prepare("insert_phone", "INSERT INTO Phones(id_client, phone) VALUES($1, $2)");
//			c.prepare("update_client", "UPDATE Clients SET first_name = '" + first_name + "', last_name = '" + last_name + "', email = '" + email + "' WHERE id = '" + client_id + "'");
//			cb.addNewClient(tx, "Bobik", "Kamushkin", "bbb@bbb.bb");

//			cb.addPhoneToClient(tx, cb.getClientIdByEmail(tx, "bbb@bbb.bb"), "+78880004444");

//			std::cout << "Enter ID Client: ";
//			std::cin >> client_id;
//			std::cout << "First Name: ";
//			std::cin >> first_name;
//			std::cout << "Last Name: ";
//			std::cin >> last_name;
//			std::cout << "email: ";
//			std::cin >> email;

//			c.prepare("update_client", "UPDATE Clients SET first_name = $1 WHERE id = $2");

//			cb.updateClient(tx, first_name, client_id);

//			c.prepare("delete_phone", "DELETE FROM Phones WHERE id_client = $1 AND phone = $2");

//			cb.deletePhoneToClient(tx, cb.getClientIdByEmail(tx, "aaa@aaa.aa"), "+70001112233");

//			c.prepare("delete_phones_client", "DELETE FROM Phones WHERE id_client = $1");
//			c.prepare("delete_client", "DELETE FROM Clients WHERE id = $1");

//			cb.deleteClient(tx, cb.getClientIdByEmail(tx, "aaa@aaa.aa"));

		std::string search;
		std::cout << "Enter First name or Last name or Email or Phone: ";
		std::cin >> search;

		c.prepare("search_client",
			"SELECT first_name, last_name, email, p.phone FROM clients c "
			"LEFT JOIN phones p  ON c.id = p.id_client "
			"WHERE first_name = $1 "
			"OR last_name = $1 "
			"OR email = $1 "
			"OR p.phone = $1");

		cb.searchClient(tx, search);


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
