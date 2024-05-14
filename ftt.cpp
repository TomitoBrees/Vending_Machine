#include <iostream>
#include "LinkedList.h"

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
    /*Create an instance of LinkedList for the food menu,
      load data from foods.dat file into the linked list,
      reset the stock levels to the default number*/
    LinkedList foodMenu;
    string s;
    bool quit = false;

    // Loop for main menu
    while (!quit) {
        // Display main menu
        std::cout << "Main Menu:" << std::endl;
        std::cout << "1. Display Meal Options" << std::endl;
        std::cout << "2. Purchase Meal" << std::endl;
        std::cout << "3. Save and Exit" << std::endl;
        std::cout << "Adminitstrator-Only Menu:" << std::endl;
        std::cout << "4. Add Food" << std::endl;
        std::cout << "5. Remove Food" << std::endl;
        std::cout << "6. Dislay Balance" << std::endl;
        std::cout << "7. Abort Program" << std::endl;
        std::cout << "Select your option (1-7) :" << std::endl;
        // Read input (s) from user
        std::cin >> s;

        if (s == "1") {
          foodMenu.displayList();
        }
        else if (s == "2") {

        }
        else if (s == "3") {

        }
        else if (s == "4") {

        }
        else if (s == "5") {

        }
        else if (s == "6") {

        }
        else if (s == "7") {
            quit = true;
        }
        else {
            std::cout << "Invalid input. Please enter a valid option." << std::endl;
        }
    }
    
    return EXIT_SUCCESS;
}

