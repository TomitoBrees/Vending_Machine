#ifndef COINMANAGER_H
#define COINMANAGER_H

// CoinManager.h defines the coin structure for managing currency in the system.
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <iomanip>

#include "LinkedList.h"

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

    // Increment the count of a coin
    void addCoin(Denomination denomination);

    void removeCoin(Denomination denomination);


    // Load the data from the coin file into the linked list.
    void loadDataFromCoinFile(const std::string& fileName);

    void saveDataToFile(const std::string& fileName);

    Denomination intToDenomination(int value);

    int denominationToInt(Denomination value);

    std::string intTabulation(int value, int tab);

    float findValue(int denomination, unsigned int quantity);

    int findSize(int value);

    void displayBalance();

    void buyItem(int toPay);

private:
    std::vector<Coin*>* coinVector;
};

#endif // COIN_H
