#pragma once
#include <iostream>

namespace my_vector
{

	template <typename T>

	class vector
	{

	private:

		T* arr = nullptr;

		size_t size_v;

		size_t capacity_v;

	public:

		vector()
		{

			arr = new T[1]();

			capacity_v = 1;

		}

		vector& operator=(const vector& other)
		{

			if (&other != this)
			{

				delete[] arr;

				arr = new T[other.size_v];

				for (int i = 0; i < other.size_v; i++)
				{
					arr[i] = other.arr[i];
				}

				size_v = other.size_v;

			}

			return *this;

		}

		vector(const vector& other)
		{

			delete[] arr;

			arr = new T[other.size_v];

			for (int i = 0; i < other.size_v; i++)
			{
				arr[i] = other.arr[i];
			}

			size_v = other.size_v;

		}

		~vector()
		{

			if (arr != nullptr)
			{
				delete[] arr;
			}

		}

		bool isEmpty() const
		{
			return size_v == 0;
		}

		int size() const
		{
			return size_v;
		}

		int capacity() const
		{
			return capacity_v;
		}

		void addNewMemory()
		{

			capacity_v = (size_v * 2);

			T* tmpArr = arr;

			arr = new T[capacity_v];

			for (int i = 0; i < size_v; ++i)
			{
				arr[i] = tmpArr[i];
			}

			delete[] tmpArr;

		}

		void push_back(const T& value)
		{

			if (size_v >= capacity_v)
			{
				addNewMemory();
			}

			arr[size_v++] = value;

		}

		void remove(size_t index)
		{

			for (size_t i = index + 1; i < size_v; ++i)
			{
				arr[i - 1] = arr[i];
			}

			--size;

		}

		T& operator[](size_t index)
		{
			return arr[index];
		}

		const T& operator[](size_t index) const
		{
			return arr[index];
		}

		T& at(size_t index)
		{

			if (index >= size_v)
			{
				throw std::out_of_range("Bad index");
			}

			return arr[index];

		}

		T* begin()
		{
			return &arr[0];
		}

		const T* cbegin() const
		{
			return &arr[0];
		}

		T* end()
		{
			return &arr[size_v];
		}

		const T* cend() const
		{
			return &arr[size_v];
		}

	};

}