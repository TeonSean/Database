#ifndef RECORDINFO_H_INCLUDED
#define RECORDINFO_H_INCLUDED

#include<map>
#include<string>
#include<vector>
#include"Exception.h"
#include"Type.h"
#include"Base.h"

class RecordInfo
{
private:
	const static std::string TAG;
    std::map<std::string, int> indexes;
    std::vector<std::string> names;
    std::vector<bool> nullables;
    std::vector<int> types;
    std::vector<int> offsets;
    std::vector<int> extras;
    std::vector<std::string> foreigns;
    std::vector<int> primKeyInfo;
    std::vector<bool> isPrims;
    std::vector<int> primaryKeys;
    int recordLength;
    int recordInfoLength;
    int primKeyLen;
    int primKeyCnt;

public:
    RecordInfo();

    void printRecordDesc(std::string tbname);

    void init();

    std::vector<int>& getPrimaryKeys();

    bool contains(std::string name);

    int index(std::string name);

    std::string name(int index);

    bool nullable(std::string name);

    int type(std::string name);

    int length(std::string name);

    bool isPrim(std::string name);

    bool isPrim(int index);

    int offset(std::string name);

    int extra(std::string name);

    std::string foreign(std::string name);

    bool nullable(int i);

    int type(int i);

    int length(int i);

    int displayLength(int i);

    int offset(int i);

    int extra(int i);

    std::string foreign(int i);

    int getRecordLength();

    int getRecordInfoLength();

    void setRecordInfoLength(int n);

    int getFieldCount();

    int getPrimKeyLen();

    int getPrimKeyCnt();

    void setPrimKeyCnt(int n);

    const std::vector<int>& getPrimKeyInfo();

    int addField(std::string name, int type, bool nullable, int extra, std::string foreign, bool isPrim);

    void reset(int n);

    const static int SUCCEED = 0;

    const static int EMPTY_FIELD_NAME = 156;

    const static int FIELD_ALREADY_EXIST = 561;

    const static int EXCEED_PAGE_LIMIT = 615;
};

struct SearchInfo
{
    std::map<int, bool> nulls;
    std::map<int, const void*> values[5];
    std::map<int, std::vector<const void*> > notEqual;
    std::map<int, std::vector<int> > fields[6];

    SearchInfo();

    bool processWheresWithOneTable(std::vector<Where>& pWheres, RecordInfo* ri, std::string tbname);
};

struct UpdateInfo
{
    std::map<int, SetRValue> action;
};

#endif // RECORDINFO_H_INCLUDED
