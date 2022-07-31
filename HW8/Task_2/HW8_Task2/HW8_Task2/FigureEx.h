#pragma once

#include <stdexcept>
#include <string>

class FigureEx :
	public std::domain_error
{

public:
	FigureEx(const std::string& msg);

};

