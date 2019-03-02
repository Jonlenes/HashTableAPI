#include "HashTableLinked.h"
using namespace std;

HashTableLinked::HashTableLinked(int countKey) : HashTable(countKey)
{
    vetKeys = new Node* [countKey];
    for(int i = 0; i < countKey; i++)
        vetKeys[i] = nullptr;
    whatHash = rand() % 2;
}

HashTableLinked::~HashTableLinked()
{
    delete [] vetKeys;
}

void HashTableLinked::insert(Hash *data)
{
    int index = hash(data->hash());
    Node *noInsert = vetKeys[index];

    if(!noInsert)
    {
        noInsert = new Node(data);
        vetKeys[index] = noInsert;
    }
    else
    {
        while (noInsert->getNext()) {
            noInsert = noInsert->getNext();
        }
        Node *noNew = new Node(data);
        noNew->setPrevius(noInsert);
        noInsert->setNext(noNew);
    }
}

void HashTableLinked::remove(int key)
{
    int index = hash(key);
    Node *no = vetKeys[index];


    while (no && no->getData()->hash() != key) {
        no = no->getNext();
    }
    if(no)
    {
        Node *prev = no->getPrevius();
        Node *next = no->getNext();

        if(prev && next) {
            prev->setNext(no->getNext());
            next->setPrevius(no->getPrevius());
        } else if(prev) {
            prev->setNext(__null);
        } else if(next) {
            next->setPrevius(__null);
            vetKeys[index] = next;
        } else
            vetKeys[index] = __null;
        delete no;
    }
    else
        throw string("key not found");
}

void HashTableLinked::remove(Hash *data)
{
    remove(data->hash());
}

Hash *HashTableLinked::search(int key)
{
    int index = hash(key);
    Node *no = vetKeys[index];
    while(no && no->getData()->hash() != key)
    {
        no = no->getNext();
    }
    if(no)
        return no->getData();
    else
        throw string("key not found");
}

int HashTableLinked::hash(long long int key)
{
    switch (whatHash) {
    case 0:
        return hash1(key);
    case 1:
        return hash2(key);
    default:
        break;
    };
    return -1;
}

int **HashTableLinked::matPrint(int &row, int &column)
{
    int **matPrint = new int*[countKey];
    int count = 0;
    int countMax = -1;
    Node *noAux;

    for(int i = 0; i < countKey; i++)
    {
        noAux = vetKeys[i];
        while (noAux) {
            noAux = noAux->getNext();
            count++;
        }
        if(count > countMax)
            countMax = count;
        count = 0;
    }
    for(int i = 0; i < countKey; i++)
    {
        matPrint[i] = new int[countMax];
        for(int j = 0; j < countMax; j++)
            matPrint[i][j] = 0;
    }

    for(int i = 0; i < countKey; i++)
    {
        noAux = vetKeys[i];
        for (int j = 0; noAux; j++) {
            matPrint[i][j] = noAux->getData()->hash();
            noAux = noAux->getNext();
        }
    }
    row = countKey;
    column = countMax;

    return matPrint;
}
