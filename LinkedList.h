#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"


class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    // more functions to be added perhaps...

    // Display the menu items/linked list
    void displayList();

    // Remove item from the menu linked list
    void removeMenuItem(int index);

    // Add item to the back of the menu linked list
    void addBackMenuItem(FoodItem* foodItem);

    // Save state of user upon exiting the program

private:
    // the beginning of the list
    Node* head;
  
    // how many nodes are there in the list?
    unsigned count;
};

#endif  // LINKEDLIST_H


