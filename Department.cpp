#pragma warning (disable: 4996)

#include <iostream>
using namespace std;
#include "department.h"
#include "warehouse.h"

// Get number of workers
inline int Department::getNumOfWorkers() const {
    return numOfWorkers;
}

// Update ingredient quantity
bool Department::updateIngredientQuantity(char* name, int quantity) {
    return wareHouse.updateIngredientQuantity(name, quantity);
}

// Add ingredient to the warehouse
bool Department::addIngredientToWarehouse(char* ingredientName, int section) {
    return wareHouse.addIngredient(ingredientName, section);
}