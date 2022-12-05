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
			arr[i] = new int[cols];
		}
	}

	table() {}

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
	std::cout << test[0][0]; // выводит 4
}
