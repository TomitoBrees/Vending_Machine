#include "CoinManager.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

CoinManager::CoinManager() {
    coinList = new LinkedList();
}

CoinManager::~CoinManager() {
    delete coinList;
}

std::vector<std::vector<int>> CoinManager::giveChange(int cents, std::vector<std::vector<int>> availableCoins)
{
    int i = 0;
    std::vector<std::vector<int>> finalChange = {{5000, 0}, {2000, 0}, {1000, 0}, {500,0}, {200, 0},
                                                 {100, 0}, {50, 0}, {20, 0}, {10, 0}, {5, 0}};
    while(cents > 0)
    {
        if (i == 10)
        {
            finalChange[0][0] = -1;
            return finalChange;
        }

        if(availableCoins[i][1] == 0)
        {
            i += 1;
        }

        else
        {
            if (cents - availableCoins[i][0] >= 0)
            {
                availableCoins[i][1] -= 1;
                cents -= availableCoins[i][0];
                finalChange[i][1] += 1;
            }
            else
            {
                i += 1;
            }
        }
    }
    return finalChange;
}

 //int main()
 //{
   //  int cents = 12500;
     //std::vector<std::vector<int>> availableCoins = {{5000, 1}, {2000, 4}, {1000, 4}, {500,5}, {200, 6},
      //                                               {100, 3}, {50, 0}, {20, 0}, {10, 0}, {5, 0}};
    //std::vector<std::vector<int>> finalChange = giveChange(cents, availableCoins);
    //std::cout << finalChange[0][1] << finalChange[1][1] << finalChange[2][1] << finalChange[3][1] << std::endl;
    //return EXIT_SUCCESS;
 //}





