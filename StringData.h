#ifndef STRING_H
#define STRING_H

#include <string>
#include "Hash.h"
using namespace std;

class StringData : public Hash
{
public:
    StringData();
    StringData(string str);
    ~StringData();

    long long hash();
    static long long hash(string &);
    static int countBit(string &str);
    void operator = (string str);
    bool operator == (StringData &str);
    bool operator > (StringData &str);
    bool operator < (StringData &str);
    void setStr(string str);
    string getStr() const;
    string valueStr() const;
    int getCount() const;
    int valueCount() const;
    void countPlusPlus();

private:
    string str;
    int count;
};

#endif // STRING_H
