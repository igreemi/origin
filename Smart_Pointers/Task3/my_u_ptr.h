#pragma once

namespace My
{
	template <class T>
	class my_u_ptr
	{
	private:

		T* my_ptr;

	public:

		my_u_ptr(T* ptr) : my_ptr(ptr){}

		~my_u_ptr()
		{
			delete my_ptr;
		}

		my_u_ptr(my_u_ptr& a) = delete;

		my_u_ptr& operator=(my_u_ptr& a) = delete;

		my_u_ptr(my_u_ptr&& other) : my_ptr(other.Release()) {}

		my_u_ptr& operator=(my_u_ptr&& other)
		{
			delete my_ptr;
			my_ptr = other.my_ptr;
			other.my_ptr = nullptr;
			return *this;
		}

		template<typename U>
		my_u_ptr(my_u_ptr<U>&& other) : my_ptr(other.Release()) {}

		template<typename U>
		my_u_ptr& operator=(my_u_ptr&& other)
		{
			delete my_ptr;
			my_ptr = other.my_ptr;
			other.my_ptr = nullptr;
			return *this;
		}

		T* operator->() const { return my_ptr; }

		T& operator*() const { return *my_ptr; }

		T* Release() 
		{
			T* tmp_ptr = my_ptr;
			my_ptr = nullptr;
			return tmp_ptr;
		}
	};
}