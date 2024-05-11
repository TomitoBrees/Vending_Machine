#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// Constructor
LinkedList::LinkedList() {
   head = nullptr;
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

// Get the item at the given index
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
    while (current != nullptr) {
        std::cout << "Menu" << std::endl;
        std::cout << "----" << std::endl;
        std::cout << "ID" << "|" << "Name" << "                             " << "|Length" << std::endl;
        std::cout << "------------------------------------------------------------------" << std::endl;
        std::cout << current->data->id << "|" << current->data->name << "                               |$" << current->data->price->displayPrice() << std::endl;
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

// Load data from the file into a linked list
void LinkedList::loadDataFromFoodFile(const std::string& fileName) {
    std::ifstream file(fileName);
    if (file.is_open()) {
        std::string code, name, description, priceStr;
        while (getline(file, code, '|') && getline(file, description, '|') && getline(file, priceStr)) {
            // Convert price from string to double
            double price = std::stod(priceStr);

            // Create Price object
            unsigned int dollars = static_cast<unsigned int>(price);
            unsigned int cents = static_cast<unsigned int>((price - dollars) * 100);
            Price* itemPrice = new Price(dollars, cents);

            // Create FoodItem object
            FoodItem* item = new FoodItem(code, name, description, itemPrice, DEFAULT_FOOD_STOCK_LEVEL);

            // Add the item to the linked list
            addFrontMenuItem(item);
        }
        // Close the file
        file.close();
    }
    else {
        // Error message if unable to read from file
        std::cout << "Unable to open file: " << fileName << std::endl;
    }
}