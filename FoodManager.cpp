#include "FoodManager.h"

FoodManager::FoodManager() {
    foodList = new LinkedList();
}

FoodItem* FoodManager::get(int index) {
    FoodItem* res = nullptr;

    if(index >= 0 && index < foodList->size()){

        int counter = 0;
        Node* current = foodList->head;

        while(counter<index){
            ++counter;
            current = current->next;
        }

        res = static_cast<FoodItem*>(current->data);

    }
    return res;
}

void FoodManager::displayList() {
    Node* current = foodList->head;
    std::cout << "Food Menu" << std::endl;
    std::cout << "---------" << std::endl;
    std::cout << "ID" << "   |" << "Name" << "                                    " << "|Length" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    while (current != nullptr) {
        FoodItem* foodItem = static_cast<FoodItem*>(current->data);
        std::cout << foodItem->id << "|" << foodItem->name << std::string(40 - foodItem->name.length(), ' ') << "|$" << foodItem->price->displayPrice() << std::endl;
        current = current->next;
    }
}

void FoodManager::removeMenuItem(FoodItem* foodItem) {

    Node* prev = nullptr;
    Node* current = foodList->head;

    while (current) {
        if(current->data == foodItem) {
            Node* next = current->next;

            if(prev == nullptr) {
                foodList->head = current;
            }
            else {
                prev->next = next;
            }
            delete current;
            current = next;
        }
        else {
            prev = current;
            current = current->next;
        }
    }
}

void FoodManager::addBackMenuItem(FoodItem* foodItem) {
    Node* current = foodList->head;

    if(!foodList->head) {
        foodList->head = new Node(foodItem, FOOD_ITEM);
        return;
    }

    while(current->next) {
        current = current->next;
    }

    current->next = new Node(foodItem, FOOD_ITEM);
}


void FoodManager::loadDataFromFoodFile(const std::string& fileName) {
    try {
        std::ifstream file(fileName);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                std::istringstream iss (line);
                std::string id, name, description, priceStr;
                if (std::getline(iss, id, '|') &&
                    std::getline(iss, name, '|') &&
                    std::getline(iss, description, '|') &&
                    std::getline(iss, priceStr)) {

                    // Convert price from string to double
                    double price = std::stod(priceStr);
                    // Create Price object
                    unsigned int dollars = static_cast<unsigned int>(price);
                    unsigned int cents = static_cast<unsigned int>((price - dollars) * 100);
                    Price* itemPrice = new Price(dollars, cents);

                    // Create FoodItem object
                    FoodItem* item = new FoodItem(id, name, description, itemPrice, DEFAULT_FOOD_STOCK_LEVEL);
                    // Add the item to the linked list
                    addBackMenuItem(item);
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


FoodItem* FoodManager::findFoodItemByID(const std::string& id) {
    Node* current = foodList->head;
    while (current) {
        FoodItem* foodItem = static_cast<FoodItem*>(current->data);
        // If the ID entered matches an ID in the linked list, return pointer to that item
        if (foodItem->id == id) {
            return foodItem;
        }
        current = current->next;
    }
    // Return nullptr if the the food item with given ID is not found
    return nullptr;
}