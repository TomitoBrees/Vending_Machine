#ifndef ADDNEWFOODITEMCOMMAND_H
#define ADDNEWFOODITEMCOMMAND_H
#include <iostream>
#include <limits>
#include "Command.h"
#include "FoodManager.h"
#include "CoinManager.h"

class AddNewFoodItemCommand : public Command {
private:
    FoodManager* foodManager;
    CoinManager* coinManager;
public:
    // Constructor
    AddNewFoodItemCommand(FoodManager* fm, CoinManager* cm) : foodManager(fm), coinManager(cm) {}
    // Function with logic for adding a new food item to the menu
    void execute() override {
        // Determine the next available id and print it
            std::string nextID = foodManager->generateNextID();
            std::cout << "This new meal item will have the item id of " << nextID << std::endl;

            // Prompt the user for the name, description
            std::string name, description;
            int price;
            std::cout << "Enter the item name: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (std::getline(std::cin, name)) {
                std::cout << "Enter the food description: ";
                if (std::getline(std::cin, description)) {
            // Add new price if the user enters a valid integer
            bool validPriceInput = false;
            do {
            std::cout << "Enter the price for this item (in cents): ";
            std::cin >> price;
            validPriceInput = !std::cin.fail();
            if (!validPriceInput) {
                // Clear the error flag on cin
                std::cin.clear();
                // Ignore the rest of the input until a newline
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid price. Please enter a valid price in cents." << std::endl;
              }
              else {
                validPriceInput = true;
              }
            } while (!validPriceInput);
            
            // Add the new food item to the linked list
            foodManager->addNewFoodItem(name, description, price);
            std::cout << "This item " << "'" << name << " - " << description << ".' has now been added to the food menu." << std::endl;
          }
       }
    }
};

#endif // ADDNEWFOODITEMCOMMAND_H