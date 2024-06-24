#include <iostream>
using namespace std;

#include "Kitchen.h"

// Assuming basic structure and methods for FoodItem and Warehouse
struct FoodItem {
    // Members and methods for FoodItem
};

Kitchen::Kitchen() : foodItemList(nullptr), numOfWrkers(0) {
    // Default constructor implementation
}

Kitchen::Kitchen(Kitchen&& other) : warehouse(move(other.warehouse)), foodItemList(other.foodItemList), numOfWrkers(other.numOfWrkers) {
    other.foodItemList = nullptr;
    other.numOfWrkers = 0;
}

Kitchen::~Kitchen() {
    delete[] foodItemList;
}

const Kitchen& Kitchen::operator=(const Kitchen& other) {
    if (this == &other) return *this;

    delete[] foodItemList;

    warehouse = other.warehouse; // Assuming Warehouse has an appropriate assignment operator
    numOfWrkers = other.numOfWrkers;

    // Assuming deep copy logic for FoodItem pointers
    // foodItemList = new FoodItem*[other.getFoodItemListSize()];
    // Deep copy code here

    return *this;
}

const Kitchen& Kitchen::operator=(Kitchen&& other) {
    if (this == &other) return *this;

    delete[] foodItemList;

    warehouse = move(other.warehouse);
    foodItemList = other.foodItemList;
    numOfWrkers = other.numOfWrkers;

    other.foodItemList = nullptr;
    other.numOfWrkers = 0;

    return *this;
}

inline Warehouse Kitchen::getWareHouse() const {
    return warehouse;
}

inline FoodItem** Kitchen::getFoodItemList() const {
    return foodItemList;
}

inline int Kitchen::getNumOfWorkers() const {
    return numOfWrkers;
}

bool Kitchen::updateIngredientQuantity(char* name, int quantity) {
    // Logic to update ingredient quantity in the warehouse
    // return warehouse.updateIngredient(name, quantity);
    return true;
}

bool Kitchen::addIngredientToWarehouse(char* ingredientName, int section) {
    // Logic to add ingredient to the warehouse
    // return warehouse.addIngredient(ingredientName, section);
    return true;
}