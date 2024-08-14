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
bool Department::updateIngredientQuantity(const char* name, int quantity) {
    Ingredient* ingradient = wareHouse->getIngredientByName(name);
    return wareHouse->updateIngredientQuantity(ingradient, quantity);
}

// Add ingredient to the warehouse
bool Department::addIngredientToWarehouse(const char* ingredientName, int section) {
    return wareHouse->addIngredientToWarehouse(ingredientName, section);
}