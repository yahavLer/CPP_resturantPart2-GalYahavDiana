#pragma warning(disable : 4996)

#include <iostream>
using namespace std;
#include "FoodItem.h"

FoodItem::FoodItem() : calories(0), kosher(true) {}

FoodItem::FoodItem(int foodCalories, bool isKosher) : calories(foodCalories), kosher(isKosher) {}

bool FoodItem::setCalories(int newCalories)
{
    if (newCalories >= 0)
    {
        calories = newCalories;
        return true;
    }
    return false;
}

bool FoodItem::setKosher(bool isKosher)
{
    kosher = isKosher;
    return true;
}
void FoodItem::print() {
    cout << "Food Item:" << endl;
    cout << "Calories: " << getCalories() << endl;
    cout << "Kosher: " << (getKosher() ? "Yes" : "No") << endl;
    cout << "Price: " << getPrice() << endl;

    cout << "Ingredients:" << endl;
    Ingredient** ingredients = getIngredientList();
    if (ingredients) {
        for (int i = 0; i < numOfIngredients; ++i) {
            ingredients[i]->print(); // assuming Ingredient has a print method
        }
    }
    else {
        cout << "No ingredients listed." << endl;
    }
}
