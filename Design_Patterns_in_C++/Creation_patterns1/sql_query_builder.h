#pragma once
#include <string>
#include <sstream>

struct SelectQuery
{
	std::string column = "";
	std::string from = "";
	std::string where = "";
};

class SqlSelectQueryBuilder
{
private:
	SelectQuery select_query;
public:
	SqlSelectQueryBuilder& AddColumn(const std::string& column) noexcept
	{
		if (select_query.column.empty())
		{
			select_query.column = column;
		}
		else
		{
			select_query.column += ", " + column;
		}
		return *this;
	}

	SqlSelectQueryBuilder& AddFrom(const std::string& from) noexcept
	{
		select_query.from = from;
		return *this;
	}

	SqlSelectQueryBuilder& AddWhere(const std::string& where, const std::string& where2) noexcept
	{
		if (select_query.where.empty())
		{
			select_query.where = where + "=" + where2;
		}
		else
		{
			select_query.where += " AND " + where + "=" + where2;
		}
		return *this;
	}

	std::string BuildQuery()
	{
		if (select_query.column.empty())
		{
			select_query.column = "*";
		}
		std::string query = "SELECT " + select_query.column + " FROM " + select_query.from;
		if (!select_query.where.empty()) {
			query += " WHERE " + select_query.where;
		}
		return query + ";";
	}
};
