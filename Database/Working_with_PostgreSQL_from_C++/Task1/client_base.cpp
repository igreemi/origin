#include "client_base.h"

#pragma once
client_base::client_base() {}

client_base::~client_base()
{
	delete connect_db;
}

void client_base::connectDB(std::string host, std::string port, std::string name, std::string user, std::string pass)
{
	connect_db = new pqxx::connection
	("host = " + host +
		" port = " + port +
		" dbname = " + name +
		" user = " + user +
		" password = " + pass);

	if (connect_db->is_open())
	{
		std::cout << " Database connected! " << std::endl;
	}
	else
	{
		std::cout << " Database not connected! " << std::endl;
	}
}

void client_base::createTables()
{
	if (connect_db == nullptr)
	{
		std::cout << " Database not connected! " << std::endl;
	}
	else
	{
		pqxx::work tx(*connect_db);

		tx.exec("CREATE TABLE IF NOT EXISTS Clients(id SERIAL PRIMARY KEY, first_name VARCHAR(255) NOT NULL, last_name VARCHAR(255) NOT NULL, email VARCHAR(255) NOT NULL, CONSTRAINT email_unique UNIQUE (email)); ");

		tx.exec("CREATE TABLE IF NOT EXISTS Phones(id SERIAL PRIMARY KEY, id_client SERIAL REFERENCES Clients(id), phone VARCHAR(255) NOT NULL, CONSTRAINT phone_unique UNIQUE (phone)); ");

		tx.commit();

		std::cout << " The table of Clients and Phones has been created. " << std::endl;
		//---------------------------------------------
		connect_db->prepare("repeat_email",
			"SELECT email FROM Clients "
			"WHERE email = $1 "
		);

		connect_db->prepare("insert_client", 
			"INSERT INTO Clients(first_name, last_name, email) VALUES($1, $2, $3)"
		);

		connect_db->prepare("repeat_phone",
			"SELECT phone FROM Phones "
			"WHERE phone = $1 "
		);

		connect_db->prepare("update_client",
			"UPDATE Clients SET first_name = $2, last_name = $3, email = $4 WHERE id = $1"
		);

		connect_db->prepare("insert_phone", 
			"INSERT INTO Phones(id_client, phone) VALUES($1, $2)"
		);

		connect_db->prepare("delete_phone",
			"DELETE FROM Phones WHERE id_client = $1 AND phone = $2"
		);

		connect_db->prepare("delete_phones_client", 
			"DELETE FROM Phones WHERE id_client = $1"
		);

		connect_db->prepare("delete_client", 
			"DELETE FROM Clients WHERE id = $1"
		);

		connect_db->prepare("search_client",
			"SELECT first_name, last_name, email, p.phone FROM clients c "
			"LEFT JOIN phones p  ON c.id = p.id_client "
			"WHERE first_name = $1 "
			"OR last_name = $1 "
			"OR email = $1 "
			"OR p.phone = $1");

	}
}

void client_base::addNewClient(const std::string& first_name, const std::string& last_name, const std::string& email)
{
	if (connect_db == nullptr)
	{
		std::cout << " Database not connected! " << std::endl;
	}
	else
	{
		pqxx::work tx(*connect_db);

		pqxx::result res = tx.exec_prepared("repeat_email", email);

		if (res.size())
		{
			std::cout << "Email already exists." << std::endl;

			tx.commit();
		}
		else
		{
			tx.exec_prepared("insert_client", first_name, last_name, email);

			tx.commit();

			std::cout << " Client added. " << std::endl;
		}
	}
}

int client_base::getClientIdByEmail(const std::string& email)
{
	if (connect_db == nullptr)
	{
		std::cout << " Database not connected! " << std::endl;
	}
	else
	{
		pqxx::work tx(*connect_db);

		pqxx::result res = tx.exec_prepared("repeat_email", email);

		if (!res.size())
		{
			std::cout << " This email does not exist! " << std::endl;

			tx.commit();

			return -1;
		}
		else
		{
			int id = tx.query_value<int>("SELECT id FROM Clients WHERE email = '" + tx.esc(email) + "'");

			tx.commit();

			return id;
		}
	}
}

void client_base::addPhoneToClient(int id_client, const std::string& phone)
{
	if (connect_db == nullptr)
	{
		std::cout << " Database not connected! " << std::endl;
	}
	else
	{
		pqxx::work tx(*connect_db);

		pqxx::result res = tx.exec_prepared("repeat_phone", phone);

		if (res.size())
		{
			std::cout << " Such a phone exists! " << std::endl;

			tx.commit();
		}
		else
		{
			tx.exec_prepared("insert_phone", id_client, phone);

			tx.commit();

			std::cout << " Phone added. " << std::endl;
		}
	}
}

void client_base::updateClient(int id, const std::string& first_name, std::string last_name, std::string email)
{
	if (connect_db == nullptr)
	{
		std::cout << " Database not connected! " << std::endl;
	}
	else
	{
		pqxx::work tx(*connect_db);

		tx.exec_prepared("update_client", id, first_name, last_name, email);

		tx.commit();

		std::cout << " Client details updated. " << std::endl;
	}
}

void client_base::deletePhoneToClient(int id_client, const std::string& phone)
{
	if (connect_db == nullptr)
	{
		std::cout << " Database not connected! " << std::endl;
	}
	else
	{
		pqxx::work tx(*connect_db);

		pqxx::result res = tx.exec_prepared("repeat_phone", phone);

		if (!res.size())
		{
			std::cout << " There is no such phone! " << std::endl;

			tx.commit();
		}
		else
		{
			tx.exec_prepared("delete_phone", id_client, phone);

			tx.commit();

			std::cout << " Customer phone number removed. " << std::endl;
		}
	}
}

void client_base::deleteClient(int id_client)
{
	if (connect_db == nullptr)
	{
		std::cout << " Database not connected! " << std::endl;
	}
	else
	{
		pqxx::work tx(*connect_db);

		tx.exec_prepared("delete_phones_client", id_client);

		tx.exec_prepared("delete_client", id_client);

		tx.commit();

		std::cout << " Client removed. " << std::endl;
	}
}

void client_base::searchClient(const std::string& search_field)
{
	if (connect_db == nullptr)
	{
		std::cout << " Database not connected! " << std::endl;
	}
	else
	{
		pqxx::work tx(*connect_db);

		pqxx::result res = tx.exec_prepared("search_client", search_field);

		if (!res.size())
		{
			std::cout << "Client not found." << std::endl;
		}
		else
		{
			pqxx::result r = tx.exec(
				"SELECT first_name, last_name, email, p.phone FROM clients c "
				"LEFT JOIN phones p  ON p.id_client = c.id "
				"WHERE first_name = '" + search_field + "' "
				"OR last_name = '" + search_field + "' "
				"OR email = '" + search_field + "' "
				"OR p.phone = '" + search_field + "'");

			for (auto const& row : r)
			{
				for (auto const& field : row)
				{
					std::cout << " | " << field.c_str() << " ";
				}
				std::cout << std::endl;
			}
		}
	}
}



