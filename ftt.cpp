#include <iostream>
#include <limits>
#include <vector>
#include <functional>
#include "LinkedList.h"
#include "FoodManager.h"
#include "CoinManager.h"
#include "DisplayFoodCommand.h"
#include "PurchasingCommand.h"
#include "SaveAndExitCommand.h"
#include "AddNewFoodItemCommand.h"
#include "RemoveFoodItemCommand.h"
#include "DisplayCoinsCommand.h"
#include "AbortCommand.h"

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

    bool quit = false;
    // Create instances of the concrete Command classes and store them in a map
    std::vector<std::function<void()>> commands = {
        [&foodManager]() { DisplayFoodCommand(foodManager).execute(); },
        [&foodManager, &coinManager]() { PurchasingCommand(foodManager, coinManager).execute(); },
        [&foodManager, &coinManager]() { SaveAndExitCommand(foodManager, coinManager).execute(); },
        [&foodManager, &coinManager]() { AddNewFoodItemCommand(foodManager, coinManager).execute(); },
        [&foodManager]() { RemoveFoodItemCommand(foodManager).execute(); },
        [&coinManager]() { DisplayCoinsCommand(coinManager).execute(); },
        [&foodManager, &coinManager]() { AbortCommand(foodManager, coinManager).execute(); }
    };

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
        std::cout << "Select your option (1-7): " ;
        // Read input (option) from user
        int option;
        std::cin >> option;

        // Check if EOF is reached
        if (std::cin.eof()) {
            // Set quit flag to exit the loop, set EOF flag to true
            quit = true;

        }
        // Handle any invalid input from the user
        if (std::cin.fail() || option < 1 || option > 7) {
            std::cerr << "Invalid input. Please enter one of the valid options (1-7)." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            // Call the concrete Command classes in the vector from user input
            commands[option - 1]();
      }
    }
    delete foodManager;
    delete coinManager; 
    return EXIT_SUCCESS;
}