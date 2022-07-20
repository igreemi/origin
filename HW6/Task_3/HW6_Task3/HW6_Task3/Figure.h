#pragma once
#include <string>
class Figure {
protected:
	std::string figure;
	int a, b, c, A, B, C;
public:
	Figure();

	std::string figure_name();

	virtual std::string get_side();

	virtual std::string get_angle();

};