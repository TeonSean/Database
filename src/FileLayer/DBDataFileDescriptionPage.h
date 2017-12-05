#ifndef DBDATAFILEDESCRIPTIONPAGE_H_INCLUDED
#define DBDATAFILEDESCRIPTIONPAGE_H_INCLUDED

#include"DBPage.h"
#include"DBSlot.h"

class DBDataFileDescriptionPage: public DBPage
{
protected:
    class DBDataFileDescriptionSlot:public DBSlot
    {
    public:
        DBDataFileDescriptionSlot(BufType cache);

        int size();
    };

    DBDataFileDescriptionSlot* dfds;
    DBRecordInfo* ri;

public:
    DBDataFileDescriptionPage(BufType cache, int index, int pageID, int mode, DBRecordInfo* ri);

    int getFirstDataPage();

    int getFirstUsagePage();

    int getPageNumber();

    int getRecordInfoLength();

    int getPrimaryKeyIndex();

    void setFirstDataPage(int n);

    void setFirstUsagePage(int n);

    void setPageNumber(int n);

    void setRecordInfoLength(int n);

    void setPrimaryKeyIndex(int n);

    void incrementPageNumber(int type);

    void writeFields();

    void print();

    static int maxRecordInfoLength();

    const static int FIRST_DATA_PAGE_OFFSET = 0;
    const static int FIRST_USAGE_PAGE_OFFSET = FIRST_DATA_PAGE_OFFSET + sizeof(int);
    const static int PAGE_NUMBER_OFFSET = FIRST_USAGE_PAGE_OFFSET + sizeof(int);
    const static int PRIMARY_KEY_INDEX_OFFSET = PAGE_NUMBER_OFFSET + sizeof(int);
    const static int RECORD_INFO_LENGTH_OFFSET = PRIMARY_KEY_INDEX_OFFSET + sizeof(int);
    const static int RECORD_INFO_OFFSET = RECORD_INFO_LENGTH_OFFSET + sizeof(int);

    const static int RECORD_INFO_TYPE_OFFSET = 0;
    const static int RECORD_INFO_NULLABLE_OFFSET = RECORD_INFO_TYPE_OFFSET + sizeof(int);
    const static int RECORD_INFO_EXTRA_OFFSET = RECORD_INFO_NULLABLE_OFFSET + sizeof(int);
    const static int RECORD_INFO_NAME_LENGTH_OFFSET = RECORD_INFO_EXTRA_OFFSET + sizeof(int);
    const static int RECORD_INFO_NAME_OFFSET = RECORD_INFO_NAME_LENGTH_OFFSET + sizeof(int);
};

#endif // DBDATAFILEDESCRIPTIONPAGE_H_INCLUDED
