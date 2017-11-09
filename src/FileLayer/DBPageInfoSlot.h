#ifndef DBPAGEINFOSLOT_H_INCLUDED
#define DBPAGEINFOSLOT_H_INCLUDED

#include"DBSlot.h"

class DBPageInfoSlot: public DBSlot
{
protected:
    BufType pageType;           // int
    BufType firstAvailableByte; // int
    BufType lengthFixed;        // int
    BufType nextSamePage;       // int
    //TODO: usage byte

public:

    DBPageInfoSlot(BufType cache, int type, int parse = false);

    int size();

    void print();

    int getPageType();

    int getFirstAvailableByte();

    int isLengthFixed();

    int getNextSamePage();

    void setPageType(int n);

    void setFirstAvailableByte(int n);

    void setLengthFixed(int n);

    void setNextSamePage(int n);

    void write(int fsb, int lf, int nsp);

    const static int PAGE_TYPE_OFFSET = 0;
    const static int FIRST_AVAILABLE_BYTE_OFFSET = PAGE_TYPE_OFFSET + sizeof(int);
    const static int LENGTH_FIXED_OFFSET = FIRST_AVAILABLE_BYTE_OFFSET + sizeof(int);
    const static int NEXT_SAME_PAGE_OFFSET = LENGTH_FIXED_OFFSET + sizeof(int);
};

#endif // DBPAGEINFOSLOT_H_INCLUDED