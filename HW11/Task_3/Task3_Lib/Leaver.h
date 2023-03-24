#pragma once
#include <string>

#ifdef Task3Lib_EXPORTS
#define Task3Lib_API __declspec(dllexport)
#else
#define Task3Lib_API __declspec(dllimport)
#endif
namespace Task3
{
	class Task3Lib_API Leaver
	{
	public:
		std::string leave(std::string name);
	};
}