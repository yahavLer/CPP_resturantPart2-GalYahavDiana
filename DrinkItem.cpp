
#include <iostream>
using namespace std;
#include "DrinkItem.h"
#include <cstring>

DrinkItem::DrinkItem() {
    name[0] = '\0';
    volume = 0;
    glass = PAPERCUP; // Default glass type
}

DrinkItem::DrinkItem(char* drinkName, int drinkVolume, eGlassType drinkGlass) {
    strncpy(name, drinkName, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
    volume = drinkVolume;
    glass = drinkGlass;
}

char* DrinkItem::getName() const {
    return const_cast<char*>(name);
}

int DrinkItem::getVolume() const {
    return volume;
}

DrinkItem::eGlassType DrinkItem::getGlass() const {
    return glass;
}

bool DrinkItem::setName(char* newName) {
    if (newName) {
        strncpy(name, newName, sizeof(name) - 1);
        name[sizeof(name) - 1] = '\0';
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
