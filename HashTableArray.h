#ifndef HASHTABLEARRAY_H
#define HASHTABLEARRAY_H

#include "HashTable.h"

class HashTableArray : public HashTable
{
public:
    HashTableArray(int countKey);
    ~HashTableArray();

    void insert(Hash *data);
    Hash *search(int key);
    const Hash **infoPrint(int &row, int &column) const;

private:
    Hash **vetHash;
    int doubleHash(int key, int i);
    void redmin();
    void clear();
};

#endif // HASHTABLEARRAY_H
