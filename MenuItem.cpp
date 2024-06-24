#include "MenuItem.h"
#include "Ingredient.h" // Ensure this file includes the definition of Ingredient
#include <utility> // For std::move

MenuItem::MenuItem(int numOfIngredients, Ingredient** list)
    : price(0), ingredientList(list) {
    // You may want to add additional initialization logic here
}

MenuItem::~MenuItem() {
    delete[] ingredientList; // Ensure proper deletion of dynamically allocated array
}

MenuItem::MenuItem() : price(0), ingredientList(nullptr) {}

MenuItem::MenuItem(MenuItem&& other)
    : price(other.price), ingredientList(other.ingredientList) {
    other.ingredientList = nullptr; // Nullify the source's pointer to avoid double deletion
}

const MenuItem& MenuItem::operator=(const MenuItem& other) {
    if (this != &other) {
        price = other.price;
        delete[] ingredientList; // Clean up existing resources
        // Deep copy the ingredient list
        ingredientList = new Ingredient * [sizeof(other.ingredientList) / sizeof(Ingredient*)];
        for (int i = 0; i < sizeof(other.ingredientList) / sizeof(Ingredient*); ++i) {
            ingredientList[i] = other.ingredientList[i]; // Assuming Ingredient has a proper copy constructor
        }
    }
    return *this;
}

const MenuItem& MenuItem::operator=(MenuItem&& other) {
    if (this != &other) {
        price = other.price;
        delete[] ingredientList; // Clean up existing resources
        ingredientList = other.ingredientList;
        other.ingredientList = nullptr; // Nullify the source's pointer to avoid double deletion
    }
    return *this;
}

int MenuItem::getPrice() const {
    return price;
}

const Ingredient**& MenuItem::getIngredientList() const {
    return const_cast<const Ingredient**&>(ingredientList); // Cast to match the return type
}

bool MenuItem::setPrice(int newPrice) {
    if (newPrice >= 0) {
        price = newPrice;
        return true;
    }
    return false;
}

bool MenuItem::setIngredients(Ingredient** newIngredientList, int size) {
    if (newIngredientList) {
        delete[] ingredientList; // Clean up existing resources
        ingredientList = new Ingredient * [size];
        for (int i = 0; i < size; ++i) {
            ingredientList[i] = newIngredientList[i]; // Assuming Ingredient has a proper copy constructor
        }
        return true;
    }
    return false;
}
