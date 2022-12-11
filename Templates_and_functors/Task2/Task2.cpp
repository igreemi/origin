#include <iostream>

template<class T>
class table
{
private:
	int rows, cols;
	T** arr = nullptr;
public:

	T* operator[](int i) { return arr[i]; }

	table(int r, int c)
	{
		rows = r;
		cols = c;

		arr = new T * [rows];

		for (int i = 0; i < rows; i++)
		{
			arr[i] = new T[cols];
		}
	}

	table() {}

	table(const table& t)
	{
		cols = t.cols;
		rows = t.rows;

		arr = new T * [rows] {nullptr};

		for (int i = 0; i < rows; ++i)
		{
			arr[i] = new T[cols];
		}

		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < rows; ++j)
			{
				arr[i][j] = t.arr[i][j];
			}
		}

	}

	table& operator = (table const& t)
	{
		if (this != &t)
		{
			cols = t.cols;
			rows = t.rows;

			arr = new T * [rows] {nullptr};

			for (int i = 0; i < rows; ++i)
			{
				arr[i] = new T[cols];
			}

			for (int i = 0; i < rows; ++i)
			{
				for (int j = 0; j < rows; ++j)
				{
					arr[i][j] = t.arr[i][j];
				}
			}
		}
		return *this;
	}

	~table() {
		for (int i = 0; i < rows; ++i)
		{
			delete[] arr[i];
		}
		delete[] arr;
	}

};


int main()
{
	auto test = table<int>(2, 3);

	test[0][0] = 4;

	table<int> test2 = test;

	test[0][0] = 10;

	std::cout << "test : " << test[0][0];

	std::cout << std::endl;

	std::cout << "test2 : " << test2[0][0];

	std::cout << std::endl;

	table<double> myvector(2, 3);

	table<double> myvector2 = myvector;
}
