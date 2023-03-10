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

	//�����, ����������� �������� ������ �������
	void addNewClient(const std::string& first_name, const std::string& last_name, const std::string& email);

	int getClientIdByEmail(const std::string& email);

	//�����, ����������� �������� ������� ��� ������������� �������
	void addPhoneToClient(int id_client, const std::string& phone);

	//�����, ����������� �������� ������ � �������
	void updateClient(int id, const std::string& first_name, std::string last_name, std::string email);

	//�����, ����������� ������� ������� ��� ������������� �������
	void deletePhoneToClient(int id_client, const std::string& phone);

	//�����, ����������� ������� ������������� �������
	void deleteClient(int id_client);

	//�����, ����������� ����� ������� �� ��� ������ (�����, �������, email-� ��� ��������)
	void searchClient(const std::string& search_field);
};

