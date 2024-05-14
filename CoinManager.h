#ifndef COIN_H
#define COIN_H

// CoinManager.h defines the coin structure for managing currency in the system.
#include <vector>

#define DELIM ","  // delimiter


// represents a coin type stored in the cash register perhaps. Each demonination
// will have exactly one of these in the cash register.
class CoinManager
{
public:

    std::vector<std::vector<int>> giveChange(int cents, std::vector<std::vector<int>> availableCoins);
};

#endif // COIN_H
