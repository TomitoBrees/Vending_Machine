# Vending Machine

## Overview

This project simulates a vending machine system using C++. It allows users to insert coins, select products, receive change, and manage the inventory. The system is designed with object-oriented principles and utilizes a linked list for managing items.

## Features

- **Coin Management**: Accepts coins of 1, 5, 10, and 25 cents.
- **Product Selection**: Offers products like Coke, Pepsi, and Soda with predefined prices.
- **Refund Option**: Allows users to cancel the transaction and receive a refund.
- **Inventory Management**: Enables the supplier to reset the machine's inventory.
- **Data Persistence**: Stores coin and product data in external files (`coins.dat` and `foods.dat`).

## File Structure

```
Vending_Machine/
├── CoinManager.cpp
├── CoinManager.h
├── FoodManager.cpp
├── FoodManager.h
├── LinkedList.cpp
├── LinkedList.h
├── Node.cpp
├── Node.h
├── Makefile
├── coins.dat
├── foods.dat
├── new_coin.dat
├── new_food.dat
├── ftt.cpp
├── ftt.o
├── .idea/
└── .vscode/
```

## Compilation & Execution

To compile and run the project:

1. Ensure you have a C++ compiler installed.
2. Navigate to the project directory.
3. Run the following commands:

   ```bash
   make
   ./vending_machine
   ```

## Usage

- **Insert Coins**: Enter the desired coin value when prompted.
- **Select Product**: Choose a product by entering its corresponding number.
- **Cancel Transaction**: Type 'cancel' to receive a refund.
- **Reset Inventory**: Use the supplier's reset functionality to update stock.

## Data Files

- `coins.dat`: Stores available coin denominations.
- `foods.dat`: Contains the list of products and their prices.
- `new_coin.dat` & `new_food.dat`: Used for updating coin and product data.

## Development Tools

- **IDE**: IntelliJ IDEA or Visual Studio Code
- **Build Tool**: Makefile for compilation

## License

This project is free to use
