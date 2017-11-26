#ifndef DBDATABASE_H_INCLUDED
#define DBDATABASE_H_INCLUDED

#include"../DBInclude.h"
#include"../FileLayer/DBDataFile.h"
#include"../FileLayer/../FileLayer/DBIndexFile.h"

class DBDataBase
{
private:
    static DBDataBase* instance;
    DBDataFile* data;
    std::map<std::string, DBIndexFile*> indexes;

    const char* const root;
    const char* name;

    DBDataBase(const char* root = "/home/teon/Documents/Database");

public:
    static DBDataBase* getInstance();

    void createDatabase(const char* name);
};

#endif // DBDATABASE_H_INCLUDED


