#pragma warning (disable: 4996)

#include "Ingredient.h"

const char* sections[] = { "Herbs","Dairy","Meat","Fish","Vegetables" };

Ingredient::Ingredient() {
    name[0] = '\0';
    section = VEGETABLES; // Default section
}

Ingredient::Ingredient(const char* ingredientName, eSection ingredientSection) {
    setName(ingredientName);
    section = ingredientSection;
}

bool Ingredient::setName(const char* newName) {
    if (newName) {
        int i = 0;
        while (i < sizeof(name) - 1 && newName[i] != '\0') {
            name[i] = newName[i];
            i++;
        }
        name[i] = '\0'; 
        return true;
    }
    return false;
}

bool Ingredient::setSection(eSection newSection) {
    section = newSection;
    return true;
}
