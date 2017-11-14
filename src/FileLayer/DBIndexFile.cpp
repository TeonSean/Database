#include "DBIndexFile.h"

DBIndexFile::DBIndexFile(const char* name, int _dataLen){
    dataLen = _dataLen;
    indexname = name;
	fm = DBFileIOModel::getInstance();
	up = NULL;
    fileID = -1;
}

int DBIndexFile::allocateNewPage(){
	DBUsagePage* up = openUsagePage(0);
	int ret = 0;
	while(true){
		ret = up -> findFirstAvailable();
		if (ret > 0)
			break;
		up = openUsagePage(up -> getNextSameType());
	}
	return ret;
}

int DBIndexFile::copyToNewPage(int pageID){
	int newPageID = allocateNewPage();
    DBIndexDataPage* newPage = (DBIndexDataPage*) pages[newPageID];
    DBIndexDataPage* curpage = (DBIndexDataPage*)pages[pageID];
	newPage -> setCache(curpage -> getCache());
    return newPageID;
}

DBUsagePage* DBIndexFile::openUsagePage(int pid){
    if(pages.count(pid))
    {
        DBPage* re = pages[pid];
        return re->getPageType() == DBType::USAGE_PAGE ? (DBUsagePage*)re : NULL;
    }
    int index;
    BufType cache = fm->getPage(fileID, pid, index);
    if(DBPageInfoSlot::getPageType(cache) != DBType::USAGE_PAGE)
    {
        return NULL;
    }
    DBUsagePage* re = new DBUsagePage(cache, index, pid, MODE_PARSE);
    pages[pid] = re;
    return re;
}

DBIndexDataPage* DBIndexFile::openIndexDataPage(int pid){
	if (pages.count(pid)){
		DBPage* re = pages[pid];
		return re -> getPageType() == DBType::INDEX_DATA_PAGE ? (DBIndexDataPage*) re : NULL;	
	}
	int index;
	BufType cache = fm -> getPage(fileID, pid, index);
	if (DBPageInfoSlot::getPageType(cache) != DBType::INDEX_DATA_PAGE){
		return NULL;
	}
	DBIndexDataPage* re = new DBIndexDataPage(cache, index, pid, MODE_PARSE, dataLen);
	pages[pid] = re;
	return re;
}

int DBIndexFile::createFile(const char* name){
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
    int index;
    BufType cache = fm->getPage(fileID, 0, index);
    return SUCCEED;
}

int DBIndexFile::deleteFile(const char* name){
    if(fm->deleteFile(name) != SUCCEED)
    {
        DBLogLine("ERROR");
        return FILE_OR_DIRECTORY_DOES_NOT_EXIST;
    }
    return SUCCEED;
}

int DBIndexFile::closeFile(const char* name){
//	fm->flush(dfdp->getIndex());
    for(std::map<int, DBPage*>::iterator iter = pages.begin(); iter != pages.end(); iter++)
    {
        fm->flush(iter->second->getIndex());
    }
    pages.clear();
    if(fm->closeFile(fileID) != SUCCEED)
    {
        DBLogLine("ERROR");
        return FILE_OR_DIRECTORY_DOES_NOT_EXIST;
    }
    return SUCCEED;
}

int DBIndexFile::setAvailableOfIndexPage(int ipid, bool available){
	DBUsagePage* up = openUsagePage(0);
	while(true){
		if (up == NULL){
			return ERROR;
		}
		if (up -> withinRange(ipid)){
			break;
		}
		up = openUsagePage(up -> getNextSameType());
	}
	up -> setAvailable(ipid, available);
	return SUCCEED;
}