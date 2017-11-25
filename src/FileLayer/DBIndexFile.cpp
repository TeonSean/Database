#include "DBIndexFile.h"

DBIndexFile::DBIndexFile(const char* root):
    root(root)
{
	fm = DBFileIOModel::getInstance();
    fileID = -1;
    open = false;
}

int DBIndexFile::allocateNewLeafNode()
{
    if(!open)
    {
        return FILE_NOT_OPENED;
    }
    int cnt = ifdp->getPageNumber();
    if(cnt <= 0)
    {
        return ERROR;
    }
    int index;
    BufType cache = fm->getPage(fileID, cnt, index);
    DBIndexLeafPage* ifp = new DBIndexLeafPage(cache, index, cnt, MODE_CREATE, keyType);
    pages[cnt] = ifp;
    DBLog("Allocated new leaf page ");
    DBLogLine(cnt);
    ifdp->incrementPageNumber();
    return cnt;
}

int DBIndexFile::allocateNewInternalNode()
{
    if(!open)
    {
        return FILE_NOT_OPENED;
    }
    int cnt = ifdp->getPageNumber();
    if(cnt <= 0)
    {
        return ERROR;
    }
    int index;
    BufType cache = fm->getPage(fileID, cnt, index);
    DBIndexInternalPage* ifp = new DBIndexInternalPage(cache, index, cnt, MODE_CREATE, keyType);
    pages[cnt] = ifp;
    DBLog("Allocated new internal page ");
    DBLogLine(cnt);
    ifdp->incrementPageNumber();
    return cnt;
}

void DBIndexFile::printFileDescription()
{
    if(!open)
    {
        return;
    }
    ifdp->print();
    DBPrint("Max degree of each node is: ");
    DBPrintLine(maxDgr);
    DBPrint("Min degree of each node is: ");
    DBPrintLine(minDgr);
}

DBIndexNodePage* DBIndexFile::openNode(int pid)
{
    if(!open)
    {
        return NULL;
    }
	if(pages.count(pid))
    {
		return pages[pid];
	}
    if(pid <= 0 || pid >= ifdp->getPageNumber())
    {
        return NULL;
    }
	int index;
	BufType cache = fm->getPage(fileID, pid, index);
	int pageType = DBPageInfoSlot::getPageType(cache);
    if(pageType == DBType::INDEX_INTERNAL_PAGE)
    {
        DBIndexInternalPage* re = new DBIndexInternalPage(cache, index, pid, MODE_PARSE, keyType);
        pages[pid] = re;
        return re;
    }
    else if(pageType == DBType::INDEX_LEAF_PAGE)
    {
        DBIndexLeafPage* re = new DBIndexLeafPage(cache, index, pid, MODE_PARSE, keyType);
        pages[pid] = re;
        return re;
    }
    else
    {
        return NULL;
    }
}

int DBIndexFile::split(DBIndexNodePage* cur)
{
    if(cur->getChildrenCount() >= maxDgr)
    {
        int new_pid;
        if(cur->isLeaf())
        {
            new_pid = allocateNewLeafNode();
        }
        else
        {
            new_pid = allocateNewInternalNode();
        }
        if(new_pid <= 0)
        {
            return ERROR;
        }
        DBIndexNodePage* new_page = openNode(new_pid);
        DBIndexNodePage::split(cur, new_page);
        if(cur->isLeaf())
        {
            new_page->setNextSameType(cur->getNextSameType());
            cur->setNextSameType(new_page->getPageID());
        }
        else
        {
            int curPage = new_page->getMinPage();
            while(curPage != new_page->getMaxPage())
            {
                DBIndexNodePage* tmp = openNode(curPage);
                tmp->setParent(new_pid);
                curPage = tmp->getNextSameType();
            }
            openNode(curPage)->setParent(new_pid);
        }
        if(cur->getParent() <= 0)
        {
            int new_root = allocateNewInternalNode();
            if(new_root <= 0)
            {
                return ERROR;
            }
            rootNode = new_root;
            ifdp->setRootPage(rootNode);
            DBIndexNodePage* new_root_node = openNode(new_root);
            new_root_node->insert(cur->getMaxKey(), cur->getPageID());
            new_root_node->insert(new_page->getMaxKey(), new_page->getPageID());
            cur->setParent(new_root);
            new_page->setParent(new_root);
            return SUCCEED;
        }
        else
        {
            DBIndexNodePage* parent = openNode(cur->getParent());
            new_page->setParent(cur->getParent());
            parent->changeKeyOfPage(cur->getPageID(), cur->getMaxKey());
            parent->insert(new_page->getMaxKey(), new_page->getPageID());
            return split(parent);
        }
    }
    return SUCCEED;
}

