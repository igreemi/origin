#pragma once
#include <iostream>
class FigureEx:
	public std::domain_error
{
	std::string msg;

public:
	FigureEx(const std::string &msg);

	FigureEx();

};

