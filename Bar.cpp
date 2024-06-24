#pragma warning (disable: 4996)

#include <iostream>
using namespace std;
#include "bar.h"
#include "drinkItem.h"

// Default constructor
Bar::Bar() : drinkItemList(nullptr), numOfWorkers(0) {}

// Move constructor
Bar::Bar(Bar&& other) : wareHouse(std::move(other.wareHouse)), drinkItemList(other.drinkItemList), numOfWorkers(other.numOfWorkers) {
    other.drinkItemList = nullptr;
    other.numOfWorkers = 0;
}

// Destructor
Bar::~Bar() {
    delete[] drinkItemList;
}

// Move assignment operator
const Bar& Bar::operator=(Bar&& other) {
    if (this != &other) {
        delete[] drinkItemList;

        wareHouse = std::move(other.wareHouse);
        drinkItemList = other.drinkItemList;
        numOfWorkers = other.numOfWorkers;

        other.drinkItemList = nullptr;
        other.numOfWorkers = 0;
    }
    return *this;
}

// Get number of workers
int Bar::getNumOfWorkers() const {
    return numOfWorkers;
}

// Update ingredient quantity in the warehouse
bool Bar::updateIngredientQuantity(char* name, int quantity) {
    return wareHouse.updateIngredientQuantity(name, quantity);
}

// Add ingredient to the warehouse
bool Bar::addIngredientToWarehouse(char* ingredientName, int section) {
    return wareHouse.addIngredient(ingredientName, section);
}

// Get drink item list
DrinkItem** Bar::getDrinkItemList() const {
    return drinkItemList;
}

// Get warehouse
Warehouse& Bar::getWareHouse() const {
    return wareHouse;
}
.