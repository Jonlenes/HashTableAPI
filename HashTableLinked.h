#ifndef HASHTABLELINKED_H
#define HASHTABLELINKED_H

#include "Node.h"
#include "HashTable.h"
using namespace std;

class HashTableLinked : protected HashTable
{
public:
    HashTableLinked(int countKey);
    ~HashTableLinked();

    void insert(Hash *data);
    void remove(int key);
    void remove(Hash *data);
    Hash *search(int key);
    bool *search(Hash *key);
    int **matPrint(int &row, int &column);

private:
    Node **vetKeys;
    int whatHash;
    int hash(long long key);
};
#endif // HASHTABLE_H
