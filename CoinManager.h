#ifndef COIN_H
#define COIN_H

// CoinManager.h defines the coin structure for managing currency in the system.
#include <vector>
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

    std::vector<std::vector<int>> giveChange(int cents, std::vector<std::vector<int>> availableCoins);

private:

    // The food linked list handling everything related to the menu.
    LinkedList* coinList;
};

#endif // COIN_H
