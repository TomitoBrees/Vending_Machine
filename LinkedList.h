#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"


class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    // more functions to be added perhaps...

    // Get the size of the linked list
    int size();

    // Display the menu items/linked list
    void displayList();

    // Get the item at the given index
    FoodItem* get(int index);

    // Remove item from the menu linked list
    void removeMenuItem(FoodItem* foodItem);

    // Add item to the back of the menu linked list
    void addBackMenuItem(FoodItem* foodItem);

    // Save state of user upon exiting the program

private:
    // the beginning of the list
    Node* head;
};

#endif  // LINKEDLIST_H


