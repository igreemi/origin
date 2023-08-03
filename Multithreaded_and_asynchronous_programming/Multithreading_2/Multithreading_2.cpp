#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

typedef std::vector <int> ivec;

void sum_vec(size_t start, size_t end, const ivec& v1, const ivec& v2, ivec& res)
{

	for (int i = start; i < end; i++) {
		res[i] = v1[i] + v2[i];
	}

}

/*
void parallel_sum_vec2(const ivec& v1, const ivec& v2, ivec res)
{

	std::vector<std::thread> thr;

	for (int i = 0; i < 2; i++)
	{
		thr.push_back(std::thread(sum_vec, i, v1.size() / 2, cref(v1), cref(v2), ref(res)));
	}
	for (auto& t : thr)
	{
		t.join();
	}


//	std::thread t1(sum_vec, (size_t)0, v1.size() / 2, cref(v1), cref(v2), ref(res));

//	std::thread t2(sum_vec, v1.size() / 2, v1.size(), cref(v1), cref(v2), ref(res));

//	t1.join();

//	t2.join();

}

*/

void parallel_sum_vec(const ivec& v1, const ivec& v2, ivec& res, int thr_v)
{

	int v_size = v1.size() / thr_v;

	std::vector<std::thread> thr;

	for (int i = 0; i < thr_v; i++)
	{

		if (i == 0)
		{
			thr.push_back(std::thread(sum_vec, i, v_size, std::ref(v1), std::ref(v2), std::ref(res)));
		}
		else if (i == 1)
		{
			thr.push_back(std::thread(sum_vec, v_size + i, v_size * (i + 1), std::ref(v1), std::ref(v2), std::ref(res)));
		}
		else if (i == (thr_v - 1))
		{
			thr.push_back(std::thread(sum_vec, v_size * i + 1, v1.size(), std::ref(v1), std::ref(v2), std::ref(res)));
		}
		else if (i > 1)
		{
			thr.push_back(std::thread(sum_vec, v_size * i + 1, v_size * (i + 1), std::ref(v1), std::ref(v2), std::ref(res)));
		}

	}

	for (auto& t : thr)
	{
		t.join();
	}

}

/*
void parallel_sum_vec8(const ivec& v1, const ivec& v2, ivec& res)
{

	int v_size = v1.size() / 8;

	std::thread t1(sum_vec, (size_t)0, v_size, cref(v1), cref(v2), ref(res));

	std::thread t2(sum_vec, (v_size + 1), (v_size * 2), cref(v1), cref(v2), ref(res));

	std::thread t3(sum_vec, (v_size * 2 + 1), (v_size * 3), cref(v1), cref(v2), ref(res));

	std::thread t4(sum_vec, (v_size * 3 + 1), (v_size * 4), cref(v1), cref(v2), ref(res));

	std::thread t5(sum_vec, (v_size * 4 + 1), (v_size * 5), cref(v1), cref(v2), ref(res));

	std::thread t6(sum_vec, (v_size * 5 + 1), (v_size * 6), cref(v1), cref(v2), ref(res));

	std::thread t7(sum_vec, (v_size * 6 + 1), (v_size * 7), cref(v1), cref(v2), ref(res));

	std::thread t8(sum_vec, (v_size * 7 + 1), v1.size(), cref(v1), cref(v2), ref(res));

	t1.join();

	t2.join();

	t3.join();

	t4.join();

	t5.join();

	t6.join();

	t7.join();

	t8.join();

}

void parallel_sum_vec16(const ivec& v1, const ivec& v2, ivec& res)
{

	int v_size = v1.size() / 16;

	std::thread t1(sum_vec, (size_t)0, v_size, cref(v1), cref(v2), ref(res));

	std::thread t2(sum_vec, (v_size + 1), (v_size * 2), cref(v1), cref(v2), ref(res));

	std::thread t3(sum_vec, (v_size * 2 + 1), (v_size * 3), cref(v1), cref(v2), ref(res));

	std::thread t4(sum_vec, (v_size * 3 + 1), (v_size * 4), cref(v1), cref(v2), ref(res));

	std::thread t5(sum_vec, (v_size * 4 + 1), (v_size * 5), cref(v1), cref(v2), ref(res));

	std::thread t6(sum_vec, (v_size * 5 + 1), (v_size * 6), cref(v1), cref(v2), ref(res));

	std::thread t7(sum_vec, (v_size * 6 + 1), (v_size * 7), cref(v1), cref(v2), ref(res));

	std::thread t8(sum_vec, (v_size * 7 + 1), (v_size * 8), cref(v1), cref(v2), ref(res));

	std::thread t9(sum_vec, (v_size * 8 + 1), (v_size * 9), cref(v1), cref(v2), ref(res));

	std::thread t10(sum_vec, (v_size * 9 + 1), (v_size * 10), cref(v1), cref(v2), ref(res));

	std::thread t11(sum_vec, (v_size * 10 + 1), (v_size * 11), cref(v1), cref(v2), ref(res));

	std::thread t12(sum_vec, (v_size * 11 + 1), (v_size * 12), cref(v1), cref(v2), ref(res));

	std::thread t13(sum_vec, (v_size * 12 + 1), (v_size * 13), cref(v1), cref(v2), ref(res));

	std::thread t14(sum_vec, (v_size * 13 + 1), (v_size * 14), cref(v1), cref(v2), ref(res));

	std::thread t15(sum_vec, (v_size * 14 + 1), (v_size * 15), cref(v1), cref(v2), ref(res));

	std::thread t16(sum_vec, (v_size * 15 + 1), v1.size(), cref(v1), cref(v2), ref(res));

	t1.join();

	t2.join();

	t3.join();

	t4.join();

	t5.join();

	t6.join();

	t7.join();

	t8.join();

	t9.join();

	t10.join();

	t11.join();

	t12.join();

	t13.join();

	t14.join();

	t15.join();

	t16.join();

}
*/

