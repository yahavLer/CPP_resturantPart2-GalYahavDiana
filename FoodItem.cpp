#pragma warning (disable: 4996)

#include <iostream>
using namespace std;
#include "FoodItem.h"

FoodItem::FoodItem() : calories(0), kosher(true) {}

FoodItem::FoodItem(int foodCalories, bool isKosher) : calories(foodCalories), kosher(isKosher) {}

int FoodItem::getCalories() const {
    return calories;
}

bool FoodItem::getKosher() const {
    return kosher;
}

bool FoodItem::setCalories(int newCalories) {
    if (newCalories >= 0) {
        calories = newCalories;
        return true;
    }
    return false;
}

bool FoodItem::setKosher(bool isKosher) {
    kosher = isKosher;
    return true;
}
