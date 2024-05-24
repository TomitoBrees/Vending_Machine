#include "LinkedList.h"
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
        // Check the type of node and delete the data
        if (temp->type == FOOD_ITEM) {
            delete static_cast<FoodItem*>(temp->data);
        }
        else if (temp->type == COIN) {
            delete static_cast<Coin*>(temp->data);
        }
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