#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// Constructor
LinkedList::LinkedList() {
   head = nullptr;

   // Load the data from the foods.dat file into the linked list
   loadDataFromFoodFile("foods.dat");

   // Reset stock level for all food items to the default number
   Node* current = head;
   while (current != nullptr) {
    current->data->on_hand = DEFAULT_FOOD_STOCK_LEVEL;
    current = current->next;
   }
}

// Destructor
LinkedList::~LinkedList() {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp->data;
        delete temp;
    }
}

// Get the size of the linked list
int LinkedList::size() {
    int res = 0;
    Node* current = head;
    while(current != nullptr){
        ++res;
        current = current->next;
    }
    return res;
}

// Get the item at the given index in food menu linked list
FoodItem* LinkedList::get(int index) {
    FoodItem* res = nullptr;

    if(index >= 0 && index < size()){

        int counter = 0;
        Node* current = head;

        while(counter<index){
            ++counter;
            current = current->next;
        }

        res = current->data;

    }
    return res;
}

void LinkedList::displayList() {
    // Display the menu items
    Node* current = head;
    std::cout << "Menu" << std::endl;
        std::cout << "----" << std::endl;
        std::cout << "ID" << "   |" << "Name" << "                                    " << "|Length" << std::endl;
        std::cout << "------------------------------------------------------" << std::endl;
    while (current != nullptr) {
        std::cout << current->data->id << "|" << current->data->name << std::string(40 - current->data->name.length(), ' ') << "|$" << current->data->price->displayPrice() << std::endl;
        current = current->next;
    }
}

void LinkedList::removeMenuItem(FoodItem* foodItem) {

    Node* prev = nullptr;
    Node* current = head;

    while (current) {
        if(current->data == foodItem) {
            Node* next = current->next;

            if(prev == nullptr) {
                head = current;
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

void LinkedList::addFrontMenuItem(FoodItem* foodItem) {
    Node* node = new Node();
    node->data = foodItem;
    node->next = head;
    head = node;
}

void LinkedList::addBackMenuItem(FoodItem* foodItem) {
    Node* current = head;

    if(!head) {
        head = new Node(foodItem);
        return;
    }

    while(current->next) {
        current = current->next;
    }

    current->next = new Node(foodItem);
}

// Load data from the foods.dat file into a linked list
void LinkedList::loadDataFromFoodFile(const std::string& fileName) {
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