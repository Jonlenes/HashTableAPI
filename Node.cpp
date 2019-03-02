#include "Node.h"

Node::Node(Hash *data)
{
    this->data = data;
    next = __null;
    prev = __null;
}

Node::~Node()
{

}

Hash *Node::getData()
{
    return this->data;
}

Node *Node::getNext()
{
    return this->next;
}

Node *Node::getPrevius()
{
    return this->prev;
}

void Node::setNext(Node *no)
{
    this->next = no;
}

void Node::setPrevius(Node *no)
{
    this->prev = no;
}
