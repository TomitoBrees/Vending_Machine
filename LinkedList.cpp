#include "LinkedList.h"
#include <iostream>
#include <string>

LinkedList::LinkedList() {
   head = nullptr;
}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp->data;
        delete temp;
    }
}

int LinkedList::size() {
    int res = 0;
    Node* current = head;
    while(current != nullptr){
        ++res;
        current = current->next;
    }
    return res;
}

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