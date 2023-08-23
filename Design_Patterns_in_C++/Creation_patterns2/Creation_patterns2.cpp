#include <iostream>
#include "sql_query_builder.h"

int main()
{
    SqlSelectQueryBuilder query_builder;
 //   query_builder.AddWhere("id", "42").AddWhere("name", "John");
    query_builder.AddFrom("students");
//    query_builder.AddWhere("id", "45").AddWhere("name", "Bon");
//    query_builder.AddColumn("name").AddColumn("phone");

    std::map<std::string, std::string> conditions = {
    {"id", "42"},
    {"name", "John"}
    };

    std::vector<std::string> columns;
    columns.push_back("phone");
    columns.push_back("name");
    columns.push_back("photo");

    query_builder.AddColumns(columns);
    query_builder.AddWhere(conditions);

    std::cout << query_builder.BuildQuery();
    //    static_assert(query_builder.BuildQuery(),
    //       "SELECT name, phone FROM students WHERE id=42 AND name=John;");

    return 0;
}
