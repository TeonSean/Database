#ifndef DBRECORDINFO_H_INCLUDED
#define DBRECORDINFO_H_INCLUDED

#include<map>
#include<string>
#include<vector>
#include"DBException.h"

struct SearchInfo
{
    std::map<int, bool> nulls;
    std::map<int, void*> equals;
    std::map<int, void*> largers;
    std::map<int, void*> smallers;
    std::map<int, void*> notEquals;
    std::map<int, void*> largerEquals;
    std::map<int, void*> smallerEquals;
    std::map<int, int> fequals;
    std::map<int, int> flargers;
    std::map<int, int> fsmallers;
    std::map<int, int> fnotEquals;
    std::map<int, int> flargerEquals;
    std::map<int, int> fsmallerEquals;

    void init();
};

class DBRecordInfo
{
private:
    std::map<std::string, int> indexes;
    std::vector<std::string> names;
    std::vector<bool> nullables;
    std::vector<int> types;
    std::vector<int> offsets;
    std::vector<int> extras;
    int recordLength;
    int recordInfoLength;

public:
    DBRecordInfo();

    void init();

    bool contains(std::string name);

    int index(std::string name);

    std::string name(int index);

    bool nullable(std::string name);

    int type(std::string name);

    int length(std::string name);

    int offset(std::string name);

    int extra(std::string name);

    bool nullable(int i);

    int type(int i);

    int length(int i);

    int offset(int i);

    int extra(int i);

    int getRecordLength();

    int getRecordInfoLength();

    void setRecordInfoLength(int n);

    int getFieldCount();

    int addField(std::string name, int type, bool nullable, int extra);

    void reset(int n);

    const static int SUCCEED = 0;

    const static int EMPTY_FIELD_NAME = 156;

    const static int FIELD_ALREADY_EXIST = 561;

    const static int EXCEED_PAGE_LIMIT = 615;
};

#endif // DBRECORDINFO_H_INCLUDED
