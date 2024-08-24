#pragma warning(disable : 4996)

#include <iostream>
using namespace std;
#include "FoodItem.h"

FoodItem::FoodItem() : MenuItem(), calories(0), kosher(true) {}

FoodItem::FoodItem(const char* nam, bool isKosher, int price, Ingredient** ingredients, int numOfIngredients, int calories)
    : MenuItem(name,numOfIngredients, ingredients, price), calories(0), kosher(isKosher) {
}

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
        int i = 0;
        while (ingredients[i]) {
            ingredients[i]->print(); // assuming Ingredient has a print method
            i++;
        }
    }
    else {
        cout << "No ingredients listed." << endl;
    }
}

/*FoodItem* FoodItem::clone() const override
{
    return new FoodItem(*this); // returns new copy of the object
}*/
