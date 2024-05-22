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

    // Add an item to the food liked list.
    void addBackCoin(Coin* coin);

    void addFront(Coin* coin);

    // Load the data from the coin file into the linked list.
    void loadDataFromCoinFile(const std::string& fileName);

    Denomination intToDenomination(int value);

    int denominationToInt(Denomination value);

    std::string intTabulation(int value, int tab);

    float findValue(int denomination, unsigned int quantity);

    int findSize(int value);

    void displayBalance();

private:

    // The food linked list handling everything related to the menu.
    LinkedList* coinListAscending;
    LinkedList* coinListDescending;
};

#endif // COIN_H
