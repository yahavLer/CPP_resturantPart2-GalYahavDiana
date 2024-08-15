#include <iostream>
using namespace std;
#include "DrinkItem.h"

const char* DrinkItem::glassTypes[5] = { "Lowball", "Wine", "Beer", "Highball", "Paper cup" };

DrinkItem::DrinkItem() : name(""), volume(0), glass(LOWBOAL) {}


DrinkItem::DrinkItem(const char* drinkName, int drinkVolume, eGlassType drinkGlass)
    : volume(drinkVolume), glass(drinkGlass) {
    setName(drinkName);
}


bool DrinkItem::setName(const char* newName) {
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