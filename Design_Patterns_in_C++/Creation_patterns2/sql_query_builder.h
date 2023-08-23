#pragma once
#include <string>
#include <sstream>
#include <map>
#include <vector>

struct SelectQuery
{
	std::string column = "";
	std::string from = "";
	std::string where = "";
	std::vector<std::string> columns_;
};

class SqlSelectQueryBuilder
{
private:
	SelectQuery select_query;
public:
	SqlSelectQueryBuilder& AddColumn(const std::string& column) noexcept
	{
		select_query.columns_.push_back(column);
		return *this;
	}

	SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept
	{
		select_query.columns_.insert(select_query.columns_.end(), columns.begin(), columns.end());
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

	SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept
	{
		for (const auto& i : kv) {
			AddWhere(i.first, i.second);
		}
		return *this;
	}

	std::string BuildQuery() const
	{
		std::string query = "SELECT ";

		if (select_query.columns_.empty()) {
			query += "*";
		}
		else {
			for (size_t i = 0; i < select_query.columns_.size(); ++i) {
				query += select_query.columns_[i];
				if (i < select_query.columns_.size() - 1) {
					query += ", ";
				}
			}
		}

		query += " FROM " + select_query.from;
		if (!select_query.where.empty()) {
			query += " WHERE " + select_query.where;
		}
		return query + ";";
	}
};
