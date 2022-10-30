#pragma once
#include <string>

#ifdef TASK2LIB_EXPORTS
#define TASK2LIBRARY_API __declspec(dllexport)
#else
#define TASK2LIBRARY_API __declspec(dllimport)
#endif
namespace Task2
{
	class Leaver
	{
	public:
		TASK2LIBRARY_API std::string leave(std::string name);
	};
}

