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


// represents a coin type stored in the cash register, perhaps. Each denomination
// will have exactly one of these in the cash register.
class CoinManager
{
public:
    //Constructor
    CoinManager();

    //Destructor
    ~CoinManager();

    // Increment the count of a coin.
    void addCoin(Denomination denomination);

    // Decrement the count of a coin.
    void removeCoin(Denomination denomination);

    // Load the data from the coin file into the linked list.
    void loadDataFromCoinFile(const std::string& fileName);

    // Save the coins data into a file.
    void saveDataToFile(const std::string& fileName);

    // Transforming an integer to its denomination.
    Denomination intToDenomination(int value);

    // Transforming a denomination to its integer value.
    int denominationToInt(Denomination value);

    // Giving the right string to print in displayBalance() with the good tabulation.
    std::string intTabulation(int value, int tab);

    // Multiplying the denomination to the quantity to get the value in displayBalance().
    float findValue(int denomination, unsigned int quantity);

    // Return the size of an integer.
    int findSize(int value);

    // Display the balance as it should.
    void displayBalance();

    // Buy an item with the right amount to pay.
    void buyItem(int toPay);

private:
    std::vector<Coin*>* coinVector;
};

#endif // COIN_H
