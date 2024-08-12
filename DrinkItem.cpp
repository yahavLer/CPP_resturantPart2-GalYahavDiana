#include <iostream>
using namespace std;
#include "DrinkItem.h"

const char* DrinkItem::glassTypes[5] = { "Lowball", "Wine", "Beer", "Highball", "Paper cup" };

DrinkItem::DrinkItem() {
    name[0] = '\0';
    volume = 0;
    glass = PAPERCUP; // Default glass type
}

DrinkItem::DrinkItem(const char* drinkName, int drinkVolume, eGlassType drinkGlass) {
    setName(drinkName);
    volume = drinkVolume;
    glass = drinkGlass;
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
