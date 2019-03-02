#ifndef COUNTWORD_H
#define COUNTWORD_H

#include "HashTableArray.h"
#include "StringData.h"
#include <iostream>
using namespace std;

class CountWord
{
public:
    CountWord(string filePath);
    ~CountWord();

    char *removeAccented(char *str);
    string getText();
    string getTextOrg();

    void countWord();
    StringData *getWordCount(int &column);

private:
    string strText;
    string strTextOrg;
    HashTableArray *hashTable;
};

#endif // COUNTWORD_H
