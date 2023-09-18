#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

class ini_parser
{
private:
	std::map<std::string, std::map<std::string, std::string>> sections;
	int count_str = 0;

public:
	explicit ini_parser(const std::string& file_name);

	template <typename T>
	T get_value(const std::string& s) const
	{
		std::stringstream search(s);

		std::size_t delimiter_pos = s.find('.');

		if (delimiter_pos == std::string::npos)
		{
			throw std::runtime_error("�������� ������ ������. ��������� [��������_������.��������_����������].");
		}

		std::string search_section = s.substr(0, delimiter_pos);
		std::string search_var = s.substr(delimiter_pos + 1);

		if (sections.find(search_section) == sections.end())
		{
			throw std::runtime_error("������ �����������.");
		}

		if (sections.at(search_section).find(search_var) == sections.at(search_section).end())
		{
			std::string tmp_var;

			int count = 1;
			int size = sections.at(search_section).size();

			for (const auto& pair : sections.at(search_section))
			{
				tmp_var += pair.first;
				if (count < size)
				{
					tmp_var += " ��� ";
				}
				count++;
			}

			throw std::runtime_error("���������� �����������. �������� �� ����� �����: " + tmp_var);
		}

		std::istringstream tmp_value(sections.at(search_section).at(search_var));

		T value;

		if (!(tmp_value >> value))
		{
			throw std::runtime_error("�������� ���������� ����������� ��� �������� ��� ��������.");
		}

		return value;
	}
};

