#pragma warning (disable: 4996)

#include "Ingredient.h"

const char* sections[] = { "Herbs","Dairy","Meat","Fish","Vegetables" };

Ingredient::Ingredient() 
{
    name[0] = '\0';
    section = VEGETABLES; // Default section
    quantityIng = 0;
}

Ingredient::Ingredient(std::string& ingredientName, eSection ingredientSection, int quantity)
{
    strcpy(name,ingredientName);
    //setName(ingredientName);
    section = ingredientSection;
    quantityIng = quantity;
}

bool Ingredient::setName(std::string& newName)
{
    if (!newName.empty()) 
    {
        name = newName;  // השמה פשוטה באמצעות std::string
        return true;
    }
    return false;
}

bool Ingredient::setSection(eSection newSection) 
{
    section = newSection;
    return true;
}

bool Ingredient::setQuantity(int quantity)
{
    quantityIng = quantity;
    return true;
}


void Ingredient::print()
{
    cout << "Ingredient Name: " << name << endl;
    cout << "Section: " << sections[(int)section] << endl;
}
