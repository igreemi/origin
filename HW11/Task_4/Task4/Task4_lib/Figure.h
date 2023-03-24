#pragma once

#ifdef TASK4LIB_EXPORTS
#define TASK4LIB_EXPORTS_API __declspec(dllexport)
#else
#define TASK4LIB_EXPORTS_API __declspec(dllimport)
#endif

#include <string>

 class Figure {
protected:
	std::string figure;
	int a, b, c, A, B, C;
public:
	TASK4LIB_EXPORTS_API	Figure();

	TASK4LIB_EXPORTS_API	std::string figure_name();

	TASK4LIB_EXPORTS_API	virtual std::string get_side();

	TASK4LIB_EXPORTS_API	virtual std::string get_angle();

};