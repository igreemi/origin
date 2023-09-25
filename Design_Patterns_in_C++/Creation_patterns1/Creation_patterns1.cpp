﻿#include <iostream>
#include "sql_query_builder.h"

int main()
{
    SqlSelectQueryBuilder query_builder;
    query_builder.AddWhere("id", "42").AddWhere("name", "John");
    query_builder.AddFrom("students");
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("students3");
    query_builder.AddFrom("students6");
    std::cout << query_builder.BuildQuery();
//    static_assert(query_builder.BuildQuery(),
//       "SELECT name, phone FROM students WHERE id=42 AND name=John;");

    return 0;
}