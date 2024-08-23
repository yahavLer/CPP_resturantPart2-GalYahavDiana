#pragma warning (disable: 4996)

#include <iostream>
using namespace std;
#include "Cocktail.h"

const char* alcoholLevelNames[] = { "regular","doubleDose","weak","virgin" };

Cocktail::Cocktail(int doubleDosePrice)
    : DrinkItem(), AlcoholicDrink(), alcoholLevel(regular), doubleDosePrice(doubleDosePrice) {}

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
    std::cout << "Cocktail details:" << std::endl;
    std::cout << "Alcohol Level: " << alcoholLevel << std::endl;
    std::cout << "Double Dose Price: " << doubleDosePrice << std::endl;
}
