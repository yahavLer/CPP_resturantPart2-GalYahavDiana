#include "MenuItem.h"
#include <iostream>
#include <utility>

// Constructor with parameters
// Constructor with parameters
MenuItem::MenuItem(const std::string& itemName, const int numOfIngredients, Ingredient** list, int price)
    : name(itemName), price(price), numOfIngredients(numOfIngredients), ingredientList(nullptr) {
    if (numOfIngredients > 0 && list != nullptr) {
        ingredientList = new Ingredient * [numOfIngredients];
        for (int i = 0; i < numOfIngredients; ++i) {
            ingredientList[i] = list[i];
        }
    }
}
// Default constructor
MenuItem::MenuItem() :name(""), price(0), ingredientList(nullptr), numOfIngredients(0) {}


// Destructor
MenuItem::~MenuItem() {
    clearIngredients();
}

// Move constructor
MenuItem::MenuItem(MenuItem&& other) noexcept
    :name(std::move(other.name)), price(other.price), ingredientList(other.ingredientList), numOfIngredients(other.numOfIngredients)
{
    other.ingredientList = nullptr;
    other.numOfIngredients = 0;
}

// Copy constructor
MenuItem::MenuItem(const MenuItem& other)
    : name(other.name), price(other.price), numOfIngredients(other.numOfIngredients), ingredientList(nullptr) {
    if (numOfIngredients > 0 && other.ingredientList != nullptr) {
        ingredientList = new Ingredient * [numOfIngredients];
        for (int i = 0; i < numOfIngredients; ++i) {
            ingredientList[i] = other.ingredientList[i];
        }
    }
}

// Copy assignment operator
MenuItem& MenuItem::operator=(const MenuItem& other) {
    if (this != &other) {
       clearIngredients();

       name = other.name;
       price = other.price;
       numOfIngredients = other.numOfIngredients;

       if (numOfIngredients > 0 && other.ingredientList != nullptr) {
           ingredientList = new Ingredient * [numOfIngredients];
           for (int i = 0; i < numOfIngredients; ++i) {
               ingredientList[i] = other.ingredientList[i];
           }
       }
    }
    return *this;
}

// Move assignment operator
MenuItem& MenuItem::operator=(MenuItem&& other) noexcept {
    if (this != &other) {
        clearIngredients();

        name = std::move(other.name);
        price = other.price;
        ingredientList = other.ingredientList;
        numOfIngredients = other.numOfIngredients;

        other.ingredientList = nullptr;
        other.numOfIngredients = 0;
    }
    return *this;
}

// Set price
bool MenuItem::setPrice(int newPrice) {
    if (price != 0)
    {
        price = newPrice;
        return true;
    }
    return false; 
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
// Set name
bool MenuItem::setName(const std::string& newName) {
    if (newName != "") {
        name = newName;
        return true;
    }
    return false;
}

