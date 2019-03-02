#include "CountWord.h"
#include <fstream>
#include <string>
#include <algorithm>
#include "StringData.h"
#include "sort.h"

CountWord::CountWord(string filePath)
{
    fstream file(filePath.c_str(), ios::in);
    string strTemp;

    if(file.is_open())
    {
        while(!file.eof())
        {
            getline(file, strTemp);
            strText += strTemp + '\n';
        }
    }
    else
    {
        throw string("Error opening file.");
    }
    file.close();

    strTextOrg = strText;
    strText = removeAccented((char *) strText.c_str());
    transform(strText.begin(), strText.end(), strText.begin(), ::toupper);

    int intAux;
    for(int i = 1; i < 255; i++)
    {
        if(i == ' ')
            i++;
        else if(i == 'A')
            i += 26;

        do{
            intAux = strText.find(i);
            if(intAux != -1)
            {
                if(i == '\n')
                    strText.replace(intAux, 1, " ");
                else
                    strText.replace(intAux, 1, "");
            }
        } while (intAux != -1);
    }
    hashTable = 0;
}

CountWord::~CountWord()
{

}

char *CountWord::removeAccented(char *str) {
    char *p = str;
    while ((*p) != 0) {
        const char *tr = "AAAAAAECEEEEIIIIDNOOOOOx0UUUUYPsaaaaaaeceeeeiiiiOnooooo/0uuuuypy";
        unsigned char ch = (*p);
        if (ch >= 192) {
            (*p) = tr[ch - 192];
        }
        ++p;
    }
    return str;
}

string CountWord::getText()
{
    return this->strText;
}

string CountWord::getTextOrg()
{
    return this->strTextOrg;
}

void CountWord::countWord()
{
    if(hashTable) delete hashTable;
    hashTable = new HashTableArray(256);

    int length = strText.length();
    string strAux;
    StringData *strData;

    for(int i = 0; i < length; i++)
    {
        if(strText[i] != ' ')
            strAux += strText[i];
        else
        {
            if(strAux.length() > 1)
            {
                try{
                    strData = (StringData *) hashTable->search(StringData::hash(strAux));
                    strData->countPlusPlus();
                } catch (...) {
                    strData = new StringData(strAux);
                    hashTable->insert(strData);
                }
            }
            strAux = "";
        }
    }
}

StringData *CountWord::getWordCount(int &column)
{
    int row, indexDataCopy = 0;
    const StringData **datas = (const StringData **) hashTable->infoPrint(row, column);
    StringData *dataCopy = new StringData [column];

    for(int i = 0; i < column; i++)
    {
        if(datas[i])
        {
            dataCopy[indexDataCopy] = *datas[i];
            indexDataCopy++;
        }
    }
    column = indexDataCopy;
    heapSort(dataCopy, column);
    return dataCopy;
}
