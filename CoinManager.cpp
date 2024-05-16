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

void CoinManager::addBackCoin(Coin* coin) {
    Node* current = coinList->head;

    if(!coinList->head) {
        coinList->head = new Node(coin, COIN);
        return;
    }

    while(current->next) {
        current = current->next;
    }

    current->next = new Node(coin, COIN);
}

Denomination CoinManager::intToDenomination(int value) {
    Denomination result;
    if (value == 5000) {
        result = FIFTY_DOLLARS;
    }
    else if (value == 2000) {
        result = TWENTY_DOLLARS;
    }
    else if (value == 1000) {
        result = TEN_DOLLARS;
    }
    else if (value == 500) {
        result = FIVE_DOLLARS;
    }
    else if (value == 200) {
        result = TWO_DOLLARS;
    }
    else if (value == 100) {
        result = ONE_DOLLAR;
    }
    else if (value == 50) {
        result = FIFTY_CENTS;
    }
    else if (value == 20) {
        result = TWENTY_CENTS;
    }
    else if (value == 10) {
        result = TEN_CENTS;
    }
    else {
        result = FIVE_CENTS;
    }
    return result;
}

void CoinManager::loadDataFromCoinFile(const std::string& fileName) {
    try {
        std::ifstream file(fileName);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                std::istringstream iss (line);
                std::string denomination, quantity;
                if (std::getline(iss, denomination, ',') &&
                    std::getline(iss, quantity)) {

                    // Convert coin value from string to double
                    int value = std::stoi(denomination);
                    unsigned int _quantity = std::stoi(quantity);
                    // Create Price object
                    Denomination _coin = intToDenomination(value);
                    Coin* coin = new Coin(_coin, _quantity);

                    addBackCoin(coin);
                }
            }
            // Close the file
            file.close();
        }
        else {
            // Error message if unable to open file
            throw std::runtime_error("Unable to open file: " + fileName);
        }
    }
    catch (const std::exception& e) {
        // Catch any errors while loading the data into the linked list and display and error message
        std::cerr << "Error loading data from " << fileName << ": " << e.what() << std::endl;
    }
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





