#include"DataPage.h"

DataPage::DataPage(char* cache, int index, int pageID, bool parse, RecordInfo* ri):
    Page(cache, index, pageID), ri(ri)
{
    if(!parse)
    {
        setPageType(Type::DATA_PAGE);
        setNextSamePage(-1);
        setPrevSamePage(-1);
        setFirstAvailableByte(PAGE_CONTENT_OFFSET);
        records.clear();
    }
    else
    {
        int cur = PAGE_CONTENT_OFFSET, end = getFirstAvailableByte();
        while(cur < end)
        {
            records.push_back(new RecordSlot((*this)[cur], ri));
            cur += ri->getRecordLength();
        }
    }
}

void DataPage::print()
{
    Page::print();
    std::cout << "Record count:                         " << records.size() << std::endl;
    for(int i = 0; i < records.size(); i++)
    {
        records[i]->print();
    }
}

void DataPage::read(int i, std::vector<void*>& data)
{
    records[i]->read(data);
}

int DataPage::update(SearchInfo& si, UpdateInfo& ui)
{
    int cnt = 0;
    for(int i = 0; i < records.size(); i++)
    {
        if(!records[i]->checkNull(si.nulls))
        {
            continue;
        }
        bool flag = true;
        for(int j = 0; j < 6; j++)
        {
            if(!records[i]->checkValue(si.values[j], j) || !records[i]->checkFields(si.fields[j], j))
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            records[i]->update(ui);
            cnt++;
        }
    }
    return cnt;
}

int DataPage::remove(SearchInfo& si)
{
    std::vector<bool> removed;
    removed.assign(records.size(), false);
    int cnt = 0;
    for(int i = 0; i < records.size(); i++)
    {
        if(!records[i]->checkNull(si.nulls))
        {
            continue;
        }
        bool flag = true;
        for(int j = 0; j < 6; j++)
        {
            if(!records[i]->checkValue(si.values[j], j) || !records[i]->checkFields(si.fields[j], j))
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            cnt++;
            removed[i] = true;
        }
    }
    if(cnt == 0)
    {
        return 0;
    }
    int head = 0, tail = records.size() - 1;
    while(head < tail)
    {
        while(!removed[head] && head < tail)
        {
            head++;
        }
        if(head >= tail)
        {
            break;
        }
        while(removed[tail] && head < tail)
        {
            tail--;
        }
        if(head >= tail)
        {
            break;
        }
        RecordSlot::copy(records[tail], records[head], ri->getRecordLength());
        head++;
        tail--;
    }
    setFirstAvailableByte(getFirstAvailableByte() - cnt * ri->getRecordLength());
    int cur = PAGE_CONTENT_OFFSET, end = getFirstAvailableByte();
    records.clear();
    while(cur < end)
    {
        records.push_back(new RecordSlot((*this)[cur], ri));
        cur += ri->getRecordLength();
    }
    return cnt;
}

void DataPage::select(SearchInfo& si, SelectResult& sr)
{
    for(int i = 0; i < records.size(); i++)
    {
        if(records[i]->check(si))
        {
            sr.results.push_back(PAGE_SIZE * pageID + i);
        }
    }
}

int DataPage::insert(std::vector<void*>& data)
{
    int cur = getFirstAvailableByte();
    RecordSlot* slot = new RecordSlot((*this)[cur], ri);
    slot->write(data);
    cur += ri->getRecordLength();
    setFirstAvailableByte(cur);
    records.push_back(slot);
    if(cur + ri->getRecordLength() < PAGE_SIZE)
    {
        return SUCCEED;
    }
    return PAGE_FULL;
}
