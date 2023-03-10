#pragma once
#include <iostream>
#include <string>
#include <pqxx/pqxx>

class client_base
{
private:

	pqxx::connection* connect_db = nullptr;

public:

	client_base();

	~client_base();

	client_base(const client_base&) = delete;

	void operator=(const client_base&) = delete;

	void connectDB(std::string host, std::string port, std::string name, std::string user, std::string pass);

	void createTables();

	//ћетод, позвол€ющий добавить нового клиента
	void addNewClient(const std::string& first_name, const std::string& last_name, const std::string& email);

	int getClientIdByEmail(const std::string& email);

	//ћетод, позвол€ющий добавить телефон дл€ существующего клиента
	void addPhoneToClient(int id_client, const std::string& phone);

	//ћетод, позвол€ющий изменить данные о клиенте
	void updateClient(int id, const std::string& first_name, std::string last_name, std::string email);

	//ћетод, позвол€ющий удалить телефон дл€ существующего клиента
	void deletePhoneToClient(int id_client, const std::string& phone);

	//ћетод, позвол€ющий удалить существующего клиента
	void deleteClient(int id_client);

	//ћетод, позвол€ющий найти клиента по его данным (имени, фамилии, email-у или телефону)
	void searchClient(const std::string& search_field);
};

