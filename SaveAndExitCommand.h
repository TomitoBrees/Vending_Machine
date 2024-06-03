// Concrete Command class that handles the logic for saving and exiting the program

#ifndef SAVEANDEXITCOMMAND_H
#define SAVEANDEXITCOMMADN_H
#include "Command.h"
#include "FoodManager.h"
#include "CoinManager.h"
#include "LinkedList.h"
#include <iostream>

class SaveAndExitCommand : public Command {
private:
    FoodManager* foodManager;
    CoinManager* coinManager;
public:
    // Constructor
    SaveAndExitCommand(FoodManager* fm, CoinManager* cm) : foodManager(fm), coinManager(cm) {}
    // Function that executes the logic for saving and exiting the program
    void execute() override {
        foodManager->saveDataToFile("new_food.dat");
        coinManager->saveDataToFile("new_coin.dat");
    }
};

#endif // SAVEANDEXITCOMMAND_H