#pragma warning(disable : 4996)

#include <iostream>
#include "FoodItem.h"

FoodItem::FoodItem() : MenuItem(), calories(0), kosher(true) {}

FoodItem::FoodItem(const string& name, bool kosher, int price, const list<Ingredient*>& ingredients, int calories)
    : MenuItem(name, ingredients, price), calories(0), kosher(kosher) {
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
    cout << "Food Item" << endl;
	cout << "Name: " << getName() << endl;
    cout << "Calories: " << getCalories() << endl;
    cout << "Kosher: " << (getKosher() ? "Yes" : "No") << endl;
    cout << "Price: " << getPrice() << endl;
    cout << "Ingredients:" << endl;
	int i = 0;
	if (!getIngredientList().empty()) {
        for(auto ingredient: ingredientList){
            cout << ++i <<  " ingradient: " << endl;
            ingredient->print(); // assuming Ingredient has a print method
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
