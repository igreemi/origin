#include <iostream>
#include <chrono>
#include <thread>

void Client(int& count_clients, int count)
{

	for (int i = 0; i < count; i++)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		count_clients += 1;
		std::cout << "client came | queue: " << count_clients << std::endl;
	}

}

void Operationist(int& count_clients, int count)
{

	for (int i = 0; i < count; i++)
	{
		std::this_thread::sleep_for(std::chrono::seconds(2));
		count_clients -= 1;
		std::cout << "the client was served | queue: " << count_clients << std::endl;
	}

}


int main()
{

	int count_clients = 0;
	int count_clients_max = 10;

	std::thread t1(Client, std::ref(count_clients), count_clients_max);
	std::thread t2(Operationist, std::ref(count_clients), count_clients_max);

	t1.join();
	t2.join();

	return 0;

}