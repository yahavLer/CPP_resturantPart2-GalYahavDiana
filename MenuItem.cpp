#include "MenuItem.h"
#include <iostream>
#include <utility>

// Constructor with parameters
MenuItem::MenuItem(const int numOfIngredients, Ingredient** list) {
    price = 0; // Initialize price to a default value, you may want to pass this as a parameter instead
    ingredientList = new Ingredient * [numOfIngredients];
    for (int i = 0; i < numOfIngredients; ++i) {
        // Assuming a deep copy is necessary, otherwise, shallow copy would suffice.
        ingredientList[i] = list[i];
    }
}

// Default constructor
MenuItem::MenuItem() : price(0), ingredientList(nullptr) {}

// Destructor
MenuItem::~MenuItem() {
    if (ingredientList) {
        delete[] ingredientList;
    }
}

// Move constructor
MenuItem::MenuItem(MenuItem&& other) : price(other.price), ingredientList(other.ingredientList) {
    other.price = 0;
    other.ingredientList = nullptr;
}

// Copy assignment operator
const MenuItem& MenuItem::operator=(const MenuItem& other) {
    if (this != &other) {
        price = other.price;

        // Clean up existing ingredientList
        if (ingredientList) {
            delete[] ingredientList;
        }

        // Allocate new memory and copy
        ingredientList = new Ingredient * [sizeof(other.ingredientList) / sizeof(Ingredient*)];
        for (int i = 0; i < sizeof(other.ingredientList) / sizeof(Ingredient*); ++i) {
            ingredientList[i] = other.ingredientList[i];
        }
    }
    return *this;
}

// Move assignment operator
const MenuItem& MenuItem::operator=(MenuItem&& other) {
    if (this != &other) {
        price = other.price;
        std::swap(ingredientList, other.ingredientList);

        other.price = 0;
        other.ingredientList = nullptr;
    }
    return *this;
}

// Set price
bool MenuItem::setPrice(int newPrice) {
    price = newPrice;
    return true;
}

// Set ingredients
bool MenuItem::setIngredients(Ingredient** list, int size) {
    if (ingredientList) {
        delete[] ingredientList;
    }

    ingredientList = new Ingredient * [size];
    for (int i = 0; i < size; ++i) {
        // Assuming a deep copy is necessary, otherwise, shallow copy would suffice.
        ingredientList[i] = list[i];
    }
    return true;
}