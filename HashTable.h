#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Hash.h"
#include <cmath>
#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;

class HashTable
{
public:
    HashTable(int countKey);
    virtual ~HashTable();

    virtual void insert(Hash *data) = 0;
    virtual void remove(int key);
    virtual void remove(Hash *data);
    virtual Hash *search(int key) = 0; 
    virtual const Hash **infoPrint(int &row, int &column) const = 0;

    /*esses foram implementadas aqui mesmo,
     *pois é comum a qualquer implementação*/
    bool search(Hash *key);
    int hash1(int key);
    int hash2(int key);
    int hash3(int key);

protected:
    int countKey;
    float a;
};

#endif // HASHTABLE_H
