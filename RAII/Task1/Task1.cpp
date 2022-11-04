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

		delete[] arr;
	}

};

int main()
{

	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		//		arr.add_element(32);
		std::cout << arr.get_element(2) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

}