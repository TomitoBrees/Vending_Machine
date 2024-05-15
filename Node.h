#ifndef NODE_H
#define NODE_H
#include <string>

//The length of the id string not counting the nul terminator
#define IDLEN 5

//The maximum length of a food item name not counting the nul terminator
#define NAMELEN 40

//The maximum length of a food item description not counting the nul terminator.
#define DESCLEN 255

//The default coin level to reset the coins to on request
#define DEFAULT_COIN_COUNT 20

//The possible default food stock level that all new stock should start at and that we should reset to on restock
#define DEFAULT_FOOD_STOCK_LEVEL 20

//The number of denominations of currency available in the system 
#define NUM_DENOMS 8


/**
 * a structure to represent a price. One of the problems with the floating
 * point formats in C++ like float and double is that they have minor issues
 * of inaccuracy due to rounding. In the case of currency this really is
 * not acceptable so we introduce our own type to keep track of currency.
 **/
class Price
{
public:

    //Constructor
    Price(unsigned dollar, unsigned cents);

    // The dollar value, and the cents value for some price
    unsigned dollars, cents;

    // Get the price of the product as a string
    std::string displayPrice();
};

class FoodItem
{
public:

    //Constructor
    FoodItem(std::string id, std::string name, std::string description, Price* price, unsigned on_hand);

    //the unique id for this food item
    std::string id;

    //the name of this food item
    std::string name;

    //the description of this food item
    std::string description;

    //the price of this food item
    Price* price;

    // how many of this food item do we have on hand?
    unsigned on_hand;
};

// enumeration representing the various types of currency available in the system.
enum Denomination
{
    FIVE_CENTS, TEN_CENTS, TWENTY_CENTS, FIFTY_CENTS, ONE_DOLLAR,
    TWO_DOLLARS, FIVE_DOLLARS, TEN_DOLLARS, TWENTY_DOLLARS, FIFTY_DOLLARS
};

// The class representing the coins in our program.
class Coin
{
public:

    Coin(Denomination denom, unsigned count);

    // the denomination type
    enum Denomination denom;

    // the count of how many of these are in the cash register
    unsigned count;
};

// Enum to specify the type of data stored in the node
enum NodeType { FOOD_ITEM, COIN, NONE };

/**
 * the node that holds the data about a food item stored in memory
 **/
class Node
{
public:

    //Constructor
    Node();

    // Constructor for food menu nodes
    Node(void *data, NodeType type);

    ~Node();
    
    // pointer to the data head for the FoodItem node
    void* data;
    // pointer to the next node in the list 
    Node* next;
    //Enum to get the type of the node.
    NodeType type;
};

#endif // NODE_H