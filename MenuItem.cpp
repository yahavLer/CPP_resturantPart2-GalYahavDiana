#include "MenuItem.h"
#include <iostream>
#include <utility>

// Constructor with parameters
//MenuItem::MenuItem(const std::string& itemName, const int numOfIngredients, Ingredient** list, int price)
//    : name(itemName), price(price), numOfIngredients(numOfIngredients), ingredientList(nullptr) {
//    if (numOfIngredients > 0 && list != nullptr) {
//        ingredientList = new Ingredient * [numOfIngredients];
//        for (int i = 0; i < numOfIngredients; ++i) {
//            ingredientList[i] = list[i];
//        }
//    }
//}
MenuItem::MenuItem(const string& itemName, list<Ingredient*> list, int price)
    : name(itemName), price(price), ingredientList(list) {}

// Default constructor
MenuItem::MenuItem() :name(""), price(0), ingredientList() {}

// Destructor
MenuItem::~MenuItem() {
    clearIngredients();
}

// Move constructor
MenuItem::MenuItem(MenuItem&& other) noexcept
    :name(move(other.name)), price(other.price), ingredientList(move(other.ingredientList))
{}

// Copy constructor
MenuItem::MenuItem(const MenuItem& other)
    : name(other.name), price(other.price), ingredientList(other.ingredientList) { }

// Copy assignment operator
MenuItem& MenuItem::operator=(const MenuItem& other) {
    if (this != &other) {
       clearIngredients();
       name = other.name;
       price = other.price;
       ingredientList = other.ingredientList;
    }
    return *this;
}

// Move assignment operator
MenuItem& MenuItem::operator=(MenuItem&& other) noexcept {
    if (this != &other) {
        clearIngredients();
        name = move(other.name);
        price = other.price;
        ingredientList = move(other.ingredientList);
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
bool MenuItem::setIngredients(list<Ingredient*> list) {
    clearIngredients();
    ingredientList = move(list);
    return true;
}

void MenuItem::clearIngredients() {
    ingredientList.clear();
}

const list<Ingredient*>& MenuItem::getIngredientList() const {
    return ingredientList;
}

// Set name
bool MenuItem::setName(const std::string& newName) {
    if (!newName.empty()) {
        name = newName;
        return true;
    }
    return false;
}

