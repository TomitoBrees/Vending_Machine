// Concrete Command class that handles the logic for aborting the program without saving

#ifndef ABORTCOMMAND_H
#define ABORTCOMMAND_H
#include "Command.h"
#include "FoodManager.h"
#include "CoinManager.h"
#include "LinkedList.h"
#include <cstdlib>
#include <iostream>

class AbortCommand : public Command {
private:
    FoodManager* foodManager;
    CoinManager* coinManager;
public:
    AbortCommand(FoodManager* fm, CoinManager* cm) : foodManager(fm), coinManager(cm) {}
    void execute() override {
        std::exit(EXIT_SUCCESS);
    }
};

#endif // ABORTCOMMAND_H