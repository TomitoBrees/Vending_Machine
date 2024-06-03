// Concrete class that handles the logic for displaying the food menu

#ifndef DISPLAYFOODCOMMAND_H
#define DISPLAYFOODCOMMAND_H
#include "Command.h"
#include "FoodManager.h"

class DisplayFoodCommand: public Command {
private:
    FoodManager* foodManager;
public:
    DisplayFoodCommand(FoodManager* fm): foodManager(fm) {}
    void execute() override {
        foodManager->displayList();
    }
};

#endif // DISPLAYFOODCOMMAND_H