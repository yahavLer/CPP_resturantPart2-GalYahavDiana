#pragma warning (disable: 4996)

#include "Ingredient.h"

const char* sections[] = { "Herbs","Dairy","Meat","Fish","Vegetables" };

Ingredient::Ingredient() : name(""), section(VEGETABLES), quantityIng(0){}

Ingredient::Ingredient(const string& ingredientName, eSection ingredientSection, int quantity)
    : name(ingredientName), section(ingredientSection), quantityIng(quantity) {}

bool Ingredient::setName(const string& newName)
{
    if (newName != "")
    {
        name = newName;
        return true;
    }
     
    return false;
}

bool Ingredient::setSection(eSection newSection) 
{
    if (newSection >= 0 && newSection < 5)
    {
        section = newSection;
        return true;
    }

    return false;
}

bool Ingredient::setQuantity(int quantity)
{
    if (quantity > 0)
    {
        quantityIng = quantity;
        return true;
    }

    return false;
}


void Ingredient::print()
{
    cout << "Ingredient Name: " << name << endl;
    cout << "Section: " << sections[(int)section] << endl;
}
