// Concrete class that handles the logic for displaying the current coin balance

#ifndef DISPLAYCOINSCOMMAND_H
#define DISPLAYCOINSCOMMAND_H
#include "Command.h"
#include "CoinManager.h"

class DisplayCoinsCommand: public Command {
private:
    CoinManager* coinManager;
public:
    // Constructor
    DisplayCoinsCommand(CoinManager* cm) : coinManager(cm) {}
    // Execute logic for displaying the coin balance
    void execute() override {
        coinManager->displayBalance();
    }
};

#endif // DISPLAYCOINSCOMMAND_H