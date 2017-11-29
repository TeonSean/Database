#ifndef DBBASE_H_INCLUDED
#define DBBASE_H_INCLUDED

#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>

struct Field
{
    int type;
    int extra;
    bool nullable;
    std::string name;
};
struct FieldType
{
    int type;
    int extra;
};
struct Type
{
	std::string m_string;
	int m_int;
	struct Field m_field;
	struct FieldType m_type;
};

#define YYSTYPE Type

#endif // DBBASE_H_INCLUDED
