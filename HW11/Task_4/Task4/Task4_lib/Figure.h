#pragma once

#ifdef TASK4LIBEXPORTS
#define TASK4LIBEXPORTS_API __declspec(dllexport)
#else
#define TASK4LIBEXPORTS_API __declspec(dllimport)
#endif

#include <string>

 class Figure {
protected:
	std::string figure;
	int a, b, c, A, B, C;
public:
	TASK4LIBEXPORTS_API	Figure();

	TASK4LIBEXPORTS_API	std::string figure_name();

	TASK4LIBEXPORTS_API	virtual std::string get_side();

	TASK4LIBEXPORTS_API	virtual std::string get_angle();

};