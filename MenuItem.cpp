#include "MenuItem.h"
#include <iostream>
#include <utility>

// Constructor with parameters
MenuItem::MenuItem(const int numOfIngredients, Ingredient** list)
    : price(0), numOfIngredients(numOfIngredients) {
    ingredientList = new Ingredient*[numOfIngredients];
    for (int i = 0; i < numOfIngredients; ++i) {
        ingredientList[i] = list[i];
    }
}

// Default constructor
MenuItem::MenuItem() : price(0), ingredientList(nullptr), numOfIngredients(0) {}

// Destructor
MenuItem::~MenuItem() {
    clearIngredients();
}

// Move constructor
MenuItem::MenuItem(MenuItem&& other) noexcept : price(other.price), ingredientList(other.ingredientList), numOfIngredients(other.numOfIngredients) {
    other.price = 0;
    other.ingredientList = nullptr;
    other.numOfIngredients = 0;
}

MenuItem::MenuItem(const MenuItem& other) : price(other.price), numOfIngredients(other.numOfIngredients) {
    ingredientList = new Ingredient*[numOfIngredients];
    for (int i = 0; i < numOfIngredients; ++i) {
        ingredientList[i] = other.ingredientList[i];
    }
}

// Copy assignment operator
MenuItem& MenuItem::operator=(const MenuItem& other) {
    if (this != &other) {
        clearIngredients();

        price = other.price;
        numOfIngredients = other.numOfIngredients;

        // Allocate new memory and copy
        ingredientList = new Ingredient*[numOfIngredients];
        for (int i = 0; i < numOfIngredients; ++i) {
            ingredientList[i] = other.ingredientList[i];
        }
    }
    return *this;
}

// Move assignment operator
MenuItem& MenuItem::operator=(MenuItem&& other) noexcept {
    if (this != &other) {
        clearIngredients(); 

        price = other.price;
        ingredientList = other.ingredientList;
        numOfIngredients = other.numOfIngredients;

        other.price = 0;
        other.ingredientList = nullptr;
        other.numOfIngredients = 0;
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
    clearIngredients();

    ingredientList = new Ingredient*[size];
    numOfIngredients = size;
    for (int i = 0; i < size; ++i) {
        ingredientList[i] = list[i];
    }
    return true;
}

void MenuItem::clearIngredients() {
    if (ingredientList) {
        delete[] ingredientList;
        ingredientList = nullptr;
        numOfIngredients = 0;
    }
}