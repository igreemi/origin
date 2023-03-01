#pragma once
#include <iostream>
#include <string>
#include <pqxx/pqxx>

class client_base
{
private:

public:

	void createTables(pqxx::transaction_base& tx)
	{
		tx.exec("CREATE TABLE IF NOT EXISTS Clients(id SERIAL PRIMARY KEY, first_name VARCHAR(255) NOT NULL, last_name VARCHAR(255) NOT NULL, email VARCHAR(255) NOT NULL); ");
		tx.exec("CREATE TABLE IF NOT EXISTS Phones(id SERIAL PRIMARY KEY, id_client SERIAL REFERENCES Clients(id), phone VARCHAR(255) NOT NULL); ");

		tx.commit();
	}

	//ћетод, позвол€ющий добавить нового клиента
	void addNewClient(pqxx::transaction_base& tx, const std::string& first_name, const std::string& last_name, const std::string& email)
	{
		tx.exec_prepared("insert_client", first_name, last_name, email);
		tx.commit();
	}

	int getClientIdByEmail(pqxx::transaction_base& tx, const std::string& email)
	{
		int id = tx.query_value<int>("SELECT id FROM Clients WHERE email = '" + tx.esc(email) + "'");
		return id;
	}

	//ћетод, позвол€ющий добавить телефон дл€ существующего клиента
	void addPhoneToClient(pqxx::transaction_base& tx, int id_client, const std::string& phone)
	{
		tx.exec_prepared("insert_phone", id_client, phone);
		tx.commit();
	}

	//ћетод, позвол€ющий изменить данные о клиенте
	void updateClient(pqxx::transaction_base& tx, const std::string& field, int id)
	{
		tx.exec_prepared("update_client", field, id);
		tx.commit();
	}

	//ћетод, позвол€ющий удалить телефон дл€ существующего клиента
	void deletePhoneToClient(pqxx::transaction_base& tx, int id_client, const std::string& phone)
	{
		tx.exec_prepared("delete_phone", id_client, phone);
		tx.commit();

	}

	//ћетод, позвол€ющий удалить существующего клиента
	void deleteClient(pqxx::transaction_base& tx, int id_client)
	{
		tx.exec_prepared("delete_phones_client", id_client);
		tx.exec_prepared("delete_client", id_client);
		tx.commit();
	}

	//ћетод, позвол€ющий найти клиента по его данным (имени, фамилии, email-у или телефону)
	void searchClient(pqxx::transaction_base& tx, const std::string& search_field)
	{
		tx.exec_prepared("search_client", search_field);

				for (auto &[first_name, last_name, email, phone] : tx.stream<std::string, std::string, std::string, std::string>(
					"SELECT first_name, last_name, email, p.phone FROM clients c "
					"LEFT JOIN phones p  ON c.id = p.id_client "))
				{
					std::cout << first_name << " | " << last_name << " | " << email << " | " << phone << std::endl;
				}
	}

};

