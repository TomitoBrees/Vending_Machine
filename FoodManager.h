#ifndef FOODMANAGER_H
#define FOODMANAGER_H

#include <iostream>
#include <fstream>
#include <sstream>

#include "string"
#include "LinkedList.h"

class FoodManager {
public:

    //Constructor
    FoodManager();

    //Destructor
    ~FoodManager();

    //Get the item at the given index in the food linked list.
    FoodItem* get(int index);

    //Display the food linked list.
    void displayList();

    //Remove an item from the food linked list.
    void removeMenuItem(FoodItem* foodItem);

    // Add an item to the food liked list.
    void addBackMenuItem(FoodItem* foodItem);

    // Load the data from the food file into the linked list.
    void loadDataFromFoodFile(const std::string& fileName);

    // Save the food linked list data to the wanted file.
    void saveDataToFile(const std::string& fileName);

    // Get the food Item with the given ID.
    FoodItem* findFoodItemByID(const std::string& id);

    // Generate the next available id
    std::string generateNextID();

    // Add a new food item to the food menu linked list
    void addNewFoodItem(const std::string& name, const std::string& description, int price);

    // Decrement the default food stock level by 1
    void decrementStockLevel(FoodItem* foodItem);

private:

    // The food linked list handling everything related to the menu.
    LinkedList* foodList;
};



#endif //FOODMANAGER_H
