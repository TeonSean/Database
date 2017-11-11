#include"DBRecordSlot.h"

DBRecordSlot::DBRecordSlot(BufType cache, DBRecordInfo* ri):
    DBSlot(cache), ri(ri)
{

}

int DBRecordSlot::write(std::vector<void*>& data)
{
    int cnt = ri->getFieldCount();
    if(cnt != data.size())
    {
        return ERROR;
    }
    write_id((*this)[1]);
    for(int i = 1; i < cnt; i++)
    {
        int offset = ri->offsets[i];
        char* ptr = (char*)(data[i]);
        if(ptr == NULL)
        {
            writeBoolToChar((*this)[offset], true);
        }
        else
        {
            writeBoolToChar((*this)[offset], false);
            writeData((*this)[offset + 1], ptr, DBType::typeSize(ri->types[i]));
        }
    }
    return SUCCEED;
}

void DBRecordSlot::print()
{
    std::vector<void*> data;
    if(read(data) != SUCCEED)
    {
        return;
    }
    for(int idx = 0; idx < data.size(); idx++)
    {
        void* ptr = data[idx];
        DBPrint(ri->names[idx] + ": ");
        if(ptr == NULL)
        {
            DBPrintLine("NULL");
        }
        else
        {
            switch(ri->types[idx])
            {
            case DBType::_ID:
                DBPrint_ID((char*)ptr);
                DBPrintLine("");
                break;
            case DBType::INT:
                DBPrintLine(*(int*)ptr);
                break;
            }
        }
    }
}

int DBRecordSlot::equal(std::map<int, void*>& data)
{
    return 0;
}

int DBRecordSlot::read(std::vector<void*>& data)
{
    data.clear();
    int cnt = ri->getFieldCount();
    if(cnt < 0)
    {
        return ERROR;
    }
    data.assign(cnt, NULL);
    data[0] = (void*)((*this)[1]);
    for(int i = 1; i < cnt; i++)
    {
        int offset = ri->offsets[i];
        bool isNull;
        readCharToBool((*this)[offset], &isNull);
        if(ri->nullables[i] && isNull)
        {
            data[i] = NULL;
        }
        else
        {
            int len = DBType::typeSize(ri->types[i]);
            char* tmp = new char[len];
            readData((*this)[offset + 1], tmp, len);
            data[i] = (void*)tmp;
        }
    }
    return SUCCEED;
}
