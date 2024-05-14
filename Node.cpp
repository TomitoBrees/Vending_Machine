#include "Node.h"

Node::Node(){
    data = nullptr;
    next = nullptr;
};

Node::Node(void* data, NodeType type) {
    this->data = data;
    next = nullptr;
    this->type = type;
}

Node::~Node(){
    switch(type) {
        case FOOD_ITEM:
            delete static_cast<FoodItem*>(data);
            break;
        case COIN:
            delete static_cast<Coin*>(data);
            break;
    }
    delete next;
};

Price::Price(unsigned int dollars, unsigned int cents) {
    this->dollars = dollars;
    this->cents = cents;
}

std::string Price::displayPrice() {
    // Display dollars and cents. Ensure that the cents are always 2 decimal points
    std::string res = std::to_string(dollars) + "." + (cents < 10? "0" : "") + std::to_string(cents);
    return res;
}

FoodItem::FoodItem(std::string id, std::string name, std::string description, Price* price, unsigned int on_hand) {
    this->id = id;
    this->name = name;
    this->description = description;
    this->price = price;
    this->on_hand = on_hand;
}