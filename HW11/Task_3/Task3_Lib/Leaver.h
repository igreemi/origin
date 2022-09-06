#pragma once
#include <string>

#ifdef TASK3LIBRARYDYNAMIC_EXPORTS
#define TASK3LIBRARY_API __declspec(dllexport)
#else
#define TASK3LIBRARY_API __declspec(dllimport)
#endif
namespace Task3
{
	class Leaver
	{
	public:
		TASK3LIBRARY_API std::string leave(std::string name);
	};
}