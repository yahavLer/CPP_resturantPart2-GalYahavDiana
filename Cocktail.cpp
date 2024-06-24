#pragma warning (disable: 4996)

#include <iostream>
using namespace std;
#include "Cocktail.h"

Cocktail::Cocktail(int price) : doubleDosePrice(price), alcoholLevel(regular) {}

Cocktail::eAlcoholLevel Cocktail::getAlcoholLevel() const {
    return alcoholLevel;
}

int Cocktail::getDoubleDosePrice() const {
    return doubleDosePrice;
}

bool Cocktail::setAlcoholLevel(eAlcoholLevel newAlcoholLevel) {
    alcoholLevel = newAlcoholLevel;
    return true;
}

bool Cocktail::setDoubleDosePrice(int newPrice) {
    if (newPrice >= 0) {
        doubleDosePrice = newPrice;
        return true;
    }
    return false;
}

void Cocktail::print() const {
    // Implementation for print, could use printf or std::cout
}
