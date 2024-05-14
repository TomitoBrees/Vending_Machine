#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

// Implementation of linked list in our program.
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    // Get the size of the linked list
    int size();

    Node* head;
};

#endif  // LINKEDLIST_H


