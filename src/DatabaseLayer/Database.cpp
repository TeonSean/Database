#include"Database.h"

Database* Database::instance;

Database::Database(std::string root):
    root(root), name("")
{
    if(access(root.c_str(), F_OK) != 0)
    {
        Print::printLine("Cannot open root directory.");
        exit(0);
    }
    pNames.clear();
    pTypes.clear();
    pNullables.clear();
    pExtras.clear();
    pValues.clear();
    pValueLists.clear();
    pTables.clear();
    pColumns.clear();
    pCols.clear();
    pWheres.clear();
    buffer = new char[8192];
}

void Database::createDatabase(std::string name_)
{
    std::string path("");
    path += (root + "/" + name_);
    if(access(path.c_str(), F_OK) == 0)
    {
        throw Exception("File or directory already exists.");
    }
    mkdir(path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    Print::log("Created directory ").logLine(path);
}

void Database::addPendingField(std::string& name_, int type, bool nullable, int extra)
{
    pNames.push_back(name_);
    pTypes.push_back(type);
    pNullables.push_back(nullable);
    pExtras.push_back(extra);
}

void Database::addPendingTable(std::string& name_)
{
    pTables.push_back(name_);
}

void Database::addPendingColumn(std::string& name_)
{
    pColumns.push_back(name_);
}

void Database::addPendingCol(Col& col)
{
    pCols.push_back(col);
}

void Database::addPendingValue(Value& value)
{
    pValues.push_back(value);
}

void Database::addPendingWhere(Where& where)
{
    pWheres.push_back(where);
}

void Database::addPendingSet(Set& set_)
{
    pSets.push_back(set_);
}

void Database::addPendingValueList()
{
    pValueLists.push_back(pValues);
    pValues.clear();
}

bool Database::processWheresWithOneTable(SearchInfo& si, RecordInfo* ri, std::string tbname)
{
    bool flag = true;
    for(int i = 0; i < pWheres.size(); i++)
    {
        Where& w = pWheres[i];
        if(w.left.table != "" &&
           w.left.table != tbname)
        {
            Print::printLine("Table " + w.left.table + " is not selected.");
            flag = false;
        }
        else if(ri->index(w.left.field) < 0)
        {
            Print::printLine("Table " + tbname + " does not have field" + w.left.field + ".");
            flag = false;
        }
        if(w.type == 2 && w.opCol)
        {
            if(w.col_r.table != "" && w.col_r.table != tbname)
            {
                throw Exception("Table " + w.col_r.table + " is not selected.");
                flag = false;
            }
            else if(ri->index(w.col_r.field) < 0)
            {
                Print::printLine("Table " + tbname + " does not have field" + w.col_r.field + ".");
                flag = false;
            }
        }
    }
    if(!flag)
    {
        pWheres.clear();
        return false;
    }
    for(int i = 0; i < pWheres.size(); i++)
    {
        Where& w = pWheres[i];
        switch(w.type)
        {
        case 0:
            if(si.nulls.count(ri->index(w.left.field)))
            {
                if(!si.nulls[ri->index(w.left.field)])
                {
                    pWheres.clear();
                    return false;
                }
            }
            si.nulls[ri->index(w.left.field)] = true;
            break;
        case 1:
            if(si.nulls.count(ri->index(w.left.field)))
            {
                if(si.nulls[ri->index(w.left.field)])
                {
                    pWheres.clear();
                    return false;
                }
            }
            si.nulls[ri->index(w.left.field)] = false;
            break;
        case 2:
            if(w.opCol)
            {
                if(!si.fields[w.op].count(ri->index(w.left.field)))
                {
                    si.fields[w.op][ri->index(w.left.field)] = std::vector<int>();
                }
                si.fields[w.op][ri->index(w.left.field)].push_back(ri->index(w.col_r.field));
            }
            else
            {
                if(!si.values[w.op].count(ri->index(w.left.field)))
                {
                    si.values[w.op][ri->index(w.left.field)] = std::vector<void*>();
                }
                si.values[w.op][ri->index(w.left.field)].push_back((w.val_r.type == 1 ? (void*)&w.val_r.v_int : (void*)&w.val_r.v_str));
            }
        }
    }
}

void Database::printOneTableSelectResult(SelectResult& sr, std::vector<bool>& selected, RecordInfo* ri)
{
    int columns = 0;
    for(int i = 0; i < selected.size(); i++)
    {
        if(selected[i])
        {
            columns++;
        }
    }
    int index = 0;
    std::list<std::vector<void*> >::iterator iter = sr.results.begin();
    std::stringstream ss;
    while(index <= sr.results.size())
    {
        int rows = std::min(40, (int)sr.results.size() + 1 - index);
        table t;
        t.row_num = rows;
        t.col_num = columns;
        t.col_max_width = (unsigned int *)malloc(sizeof(int) * t.col_num);
        t.content = (const char ***)malloc(sizeof(const char **) * t.row_num);
        for(int i = 0; i < rows; i++)
        {
            t.content[i] = (const char **)malloc(sizeof(const char *) * t.col_num);
        }
        int curRow = 0;
        std::string content[rows][columns];
        if(index == 0)
        {
            for(int i = 0, j = 0; i < selected.size(); i++)
            {
                if(selected[i])
                {
                    content[0][j] = ri->name(i);
                    t.content[0][j] = content[0][j].c_str();
                    j++;
                }
            }
            curRow = 1;
            index++;
            t.b = true;
        }
        else
        {
            t.b = false;
        }
        for(; curRow < rows; curRow++)
        {
            std::vector<void*>& dat =  *iter;
            for(int i = 0, j = 0; i < selected.size(); i++)
            {
                if(selected[i])
                {
                    if(dat[i] == NULL)
                    {
                        content[curRow][j] = "NULL";
                    }
                    else
                    {
                        ss.str("");
                        switch(ri->type(i))
                        {
                        case Type::INT:
                            ss << *(int*)(dat[i]);
                            break;
                        }
                        content[curRow][j] = ss.str();
                    }
                    t.content[curRow][j] = content[curRow][j].c_str();
                    j++;
                }
            }
            index++;
            iter++;
        }
        memset(buffer, 0, 8192);
        format_table(&t, buffer);
        Print::print(buffer);
    }

}

void Database::processSets(UpdateInfo& ui, RecordInfo* ri, std::string tbname)
{
    bool flag = true;
    for(int i = 0; i < pSets.size(); i++)
    {
        Set& s = pSets[i];
        if(ri->index(s.field) < 0)
        {
            Print::printLine("Table " + tbname + " does not have field" + s.field + ".");
            flag = false;
        }
    }
    if(!flag)
    {
        pSets.clear();
        throw Exception("Error in set clause.");
    }
    for(int i = 0; i < pSets.size(); i++)
    {
        Set& s = pSets[i];
        if(s.value.type == 0)
        {
            ui.data[ri->index(s.field)] = NULL;
        }
        else if(s.value.type == 1)
        {
            ui.data[ri->index(s.field)] = &s.value.v_int;
        }
        else if(s.value.type == 2)
        {
            ui.data[ri->index(s.field)] = &s.value.v_str;
        }
    }
}

void Database::update(std::string name)
{
    DataFile* df = getDataFile(name);
    if(df == NULL)
    {
        pWheres.clear();
        pSets.clear();
        return;
    }
    df->openFile();
    RecordInfo* ri = df->getRecordInfo();
    SearchInfo si;
    processWheresWithOneTable(si, ri, name);
    UpdateInfo ui;
    if(!processWheresWithOneTable(si, ri, name))
    {
        pWheres.clear();
        throw Exception("Conflict in where clauses.");
    }
    int cnt = df->update(si, ui);
    Print::print("Updated ").print(cnt).printLine(" records.");
    pWheres.clear();
    pSets.clear();
    df->closeFile();
}

void Database::remove(std::string name)
{
    DataFile* df = getDataFile(name);
    if(df == NULL)
    {
        pWheres.clear();
        return;
    }
    df->openFile();
    RecordInfo* ri = df->getRecordInfo();
    SearchInfo si;
    if(!processWheresWithOneTable(si, ri, name))
    {
        throw Exception("Conflict in where clauses.");
    }
    int cnt = df->remove(si);
    Print::print("Deleted ").print(cnt).printLine(" records.");
    pWheres.clear();
    df->closeFile();
}

void Database::selectOneTable(bool all)
{
    DataFile* df = getDataFile(pTables[0]);
    if(df == NULL)
    {
        pWheres.clear();
        pTables.clear();
        pCols.clear();
        return;
    }
    std::vector<bool> selected;
    df->openFile();
    df->printAllRecords();
    RecordInfo* ri = df->getRecordInfo();
    if(all)
    {
        selected.assign(ri->getFieldCount(), true);
    }
    else
    {
        bool flag = true;
        for(int i = 0; i < pCols.size(); i++)
        {
            if(pCols[i].table != "" &&
               pCols[i].table != pTables[0])
            {
                Print::printLine("Table " + pCols[i].table + " is not selected.");
                flag = false;
            }
            else if(ri->index(pCols[i].field) < 0)
            {
                Print::printLine("Table " + pTables[0] + " does not have field" + pCols[i].field + ".");
                flag = false;
            }
        }
        if(!flag)
        {
            pWheres.clear();
            pTables.clear();
            pCols.clear();
            df->closeFile();
            return;
        }
        selected.assign(ri->getFieldCount(), false);
        for(int i = 0; i < pCols.size(); i++)
        {
            selected[ri->index(pCols[i].field)] = true;
        }
    }
    SearchInfo si;
    if(!processWheresWithOneTable(si, ri, pTables[0]))
    {
        pWheres.clear();
        throw Exception("Conflict in where clauses.");
    }
    SelectResult sr;
    df->select(si, sr);
    printOneTableSelectResult(sr, selected, ri);
    pWheres.clear();
    pTables.clear();
    pCols.clear();
    df->closeFile();
}

void Database::selectMultiTable(bool all)
{

}

void Database::select(bool all)
{
    if(pTables.size() == 1)
    {
        selectOneTable(all);
    }
    else if(pTables.size() > 1)
    {
        selectMultiTable(all);
    }
    else
    {
        throw Exception("At least one table should be provided.");
    }
}

void Database::insert(std::string name_)
{
    DataFile* df = getDataFile(name_);
    if(df == NULL)
    {
        pValues.clear();
        pValueLists.clear();
        throw Exception("Cannot read table " + name_);
    }
    df->openFile();
    for(int i = 0; i < pValueLists.size(); i++)
    {
        std::vector<void*> data;
        data.push_back(NULL);
        for(int j = 0; j < pValueLists[i].size(); j++)
        {
            switch(pValueLists[i][j].type)
            {
            case 0:
                data.push_back(NULL);
                break;
            case 1:
                data.push_back(&(pValueLists[i][j].v_int));
                break;
            case 2:
                data.push_back(&(pValueLists[i][j].v_str));
                break;
            }
        }
        df->insert(data);
    }
    pValues.clear();
    pValueLists.clear();
    df->closeFile();
}

void Database::delete_path(const char* path)
{
    DIR *pDir = NULL;
    struct dirent *dmsg;
    char szFileName[128];
    char szFolderName[128];
    strcpy(szFolderName, path);
    strcat(szFolderName, "/%s");
    if((pDir = opendir(path)) != NULL)
    {
        while((dmsg = readdir(pDir)) != NULL)
        {
            if(strcmp(dmsg->d_name, ".") != 0 && strcmp(dmsg->d_name, "..") != 0)
            {
                sprintf(szFileName, szFolderName, dmsg->d_name);
                if(opendir(szFileName) != NULL){
                    delete_path(szFileName);
                }
                remove(szFileName);
            }
        }
        closedir(pDir);
    }
}

void Database::showTables()
{
    assert(databaseAvailable());
    DIR *pDir = NULL;
    struct dirent *dmsg;
    char szFileName[128];
    char szFolderName[128];
    strcpy(szFolderName, root.c_str());
    strcat(szFolderName, "/");
    strcat(szFolderName, name.c_str());
    if((pDir = opendir(szFolderName)) != NULL)
    {
        strcat(szFolderName, "/%s");
        Print::printLine("====================");
        Print::print("All tables of ").print(name).printLine(" are listed as below:");
        while((dmsg = readdir(pDir)) != NULL)
        {
            if(strcmp(dmsg->d_name, ".") != 0 && strcmp(dmsg->d_name, "..") != 0)
            {
                sprintf(szFileName, szFolderName, dmsg->d_name);
                std::string tmp = szFileName;
                if(opendir(szFileName) == NULL && tmp.substr(tmp.size() - 4, 4).compare(".dat") == 0){
                    std::string filename = std::string(dmsg->d_name);
                    Print::printLine(filename.substr(0, filename.size() - 4));
                }
            }
        }
        Print::printLine("====================");
        closedir(pDir);
    }
    else
    {
        Print::printLine("Current database is not available.");
    }
}

void Database::showDatabases()
{
    Print::printLine("====================");
    Print::printLine("All databases are listed as below:");
    DIR *pDir = NULL;
    struct dirent *dmsg;
    char szFileName[128];
    char szFolderName[128];
    strcpy(szFolderName, root.c_str());
    strcat(szFolderName, "/%s");
    if((pDir = opendir(root.c_str())) != NULL)
    {
        while((dmsg = readdir(pDir)) != NULL)
        {
            if(strcmp(dmsg->d_name, ".") != 0 && strcmp(dmsg->d_name, "..") != 0)
            {
                sprintf(szFileName, szFolderName, dmsg->d_name);
                std::string tmp = szFileName;
                if(opendir(szFileName) != NULL)
                {
                    Print::printLine(dmsg->d_name);
                }
            }
        }
        closedir(pDir);
    }
    Print::printLine("====================");
}

void Database::useDatabase(std::string name_)
{
    std::string path("");
    path += (root + "/" + name_);
    if(access(path.c_str(), F_OK) != 0)
    {
        throw Exception("Database does not exist.");
    }
    if (opendir(path.c_str()) == NULL)
    {
        throw Exception(" is not a Database.");
    }
    name = name_;
    data.clear();
    indexes.clear();
    Print::log("USING DATABASE ").logLine(name);
}

void Database::dropDatabase(std::string name_)
{
    if(name_ == name)
    {
        name = "";
    }
    std::string path("");
    path += (root + "/" + name_);
    if(access(path.c_str(), F_OK) != 0)
    {
        throw Exception("Database does not exist.");
    }
    delete_path(path.c_str());
    rmdir(path.c_str());
    Print::log("Removed directory ").logLine(path);
}

void Database::createTable(std::string name_)
{
    assert(databaseAvailable());
    std::string path("");
    path += (root + "/" + name + "/" + name_ + ".dat");
    if(access(path.c_str(), F_OK) == 0)
    {
        Print::printLine("File already exists.");
        return;
    }
    DataFile* df = new DataFile(path);
    data[name_] = df;
    df->createFile();
    df->openFile();
    df->addFields(pNames, pTypes, pNullables, pExtras);
    df->closeFile();
    pNames.clear();
    pTypes.clear();
    pNullables.clear();
    pExtras.clear();
    Print::log("Created file ").logLine(path);
}

void Database::describeTable(std::string name_)
{
    DataFile* df = getDataFile(name_);
    if(df == NULL)
    {
        return;
    }
    df->openFile();
    Print::printLine("TABLE " + name_ + "(");
    df->printRecordDescription();
    Print::printLine(")");
    df->closeFile();
}

DataFile* Database::getDataFile(std::string name_)
{
    assert(databaseAvailable());
    if(data.count(name_))
    {
        return data[name_];
    }
    std::string path("");
    path += (root + "/" + name + "/" + name_ + ".dat");
    if(access(path.c_str(), F_OK) != 0)
    {
        Print::printLine("Table " + name_ + " does not exist.");
        return NULL;
    }
    if(opendir(path.c_str()) != NULL)
    {
        Print::printLine(name_ + " is not a file.");
        return NULL;
    }
    DataFile* df = new DataFile(path);
    data[name_] = df;
    return df;
}

void Database::dropTable(std::string name_)
{
    DataFile* df = getDataFile(name_);
    if(df == NULL)
    {
        return;
    }
    df->deleteFile();
    std::string path("");
    path += (root + "/" + name + "/" + name_ + ".idx");
    delete_path(path.c_str());
    rmdir(path.c_str());
}

bool Database::databaseAvailable()
{
    if(name == "")
    {
        Print::printLine("No database being used.");
        return false;
    }
    std::string path("");
    path += (root + "/" + name + "/");
    if(access(path.c_str(), F_OK) != 0)
    {
        Print::printLine("Current database is not available.");
        return false;
    }
    return true;
}

Database* Database::getInstance()
{
    if(instance == NULL)
    {
        instance = new Database();
    }
    return instance;
}

void Database::_test()
{
    const char* sFile="test.sql";
    FILE* fp=fopen(sFile, "r");
    if(fp==NULL)
    {
        printf("cannot open %s\n", sFile);
        return;
    }
    extern FILE* yyin;
    yyin=fp;
    yyparse();
    fclose(fp);
}

void Database::test()
{
    getInstance()->_test();
}