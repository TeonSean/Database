#include"DBIndexNodePage.h"

DBIndexNodePage::DBIndexNodePage(BufType cache, int index, int pageID, int type, int mode, int keyLength):
    DBPage(cache, index, pageID, type, mode), keyLength(keyLength)
{
    ins = new DBIndexNodeSlot((*this)[PAGE_INFO_SLOT_OFFSET + pis->size()], keyLength);
    if(mode == MODE_CREATE)
    {
        ins->setChildrenCount(0);
        ins->setParentNode(0);
        pis->setLengthFixed(false);
        pis->setPageType(type);
        pis->setFirstAvailableByte(pis->size() + ins->size());
        pis->setNextSamePage(-1);
    }
}

void DBIndexNodePage::print()
{
    DBPage::print();
    if(pis->getPageType() == DBType::INDEX_INTERNAL_PAGE)
    {
        DBPrintLine("This is an internal node.");
    }
    else if(pis->getPageType() == DBType::INDEX_LEAF_PAGE)
    {
        DBPrintLine("This is a leaf node.");
    }
    DBPrint("Keys are of length ");
    DBPrintLine(keyLength);
    ins->print();
}
