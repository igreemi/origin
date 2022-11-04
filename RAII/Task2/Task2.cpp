#include <iostream>
#include <exception>

class smart_array
{
private:
	int size = 0;
	int i = 0;
	int* arr = nullptr;

public:
	smart_array() {}

	smart_array(int size) {
		this->size = size;
		this->arr = new int[size]();

	}

	smart_array& operator=(const smart_array& other)
	{

		arr = new int[other.size];

		for (int i = 0; i < other.size; i++)
		{
			arr[i] = other.arr[i];
		}
		size = other.size;

		return *this;
	}
	void add_element(int num)
	{
		if (i < size)
		{

			arr[i] = num;
			if (i < size)
			{
				i++;
			}
		}
		else
			if (i > size - 1) {
				throw std::runtime_error(" Exiting an array of an array ");
			}

	}

	int get_element(int num)
	{
		if (num < size)
		{
			return arr[num];

		}
		else

		{
			throw std::runtime_error(" Exiting an array of an array ");
		}
	}

	~smart_array() {
		if (arr != nullptr)
		{
			delete[] arr;
		}
	}

};

int main()
{

	try {
		std::cout << "Array before change" << std::endl;

		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		//		arr.add_element(32);

		smart_array arr2(5);
		arr2.add_element(3);
		arr2.add_element(5);
		arr2.add_element(200);
		arr2.add_element(28);
		arr2.add_element(30);

		smart_array arr3(3);
		arr3.add_element(11);
		arr3.add_element(22);
		arr3.add_element(33);

		std::cout << "arr: " << arr.get_element(2) << " | "
			<< "arr2: " << arr2.get_element(2) << " | "
			<< "arr3: " << arr3.get_element(2) << std::endl;

		std::cout << std::endl;
		std::cout << "Array after modification" << std::endl;

		arr = arr2;
		arr2 = arr3;
		arr3 = arr;

		std::cout << "arr: " << arr.get_element(2) << " | "
			<< "arr2: " << arr2.get_element(2) << " | "
			<< "arr3: " << arr3.get_element(2) << std::endl;

	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}