#ifndef NODE_H
#define NODE_H
#include "Hash.h"


class Node
{
public:
    Node(Hash * data);
    ~Node();

    Hash *getData();
    Node *getNext();
    Node *getPrevius();
    void setNext(Node *no);
    void setPrevius(Node *no);

private:
    Hash *data;
    Node *next;
    Node *prev;
};

#endif // NODE_H
