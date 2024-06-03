// Concrete command class that handles the logic for purchasing a food item

#ifndef PURCHASINGCOMMAND_H
#define PURCHASINGCOMMAND_H
#include <iostream>
#include <limits>
#include "Command.h"
#include "FoodManager.h"
#include "CoinManager.h"

class PurchasingCommand : public Command {
private:
    FoodManager* foodManager;
    CoinManager* coinManager;
public:
    // Constructor
    PurchasingCommand(FoodManager* fm, CoinManager* cm) : foodManager(fm), coinManager(cm) {}
    // Function with the logic for purchasing a food item
    void execute() override {
        bool validIdEntered = false;
        bool cancelPurchase = false;
        std::cout << "Purchase Meal" << std::endl;
        std::cout << "-------------" << std::endl;

        while (!validIdEntered && !cancelPurchase) {
        std::cout << "Please enter the ID of the food you want to purchase: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::string foodID;
        std::cin >> foodID;
        // Find the food item in the linked list
        FoodItem* desiredItem = foodManager->findFoodItemByID(foodID);
        if (desiredItem) {
            // Find the food item and display the details
            std::cout << "You have selected " << "'" << desiredItem->name << " - " << desiredItem->description << "'. "
                      << "This will cost you $ " << desiredItem->price->displayPrice() << std::endl;
            std::cout << "Please hand over the money - type in the value of each note/coin in cents." << std::endl;
            std::cout << "Please enter ctrl-D or enter on a new line to cancel this purchase." << std::endl;
            coinManager->buyItem(desiredItem->price->priceToInt());

            // Check for EOF or empty line to cancel the purchase
            if (std::cin.eof() || foodID.empty()) {
                cancelPurchase = true;
            }
                // Set validIdEntered to true to exit the loop if not cancelled
            validIdEntered = !cancelPurchase;
        }
        else {
            // Display error message if the input entered is not valid or does not exist in the linked list
            std::cout << "Error: Invalid input. Please enter a valid ID (e.g. F0001)." << std::endl;
        }
      }
    }
};

#endif // PURCHASINGCOMMAND_H