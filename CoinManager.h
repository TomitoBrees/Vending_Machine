#ifndef COINMANAGER_H
#define COINMANAGER_H

// CoinManager.h defines the coin structure for managing currency in the system.
#include <vector>
#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "string"

#define DELIM ","  // delimiter


// represents a coin type stored in the cash register perhaps. Each demonination
// will have exactly one of these in the cash register.
class CoinManager
{
public:
    //Constructor
    CoinManager();

    //Destructor
    ~CoinManager();

    //Remove a coin from the coinList.
    void removeQuantityToCoin(Coin* coin, int quantity);

    //Add a coin from the coinList.
    void addQuantityToCoin(Coin* coin, int quantity);

    // Add an item to the food liked list.
    void addBackCoin(Coin* coin);

    // Load the data from the coin file into the linked list.
    void loadDataFromCoinFile(const std::string& fileName);

    Denomination intToDenomination(int value);

    //Return a 2D array representing the necessary change
    std::vector<std::vector<int>> giveChange(int cents, std::vector<std::vector<int>> availableCoins);

private:

    // The food linked list handling everything related to the menu.
    LinkedList* coinList;
};

#endif // COIN_H
