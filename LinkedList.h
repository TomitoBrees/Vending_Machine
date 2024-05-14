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

    // Get the item at the given index in food menu linked list
    FoodItem* get(int index);

    // Get item at the given index in coin linked list
    Coin* getCoin(int value);

    // Remove item from the menu linked list
    void removeMenuItem(FoodItem* foodItem);

    // Add item to the back of the menu linked list
    void addBackMenuItem(FoodItem* foodItem);

    // Add item to the front of the menu linked list
    void addFrontMenuItem(FoodItem* foodItem);

    // Save state of user upon exiting the program

    // Read data from foods.dat file and populate a linked list
    void loadDataFromFoodFile(const std::string& fileName);

    // Return a food item from the linked list by its ID
    FoodItem* findFoodItemByID(const std::string& id);

private:
    // the beginning of the food menu list
    Node* head;
};

#endif  // LINKEDLIST_H


