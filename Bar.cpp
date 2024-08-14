#pragma warning (disable: 4996)

#include <iostream>
using namespace std;
#include "bar.h"
#include "drinkItem.h"

// Default constructor
Bar::Bar() : drinkItemList(nullptr){}

// Move constructor
Bar::Bar(Bar&& other) noexcept : Department(std::move(other)), drinkItemList(other.drinkItemList) {
    other.drinkItemList = nullptr;
}

// Destructor
Bar::~Bar() {
    delete[] drinkItemList;
}

// Move assignment operator
const Bar& Bar::operator=(Bar&& other) {
    if (this != &other) {
        Department::operator=(std::move(other));

        delete[] drinkItemList;
        drinkItemList = other.drinkItemList;
        other.drinkItemList = nullptr;
    }
    return *this;
}

// Get number of workers
int Bar::getNumOfWorkers() const {
    return numOfWorkers;
}

// Update ingredient quantity in the warehouse
bool Bar::updateIngredientQuantity(const char* name, int quantity) {
    return wareHouse->updateIngredientQuantity(name, quantity);
}

// Add ingredient to the warehouse
bool Bar::addIngredientToWarehouse(char* ingredientName, int section) {
    return wareHouse->addIngredient(ingredientName, section);
}

// Get drink item list
DrinkItem** Bar::getDrinkItemList() const {
    return drinkItemList;
}

// Get warehouse
Warehouse& Bar::getWareHouse() const {
    return wareHouse;
}