#include "Warehouse.h"
#include "ingredient.h"
#include <cstring>

Warehouse::Warehouse() : ingrediantList(nullptr), ingrediantQuantityList(nullptr) {}

Warehouse::Warehouse(Warehouse&& other)
    : ingrediantList(other.ingrediantList), ingrediantQuantityList(other.ingrediantQuantityList) {
    other.ingrediantList = nullptr;
    other.ingrediantQuantityList = nullptr;
}

Warehouse::~Warehouse() {
    delete[] ingrediantList;
    delete[] ingrediantQuantityList;
}

const Warehouse& Warehouse::operator=(const Warehouse& other) {
    if (this != &other) {
        delete[] ingrediantList;
        delete[] ingrediantQuantityList;
        // Deep copy ingredient list
        ingrediantList = new Ingrediant * [sizeof(other.ingrediantList) / sizeof(Ingrediant*)];
        for (int i = 0; i < sizeof(other.ingrediantList) / sizeof(Ingrediant*); ++i) {
            ingrediantList[i] = other.ingrediantList[i]; // Assuming Ingrediant has a proper copy constructor
        }
        // Deep copy ingredient quantity list
        ingrediantQuantityList = new int[sizeof(other.ingrediantQuantityList) / sizeof(int)];
        std::memcpy(ingrediantQuantityList, other.ingrediantQuantityList, sizeof(other.ingrediantQuantityList));
    }
    return *this;
}

const Warehouse& Warehouse::operator=(Warehouse&& other) {
    if (this != &other) {
        delete[] ingrediantList;
        delete[] ingrediantQuantityList;
        ingrediantList = other.ingrediantList;
        ingrediantQuantityList = other.ingrediantQuantityList;
        other.ingrediantList = nullptr;
        other.ingrediantQuantityList = nullptr;
    }
    return *this;
}

Ingrediant** Warehouse::getIngrediantList() const {
    return ingrediantList;
}

int* Warehouse::getIngrediantQuantityList() const {
    return ingrediantQuantityList;
}

bool Warehouse::updateIngredientQuantity(Ingrediant ingrediant, int quantity) {
    for (int i = 0; ingrediantList[i] != nullptr; ++i) {
        if (std::strcmp(ingrediantList[i]->getName(), ingrediant.getName()) == 0) {
            ingrediantQuantityList[i] = quantity;
            return true;
        }
    }
    return false;
}

bool Warehouse::addIngredientToWarehouse(char* ingredientName, int section) {
    // Determine the size of the existing lists
    int size = 0;
    while (ingrediantList && ingrediantList[size] != nullptr) {
        ++size;
    }

    // Create new lists with one additional slot
    Ingrediant** newIngrediantList = new Ingrediant * [size + 2];
    int* newIngrediantQuantityList = new int[size + 1];

    // Copy existing data to new lists
    for (int i = 0; i < size; ++i) {
        newIngrediantList[i] = ingrediantList[i];
        newIngrediantQuantityList[i] = ingrediantQuantityList[i];
    }

    // Add the new ingredient
    newIngrediantList[size] = new Ingrediant(ingredientName, static_cast<Ingrediant::eSection>(section));
    newIngrediantQuantityList[size] = 0;

    // Null terminate the ingredient list
    newIngrediantList[size + 1] = nullptr;

    // Clean up old lists
    delete[] ingrediantList;
    delete[] ingrediantQuantityList;

    // Assign new lists to class members
    ingrediantList = newIngrediantList;
    ingrediantQuantityList = newIngrediantQuantityList;

    return true;
}