int main()
{

	setlocale(LC_ALL, "ru");

	unsigned int thr = std::thread::hardware_concurrency();

	int n = 1000;

	std::cout << "\t Колличество аппаратных ядер - " << thr;

	std::cout << std::endl;

	std::cout << "           \t" << "1000 \t" << "\t" << "10000 \t" << "\t" << "100000 \t" << "\t" << "1000000 \t" << std::endl;

	std::cout << "1 потоков  \t";

	do
	{

		std::vector<int> v1(n, 1);
		std::vector<int> v2(n, 2);
		std::vector<int> res(n, 0);

		auto start = std::chrono::steady_clock::now();

		sum_vec((size_t)0, n, std::ref(v1), std::ref(v2), std::ref(res));

		auto end = std::chrono::steady_clock::now();

		std::chrono::duration<double> elapsed_seconds = end - start;

		std::cout << elapsed_seconds.count() << "\t";

		n *= 10;

	} while (n <= 1000000);

	std::cout << std::endl;

	std::cout << "2 потоков  \t";

	n = 1000;

	do
	{

		std::vector<int> v1(n, 1);
		std::vector<int> v2(n, 2);
		std::vector<int> res(n, 0);

		auto start2 = std::chrono::steady_clock::now();

		parallel_sum_vec(std::ref(v1), std::ref(v2), std::ref(res), 2);

		auto end2 = std::chrono::steady_clock::now();

		std::chrono::duration<double> elapsed_seconds2 = end2 - start2;

		std::cout << elapsed_seconds2.count() << "\t";

		n *= 10;

	} while (n <= 1000000);

	std::cout << std::endl;

	std::cout << "4 потоков  \t";

	n = 1000;

	do
	{

		std::vector<int> v1(n, 1);
		std::vector<int> v2(n, 2);
		std::vector<int> res(n, 0);

		auto start4 = std::chrono::steady_clock::now();

		parallel_sum_vec(std::ref(v1), std::ref(v2), std::ref(res), 4);

		auto end4 = std::chrono::steady_clock::now();

		std::chrono::duration<double> elapsed_seconds4 = end4 - start4;

		std::cout << elapsed_seconds4.count() << "\t";

		n *= 10;

	} while (n <= 1000000);

	std::cout << std::endl;

	std::cout << "8 потоков  \t";

	n = 1000;

	do
	{

		std::vector<int> v1(n, 1);
		std::vector<int> v2(n, 2);
		std::vector<int> res(n, 0);

		auto start8 = std::chrono::steady_clock::now();

		parallel_sum_vec(std::ref(v1), std::ref(v2), std::ref(res), 8);

		auto end8 = std::chrono::steady_clock::now();

		std::chrono::duration<double> elapsed_seconds8 = end8 - start8;

		std::cout << elapsed_seconds8.count() << "\t";

		n *= 10;

	} while (n <= 1000000);

	std::cout << std::endl;

	std::cout << "16 потоков  \t";

	n = 1000;

	do
	{

		std::vector<int> v1(n, 1);
		std::vector<int> v2(n, 2);
		std::vector<int> res(n, 0);

		auto start16 = std::chrono::steady_clock::now();

		parallel_sum_vec(std::ref(v1), std::ref(v2), std::ref(res), 16);

		auto end16 = std::chrono::steady_clock::now();

		std::chrono::duration<double> elapsed_seconds16 = end16 - start16;

		std::cout << elapsed_seconds16.count() << "\t";

		n *= 10;

	} while (n <= 1000000);

	std::cout << std::endl;

	return 0;

}
