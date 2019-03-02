#include "HashTableArray.h"
#include <QDebug>
#include "StringData.h"

HashTableArray::HashTableArray(int countKey) : HashTable(countKey)
{
    vetHash = new Hash *[countKey];
    for(int i = 0; i < countKey; i++)
        vetHash[i] = __null;
}

HashTableArray::~HashTableArray()
{
    clear();
}

void HashTableArray::insert(Hash *data)
{
    if(!data) return;

    int index;
    for(int i = 0; i < countKey; i++)
    {
        index = doubleHash(data->hash(), i);
        if(!vetHash[index])
        {
            vetHash[index] = data;
            return;
        }
    }

    //Overflow - redim vector//
    redmin();
    insert(data);
}

Hash *HashTableArray::search(int key)
{
    int index;
    for(int i = 0; i < countKey; i++)
    {
        index = doubleHash(key, i);
        if(vetHash[index])
        {
            if(vetHash[index]->hash() == key)
                return vetHash[index];
        }
        else
            i = countKey;
    }
    throw string("key not found.");
    return __null;
}

const Hash **HashTableArray::infoPrint(int &row, int &column) const
{
    const Hash **hashPrint;
    column = countKey;
    row = 1;
    hashPrint = (const Hash **) vetHash;
    return hashPrint;
}

int HashTableArray::doubleHash(int key, int i)
{
    return ((hash1(key) + i * hash3(key)) % countKey);
}

void HashTableArray::redmin()
{
    Hash **vetHashNew = new Hash *[countKey];
    int countKeyOld = countKey;
    countKey += countKey;

    for(int i = 0; i < countKeyOld; i++)
        vetHashNew[i] = vetHash[i];

    //delete vetHash;
    vetHash = new Hash *[countKey];
    for(int i = 0; i < countKey; i++)
        vetHash[i] = __null;

    for(int i = 0; i < countKeyOld; i++)
        insert(vetHashNew[i]);
    //delete vetHashNew;
}

void HashTableArray::clear()
{
    for(int i = 0; i < countKey; i++)
        if(vetHash[i]) delete vetHash[i];
    delete [] vetHash;
}