int DBIndexFile::insert(void* key, int pid)
{
    DBIndexNodePage* curNode = openNode(rootNode);
    if(curNode == NULL)
    {
        return ERROR;
    }
    void* maxKey = curNode->getMaxKey();
    if(maxKey == NULL)
    {
        curNode->insert(key, pid);
        return SUCCEED;
    }
    while(true)
    {
        if(curNode == NULL || curNode->isLeaf())
        {
            break;
        }
        if(larger(key, curNode->getMaxKey(), keyType))
        {
            while(curNode != NULL && !curNode->isLeaf())
            {
                curNode->setMaxKey(key);
                curNode = openNode(curNode->getMaxPage());
            }
            break;
        }
        curNode = openNode(curNode->search(key));
    }
    if(curNode == NULL)
    {
        return ERROR;
    }
    int re = curNode->insert(key, pid);
    if(re != SUCCEED)
    {
        return re;
    }
    re = split(curNode);
    if(re != SUCCEED)
    {
        return re;
    }
    return SUCCEED;
}

int DBIndexFile::search(void* key)
{
    DBIndexNodePage* curNode = openNode(rootNode);
    while(curNode != NULL && !curNode->isLeaf())
    {
        curNode = openNode(curNode->search(key));
    }
    if(curNode == NULL)
    {
        return ERROR;
    }
    return curNode->searchEqual(key);
}

int DBIndexFile::createFile(const char* name, int keyType)
{
    if(open)
    {
        DBLogLine("ERROR");
        return A_FILE_ALREADY_OPENED;
    }
    if(fm->createFile(name) != SUCCEED)
    {
        DBLogLine("ERROR");
        return FILE_OR_DIRECTORY_DOES_NOT_EXIST;
    }
    if(fm->openFile(name, fileID) != SUCCEED)
    {
        DBLogLine("ERROR");
        return FILE_OR_DIRECTORY_DOES_NOT_EXIST;
    }
    this->keyType = keyType;
    open = true;
    keyLength = DBType::typeSize(keyType);
    int index;
    BufType cache = fm->getPage(fileID, 0, index);
    ifdp = new DBIndexFileDescriptionPage(cache, index, 0, MODE_CREATE, keyType);
    int root = allocateNewLeafNode();
    ifdp->setRootPage(root);
    fm->flush(ifdp->getIndex());
    fm->closeFile(fileID);
    open = false;
    return SUCCEED;
}

int DBIndexFile::deleteFile(const char* name)
{
    if(open)
    {
        DBLogLine("ERROR");
        return A_FILE_ALREADY_OPENED;
    }
    if(fm->deleteFile(name) != SUCCEED)
    {
        DBLogLine("ERROR");
        return FILE_OR_DIRECTORY_DOES_NOT_EXIST;
    }
    return SUCCEED;
}

int DBIndexFile::closeFile()
{
    if(!open)
    {
        return FILE_NOT_OPENED;
    }
    fm->flush(ifdp->getIndex());
    for(std::map<int, DBIndexNodePage*>::iterator iter = pages.begin(); iter != pages.end(); iter++)
    {
        fm->flush(iter->second->getIndex());
    }
    if(fm->closeFile(fileID) != SUCCEED)
    {
        DBLogLine("ERROR");
        return FILE_OR_DIRECTORY_DOES_NOT_EXIST;
    }
    pages.clear();
    open = false;
    return SUCCEED;
}

int DBIndexFile::openFile(const char* name)
{
    if(open)
    {
        DBLogLine("ERROR");
        return A_FILE_ALREADY_OPENED;
    }
    if(fm->openFile(name, fileID) != SUCCEED){
        DBLogLine("ERROR");
        return FILE_OR_DIRECTORY_DOES_NOT_EXIST;
    }
    int index;
    open = true;
    this->name = name;
    BufType cache = fm->getPage(fileID, 0, index);
    ifdp = new DBIndexFileDescriptionPage(cache, index, 0, MODE_PARSE);
    keyType = ifdp->getKeyType();
    rootNode = ifdp->getRootPage();
    keyLength = DBType::typeSize(keyType);
    openNode(rootNode)->calcDegree(minDgr, maxDgr);
    return SUCCEED;
}

void DBIndexFile::test()
{
    createFile("test.idx", DBType::INT);
    closeFile();
    openFile("test.idx");
    for(int i = 0; i < 1000000; i++)
    {
        insert(&i, i);
    }
    closeFile();

    openFile("test.idx");
    printFileDescription();
    for(int i = 0; i < 1000000; i++)
    {
        DBPrintLine(search(&i));
    }
    closeFile();
}
