#pragma once
#include <iostream>
class FigureEx:
	public std::domain_error
{

public:
	FigureEx(const std::string &msg);

};

