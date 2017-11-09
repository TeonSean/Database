#ifndef DBTYPE_H_INCLUDED
#define DBTYPE_H_INCLUDED

#include"../DBInclude.h"
class DBType
{
    const static int typeSize_[];
    const static char* const typeName_[];
    const static char* const pageName_[];

public:
    const static int INT = 0;
    const static int FIRST_TYPE = INT;
    const static int LAST_TYPE = INT;

    const static int DATA_FILE_DESCRIPTION_PAGE = 0;
    const static int DATA_PAGE = DATA_FILE_DESCRIPTION_PAGE + 1;
    const static int INDEX_PAGE = DATA_PAGE + 1;
    const static int FIRST_PAGE_TYPE = DATA_FILE_DESCRIPTION_PAGE;
    const static int LAST_PAGE_TYPE = INDEX_PAGE;

    static int typeSize(int type);

    static const char* typeName(int type);

    static const char* pageName(int type);
};

#endif // DBTYPE_H_INCLUDED