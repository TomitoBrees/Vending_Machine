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
    // Validate command line arguments
    if (argc !=3) {
        std::cerr << "Error: invalid arguments" << std::endl;
        return EXIT_FAILURE;
    }
    // Create an instance of foodManager and CoinManager
    FoodManager* foodManager = new FoodManager();
    CoinManager* coinManager = new CoinManager();
    // Load data from food file and coins file as specified in arguments
    std::string food_file = std::string(argv[1]);
    std::string coin_file = std::string(argv[2]);
    foodManager->loadDataFromFoodFile(food_file);
    coinManager->loadDataFromCoinFile(coin_file);

    string s;
    bool quit = false;
    // Flag that detects EOF
    bool eofDetected = false;

    // Loop for main menu
    while (!quit) {
        while (!eofDetected) {
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

        // Check if EOF is reached
        if (std::cin.eof()) {
            // Set quit flag to exit the loop, set EOF flag to true
            quit = true;
            eofDetected = true;
        }

        if (!eofDetected) {
        if (s == "1") {
            std::cout << std::endl;
            foodManager->displayList();
            std::cout << std::endl;
        }
        else if (s == "2") {
            std::cout << "Purchase Meal" << std::endl;
            std::cout << "-------------" << std::endl;
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
            }
            else {
                // Display error message if the input entered is not valid or does not exist in the linked list
                std::cout << "Error: Invalid input. Please enter a valid ID (e.g. F0001)." << std::endl;
            }
        }
        else if (s == "3") {
            foodManager->saveDataToFile("new_food.dat");
            coinManager->saveDataToFile("new_coin.dat");
            delete foodManager;
            delete coinManager;
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
            } while (!validPriceInput);
            
            // Add the new food item to the linked list
            foodManager->addNewFoodItem(name, description, price);
            std::cout << "This item " << "'" << name << " - " << description << ".' has now been added to the food menu." << std::endl;
           }
          }
        }
        else if (s == "5") {
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
        else if (s == "6") {
            std::cout << std::endl;
            coinManager->displayBalance();
            std::cout << std::endl;
        }
        else if (s == "7") {
            quit = true;
            delete foodManager;
            delete coinManager;
            break;
        }
        else {
            std::cout << "Invalid input. Please enter a valid option." << std::endl;
        }
       }
       else {
        // Handle EOF being detected, exit the loop
        std::cerr << "End of input reached. Exiting..." << std::endl;
        quit = true;
       }
      }
    } 
    return EXIT_SUCCESS;
}