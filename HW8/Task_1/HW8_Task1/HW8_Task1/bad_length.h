#pragma once
#include <iostream>

class bad_length
	:
	public std::runtime_error
	{

	public:
		bad_length(const std::string & msg);

};

