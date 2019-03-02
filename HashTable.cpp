#include "HashTable.h"

HashTable::HashTable(int countKey)
{
    this->countKey = countKey;
    a = float((sqrt(5) - 1) / 2);
    srand( static_cast<unsigned int>(time(nullptr)) );
}

HashTable::~HashTable()
{

}

bool HashTable::search(Hash *)
{
    try
    {
        //printf("Loucura man")
        //search(data->hash());
        return true;
    }
    catch(...)
    {
        return false;
    }
}

int HashTable::hash1(int key)
{
    return (key % countKey);
}

int HashTable::hash2(int key)
{
    return int(countKey * (double(key * a) - int(key * a)));
}

int HashTable::hash3(int key)
{
    return (1 + (key % (countKey - 1)));
}

void HashTable::remove(Hash *)
{
    throw string("this method is not implemented by the derived class.");
}

void HashTable::remove(int)
{
    throw string("this method is not implemented by the derived class.");
}
