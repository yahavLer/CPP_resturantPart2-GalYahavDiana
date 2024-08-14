#pragma warning (disable: 4996)

#include <iostream>
using namespace std;
#include "department.h"

Department::Department() : wareHouse(nullptr), numOfWorkers(0) {}

Department::Department(int workers) : wareHouse(nullptr), numOfWorkers(workers) {}


// Update ingredient quantity
bool Department::updateIngredientQuantity(const char* name, int quantity) {
    Ingredient* ingredient = wareHouse->getIngredientByName(name);
    if (ingredient) {
        return wareHouse->updateIngredientQuantity(ingredient, quantity);
    }
    return false;  // Return false if ingredient not found
}

// Add ingredient to the warehouse
bool Department::addIngredientToWarehouse(const char* ingredientName, int section) {
    return wareHouse->addIngredientToWarehouse(ingredientName, section);
}