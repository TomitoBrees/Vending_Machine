#include "FoodManager.h"

FoodManager::FoodManager() {
    foodList = new LinkedList();
}

FoodManager::~FoodManager() {
    delete foodList;
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

void FoodManager::saveDataToFile(const std::string& fileName) {
    try {
        std::ofstream file(fileName);
        Node* current = foodList->head;

        while(current) {
            FoodItem* currentItem = static_cast<FoodItem*>(current->data);
            file << currentItem->id << "|" << currentItem->name << "|" << currentItem->description << "|" << currentItem->price->displayPrice() << std::endl;

            current = current->next;
        }

        file.close();
    }
    catch (const std::exception &e) {
        // Catch any errors while loading the data into the linked list and display and error message
        std::cerr << "Error writing data to " << fileName << ": " << e.what() << std::endl;
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

std::string FoodManager::generateNextID() {
    try {
    // Determine the current size of the linked list
    int currentSize = foodList->size();

    // Generate the next available id according the format in the foods.dat file
    std::string nextID = "F";
    nextID.append(std::to_string(currentSize + 1));

    // Pad the id with leading 0's to make sure it's 5 characters long
    nextID.insert(1, 5 - nextID.length(), '0');
    return nextID;
    }
    catch (const std::exception& e) {
        // Error message if there is a problem generating the next available id
        std::cerr << "Error generating next ID: " << e.what() << std::endl;
        throw;
    }
}

void FoodManager::addNewFoodItem(const std::string& name, const std::string& description, double price) {
    try {
    // Generate the next available id for the new food item
    std::string nextID = generateNextID();

    // Create Price object
    unsigned int dollars = static_cast<unsigned int>(price);
    unsigned int cents = static_cast<unsigned int>((price - dollars) * 100);
    Price* itemPrice = new Price(dollars, cents);
    
    // Create FoodItem object and add it to the linked list
    FoodItem* newItem = new FoodItem(nextID, name, description, itemPrice, DEFAULT_FOOD_STOCK_LEVEL);
    addBackMenuItem(newItem);
    }
    catch (const std::exception& e) {
        // Error message if there is a problem while adding the new food item to the linked list
        std::cerr << "Error adding new food item: " << e.what() << std::endl;
    }
}

void FoodManager::removeMenuItem(FoodItem* foodItem) {
    Node* prev = nullptr;
    Node* current = foodList->head;

    while (current) {
        // Get the food item node and remove it from the linked list
        if (current->data == foodItem) {
            Node* next = current->next;

            if (prev == nullptr) {
                // Update the pointer to point to the next node
                foodList->head = next;
            }
            else { 
                prev->next = next;
            }

            // Print the details of the removed food item
            FoodItem* removedItem = static_cast<FoodItem*>(current->data);
            std::cout << "'" << removedItem->id << " - " << removedItem->name << " - " 
            << removedItem->description << "' has been removed from the system." << std::endl;
            std::cout << std::endl;
            delete current;
            return;
        }
        else {
            prev = current;
            current = current->next;
        }
    }
}