#include <iostream>
using namespace std;
#include "DrinkItem.h"

const char* DrinkItem::glassTypes[5] = { "Lowball", "Wine", "Beer", "Highball", "Paper cup" };

DrinkItem::DrinkItem() : MenuItem(), volume(0), glass(LOWBOAL) {}


// ���� �� �������
DrinkItem::DrinkItem(const char* drinkName, int drinkVolume, eGlassType drinkGlass, int price, Ingredient** ingredients, int numOfIngredients)
    : MenuItem(drinkName, numOfIngredients, ingredients, price), volume(drinkVolume), glass(drinkGlass) {}


// ���� �����
DrinkItem::DrinkItem(const DrinkItem& other)
    : MenuItem(other), volume(other.volume), glass(other.glass) {}

// ������� ����
DrinkItem& DrinkItem::operator=(const DrinkItem& other) {
    if (this != &other) {
        MenuItem::operator=(other);
        volume = other.volume;
        glass = other.glass;
    }
    return *this;
}


bool DrinkItem::setVolume(int newVolume) {
    if (newVolume >= 0) {
        volume = newVolume;
        return true;
    }
    return false;
}

bool DrinkItem::setGlass(eGlassType newGlass) {
    glass = newGlass;
    return true;
}
void DrinkItem::print() {
    cout << "Drink Item:" << endl;
    cout << "Name: " << getName() << endl;
    cout << "Volume: " << getVolume() << " ml" << endl;
    cout << "Glass Type: " << glassTypes[getGlass()] << endl;
    cout << "Price: " << getPrice() << endl;

    cout << "Ingredients:" << endl;
    Ingredient** ingredients = getIngredientList();
    if (ingredients) {
        int i = 0;
        while (ingredients[i] != nullptr) {
            ingredients[i]->print(); // assuming Ingredient has a print method
            i++;
        }
    }
    else {
        cout << "No ingredients listed." << endl;
    }
}

DrinkItem* DrinkItem::clone() const {
    return new DrinkItem(*this); // יצירת עותק חדש של האובייקט הנוכחי
}