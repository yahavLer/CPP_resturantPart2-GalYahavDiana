#pragma warning (disable: 4996)

#include <iostream>
using namespace std;

#include "Ingredient.h"
#include <cstring>

const char* sections[] = { "Herbs","Dairy","Meat","Fish","Vegetables" };




Ingredient::Ingredient() {
    name[0] = '\0';
    section = VEGETABLES; // Default section
}

Ingredient::Ingredient(const char* ingredientName, eSection ingredientSection) {
    setName(ingredientName);
    section = ingredientSection;
}

char* Ingredient::getName() const {
    return const_cast<char*>(name);
}

Ingredient::eSection Ingredient::getSection() const {
    return section;
}

bool Ingredient::setName(const char* newName) {
    if (newName) {
        strncpy(name, newName, sizeof(name) - 1);
        name[sizeof(name) - 1] = '\0';
        return true;
    }
    return false;
}

bool Ingredient::setSection(eSection newSection) {
    section = newSection;
    return true;
}
