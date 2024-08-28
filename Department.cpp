#pragma warning (disable: 4996)

#include <iostream>
using namespace std;
#include "department.h"

Department::Department() : wareHouse(), numOfWorkers(0) { }

Department::Department(int workers) : wareHouse(), numOfWorkers(workers) {}

// Move constructor
Department::Department(Department&& other) noexcept
    : wareHouse(std::move(other.wareHouse)), numOfWorkers(other.numOfWorkers)
{
    other.numOfWorkers = 0;
}

Warehouse& Department::getWarehouse()
{ 
    return wareHouse; 
}

// Update ingredient quantity
bool Department::updateIngredientQuantity(const char* name, int quantity) {
    Ingredient* ingredient = wareHouse.getIngredientByName(name);
    if (ingredient) {
        return wareHouse.updateIngredientQuantity(ingredient, quantity);
    }
    return false;  // Return false if ingredient not found
}

// Add ingredient to the warehouse
bool Department::addIngredientToWarehouse(const char* ingredientName, int section) 
{
    return wareHouse.addIngredientToWarehouse(ingredientName, section);
}

Department& Department::operator=(const Department& other)
{
    if (this != &other)
    {
       
        Department::operator=(other); // Assuming Warehouse has an appropriate assignment operator
      
    }

    return *this;
}

void Department::printWarehouse()
{
    wareHouse.print();
}
