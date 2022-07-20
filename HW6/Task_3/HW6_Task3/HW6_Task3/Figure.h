#pragma once
#include <string>
class Figure {
protected:
	std::string figure;
	int a = 0, b = 0, c = 0, A = 0, B = 0, C = 0;
public:
	Figure();

	std::string figure_name();

	virtual std::string get_side();

	virtual std::string get_angle();

};