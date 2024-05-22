#include <iostream>
#include <limits>
#include "LinkedList.h"
#include "FoodManager.h"
#include "CoinManager.h"

using std::string;
/**
 * manages the running of the program, initialises data structures, loads
 * data, display the main menu, and handles the processing of options. 
 * Make sure free memory and close all files before exiting the program.
 **/
int main(int argc, char **argv)
{
    /* validate command line arguments */
    // TODO
    // Create an instance of foodManager and CoinManager
    FoodManager* foodManager = new FoodManager();
    CoinManager* coinManager = new CoinManager();
    // If the user provides 3 arguments to run the program
    if (argc == 3) {
    // Load data from food file and coins file as specified in arguments
    std::string food_file = std::string(argv[1]);
    std::string coin_file = std::string(argv[2]);
    foodManager->loadDataFromFoodFile(food_file);
    coinManager->loadDataFromCoinFile(coin_file);
    }
    else {
        // Invlaid number of arguments
        std::cerr << "Error: invalid arguments" << std::endl;
    }

    string s;
    bool quit = false;

    // Loop for main menu
    while (!quit) {
        // Display main menu
        std::cout << "Main Menu:" << std::endl;
        std::cout << "\t1. Display Meal Options" << std::endl;
        std::cout << "\t2. Purchase Meal" << std::endl;
        std::cout << "\t3. Save and Exit" << std::endl;
        std::cout << "Administrator-Only Menu:" << std::endl;
        std::cout << "\t4. Add Food" << std::endl;
        std::cout << "\t5. Remove Food" << std::endl;
        std::cout << "\t6. Display Balance" << std::endl;
        std::cout << "\t7. Abort Program" << std::endl;
        std::cout << "Select your option (1-7) : " ;
        // Read input (s) from user
        std::cin >> s;

        if (s == "1") {
            std::cout << std::endl;
            foodManager->displayList();
            std::cout << std::endl;
        }
        else if (s == "2") {
            std::cout << "Purchase Meal" << std::endl;
            std::cout << "-------------" << std::endl;
            std::cout << "Please enter the ID of the food you want to purchase: ";
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
            }
            else {
                // Display error message if the input entered is not valid or does not exist in the linked list
                std::cout << "Error: Invalid input. Please enter a valid ID (e.g. F0001)." << std::endl;
            }
        }
        else if (s == "3") {
            foodManager->saveDataToFile("test.dat");
            delete foodManager;
            return EXIT_SUCCESS;
        }
        else if (s == "4") {
            // Determine the next available id and print it
            std::string nextID = foodManager->generateNextID();
            std::cout << "This new meal item will have the item id of " << nextID << std::endl;

            // Prompt the user for the name, description
            std::string name, description;
            int price;
            std::cout << "Enter the item name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Enter the food description: ";
            std::getline(std::cin, description);

            // Add new price if the user enters a valid integer
            bool validInput;
            do {
            std::cout << "Enter the price for this item (in cents): ";
            std::cin >> price;
            validInput = !std::cin.fail();
            if (!validInput) {
                // Clear the error flag on cin
                std::cin.clear();
                // Ignore the rest of the input until a newline
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid price. Please enter a valid price in cents." << std::endl;
              }
            } while (!validInput);
            
            // Add the new food item to the linked list
            foodManager->addNewFoodItem(name, description, price);
            std::cout << "This item " << "'" << name << " - " << description << ".' has now been added to the food menu." << std::endl;
        }
        else if (s == "5") {
            std::cout << "Enter the food id of the food to remove from the menu: ";

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
        else if (s == "6") {

        }
        else if (s == "7") {
            quit = true;
            delete foodManager;
            delete coinManager;
        }
        else {
            std::cout << "Invalid input. Please enter a valid option." << std::endl;
        }
    }
    
    return EXIT_SUCCESS;
}

