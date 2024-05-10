#include "Node.h"

Node::Node(){
    data = nullptr;
    next = nullptr;
};

Node::Node(FoodItem* data) {
    this->data = data;
    next = nullptr;
}

Node::~Node(){
    delete data;
    delete next;
};

Price::Price(unsigned int dollars, unsigned int cents) {
    this->dollars = dollars;
    this->cents = cents;
}

std::string Price::displayPrice() {
    std::string res = std::to_string(dollars) + "." + std::to_string(cents);
    return res;
}


FoodItem::FoodItem(std::string id, std::string name, std::string description, Price* price, unsigned int on_hand) {
    this->id = id;
    this->name = name;
    this->description = description;
    this->price = price;
    this->on_hand = on_hand;
}
