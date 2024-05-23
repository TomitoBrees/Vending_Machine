#include <limits>
#include "CoinManager.h"


CoinManager::CoinManager() {
    coinVector = new std::vector<Coin*>;
}

CoinManager::~CoinManager() {

    delete coinVector;
}

void CoinManager::addCoin(Denomination denomination) {

    for (size_t i = 0; i < coinVector->size(); i++) {
        Coin* current_coin = (*coinVector)[i];
        if (current_coin->denom == denomination) {
            current_coin->count += 1;
            return;
        }
    }
    std::cout << "You cannot add this change" << std::endl;
}

void CoinManager::removeCoin(Denomination denomination)
{
    for (size_t i = 0; i < coinVector->size(); i++) {
        Coin* current_coin = (*coinVector)[i];
        if (current_coin->denom == denomination) {
            if(current_coin->count >= 1) {
                current_coin->count -= 1;
            }
            else {
                std::cout << "You don't have enough of these coins to give back" << std::endl;
            }
            return;
        }
    }
    std::cout << "You cannot give this change" << std::endl;
}

Denomination CoinManager::intToDenomination(int value) {

    Denomination result = WRONG;

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
    else if (value == 5) {
        result = FIVE_CENTS;
    }

    return result;
}


int CoinManager::denominationToInt(Denomination value) {
    int result;

    if(value == FIVE_CENTS)
    {
        result = 5;
    }
    if(value == TEN_CENTS)
    {
        result = 10;
    }
    if(value == TWENTY_CENTS)
    {
        result = 20;
    }
    if(value == FIFTY_CENTS)
    {
        result = 50;
    }
    if(value == ONE_DOLLAR)
    {
        result = 100;
    }
    if(value == TWO_DOLLARS)
    {
        result = 200;
    }
    if(value == FIVE_DOLLARS)
    {
        result = 500;
    }
    if(value == TEN_DOLLARS)
    {
        result = 1000;
    }
    if(value == TWENTY_DOLLARS)
    {
        result = 2000;
    }
    if(value == FIFTY_DOLLARS)
    {
        result = 5000;
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

                    coinVector->insert(coinVector->begin(),coin);
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

void CoinManager::saveDataToFile(const std::string& fileName) {
    try {
        std::ofstream file(fileName);
        for (size_t i = coinVector->size() - 1; i > 0; i--) {
            Coin* currentItem = (*coinVector)[i];
            file << denominationToInt(currentItem->denom) << "," << currentItem->count << std::endl;
        }

        file.close();
    }
    catch (const std::exception &e) {
        // Catch any errors while loading the data into the linked list and display and error message
        std::cerr << "Error writing data to " << fileName << ": " << e.what() << std::endl;
    }
}

std::string CoinManager::intTabulation(int value, int tab) {
    std::string result;
    int copy = value;
    int size = 1;
    while(value/10 != 0) {
        size += 1;
        value /= 10;
    }

    int tabulation = tab - size;
    std::string str = std::to_string(copy);
    result += str;

    for (int i = 0; i < tabulation; i++) {
        result += " ";
    }
    return result;
}

float CoinManager::findValue(int denomination, unsigned int quantity) {
    float value;
    float realDenom = denomination * 0.01;
    value = realDenom * quantity;
    return value;
}

int CoinManager::findSize(int value) {
    int size = 0;
    if (value == 0) {
        return 1;
    }

    while(value != 0) {
        value /= 10;
        size += 1;
    }
    return size;
}

void CoinManager::displayBalance() {
    std::cout << "Balance Summary\n"
                 "-------------\n"
                 "Denom  | Quantity | Value\n"
                 "---------------------------" << std::endl;

    int denomination;
    unsigned int quantity;
    float total = 0;
    int index = 0;

    for (size_t i = 0; i < coinVector->size() && index < 10; ++i) {
        Coin* currentCoin = (*coinVector)[i];
        index += 1;

        Denomination _denomination = currentCoin->denom;
        denomination = denominationToInt(_denomination);
        quantity = currentCoin->count;

        std::cout << intTabulation(denomination, 7) << "| " << intTabulation(quantity, 9);

        float value = findValue(denomination, quantity);
        std::stringstream stream;
        stream << std::fixed << std::setprecision(2) << value;
        std::string s = stream.str();

        std::string tab = "$ ";
        int size = findSize(static_cast<int>(value));

        if (size == 1)
            tab += "  ";
        else if (size == 2)
            tab += " ";

        tab += s;
        std::cout << "|" << tab << std::endl;

        total += value;
    }
    std::cout << "---------------------------" << std::endl;

    std::stringstream stream2;
    stream2 << std::fixed << std::setprecision(2) << total;
    std::string s2 = stream2.str();

    std::cout << "                   $ " << s2 << std::endl;
}

void CoinManager::buyItem(int toPay) {
    bool paid = false;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

    std::vector<Coin*> recolted_change;

    while(!paid) {

        std::cout << "You still need to give us $ " << toPay << " : ";

        std::string input;
        std::getline(std::cin, input);
        std::stringstream ss(input);

        if (input.empty()) {

            if(!recolted_change.empty()) {
                for (size_t i = 0; i < recolted_change.size(); i++) {
                    removeCoin(recolted_change[i]->denom);
                }
            }

            return;
        }

        int given;

        if (!(ss >> given)) {
            // Invalid input, clear the stream and try again
            std::cin.clear();
            std::cout << "Invalid input. Please enter a valid amount." << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore remaining characters
            continue;
        }

        Denomination toAdd = intToDenomination(given);
        if (toAdd == WRONG) {
            std::cout << "Invalid denomination. Please enter a valid coin value." << std::endl;
            continue;
        }

        recolted_change.push_back(new Coin(toAdd, 1));

        addCoin(toAdd);

        toPay -= given;

        if (toPay <= 0) {
            paid = true;
        }
    }

    if (toPay < 0) {
        for (size_t i = coinVector->size() - 1; i >= 0 && toPay != 0; --i) {
            int coinValue = denominationToInt((*coinVector)[i]->denom);
            int coinCount = (*coinVector)[i]->count;
            if (coinValue <= std::abs(toPay) && coinCount > 0) {
                int numCoinsToUse = std::min(coinCount, std::abs(toPay) / coinValue);
                (*coinVector)[i]->count -= numCoinsToUse;
                toPay += numCoinsToUse * coinValue;

                for (int j = 0; j < numCoinsToUse; j++) {
                    removeCoin(intToDenomination(coinValue));
                }

                std::cout << "Giving change: " << coinValue << std::endl;
            }
        }
    }

    std::cout << " " << std::endl;
}
