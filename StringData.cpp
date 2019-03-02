#include "StringData.h"
#include <cmath>

StringData::StringData()
{
    count = 0;
}

StringData::StringData(string str)
{
    count = 1;
    this->str = str;
}

StringData::~StringData()
{

}

long long StringData::hash()
{
    int hash = 0;
    int size = str.length();
    for(int i = 0; i < size; i++)
        hash += (i + 1) * (int) str[i];
    return hash * countBit(str);
}

long long StringData::hash(string &str)
{
    long long hash = 0;
    int size = str.length();
    for(int i = 0; i < size; i++)
        hash += (i + 1) * (int) str[i];
    return hash * countBit(str);
}

int StringData::countBit(string &str)
{
    int count = 0;
    int length = str.length();
    for(int i = 0; i < length; i++)
        for(int j = 0; j < 8; j++)
            count += str[i] & (char) pow(2, j);
    return count;
}

void StringData::operator = (string str)
{
    this->str = str;
    count = 1;
}

bool StringData::operator == (StringData &str)
{
    return (this->count == str.getCount() && this->str == str.getStr());
}

bool StringData::operator > (StringData &str)
{
    if(this->count != str.getCount())
        return (this->count > str.getCount());
    return (this->str < str.getStr());
}

bool StringData::operator < (StringData &str)
{
    if(this->count != str.getCount())
        return (this->count < str.getCount());
    return (this->str > str.getStr());
}

void StringData::setStr(string str)
{
    this->str = str;
    count = 1;
}

string StringData::getStr() const
{
    return this->str;
}

string StringData::valueStr() const
{
    return this->str;
}

int StringData::getCount() const
{
    return this->count;
}

int StringData::valueCount() const
{
    return this->count;
}

void StringData::countPlusPlus()
{
    count++;
}
