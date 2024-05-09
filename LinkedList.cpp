#include "LinkedList.h"
#include <iostream>
#include <string>

LinkedList::LinkedList() {
   head = nullptr;

   // TODO
}

LinkedList::~LinkedList() {
    // TODO
}

void LinkedList::displayList() {
    // Display the menu items
    Node* current = head;
    while (current != nullptr) {
        std::cout << "Menu" << std::endl;
        std::cout << "----" << std::endl;
        std::cout << "ID" << "|" << "Name" << "                             " << "|Length" << std::endl;
        std::cout << "------------------------------------------------------------------" << std::endl;
        std::cout << current->data->id << "|" << current->data->name << "                               |$" << current->data->price << std::endl;
        current = current->next;
    }
}

void LinkedList::removeMenuItem(int index) {
    
}

void LinkedList::addBackMenuItem(FoodItem* foodItem) {

}
