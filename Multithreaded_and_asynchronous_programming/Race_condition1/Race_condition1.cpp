#include <iostream>
#include <chrono>
#include <thread>
#include <atomic>
#include <mutex>

void Client(std::atomic_int& count_clients, int& count)
{

	for (int i = 0; i < count; i++)
	{

		count_clients.store(count_clients += 1, std::memory_order_relaxed);

		std::cout << "client came | queue: " << count_clients.load(std::memory_order_relaxed) << std::endl;

	}

}

void Operationist(std::atomic_int& count_clients, int& count)
{

	for (int i = 0; i < count; i++)
	{

		count_clients.store(count_clients -= 1, std::memory_order_relaxed);

		std::cout << "the client was served | queue: " << count_clients.load(std::memory_order_relaxed) << std::endl;

	}

}


int main()
{

	std::atomic_int count_clients(0);

	int count_clients_max = 10;

	std::thread t1(Client, std::ref(count_clients), std::ref(count_clients_max));
	std::thread t2(Operationist, std::ref(count_clients), std::ref(count_clients_max));

	t1.join();
	t2.join();

	return 0;

}