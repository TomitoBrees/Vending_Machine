#ifndef REMOVEFOODITEMCOMMAND_H
#define REMOVEFOODITEMCOMMAND_H
#include <iostream>
#include <limits>
#include "Command.h"
#include "FoodManager.h"

class RemoveFoodItemCommand : public Command {
private:
    FoodManager* foodManager;
public:
    // Constructor
    RemoveFoodItemCommand(FoodManager* fm) : foodManager(fm) {}
    // Function that executes the logic for removing a food item from the menu
    void execute() override {
        std::cout << "Enter the food id of the food to remove from the menu: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::string idToRemove;
            std::cin >> idToRemove;

            // Find the food item in the linked list
            FoodItem* itemToRemove = foodManager->findFoodItemByID(idToRemove);

            if (itemToRemove) {
                // If the food item with the entered id exists, remove the food item
                foodManager->removeMenuItem(itemToRemove);
            }
            else {
                std::cout << "Food item with id " << idToRemove << " not found." << std::endl;
            }
    }
};

#endif // REMOVEFOODITEMCOMMAND_H