#pragma warning (disable: 4996)

#include <iostream>
using namespace std;
#include "AlcoholicDrink.h"

AlcoholicDrink::AlcoholicDrink() : alcoholPercentage(0) {}

AlcoholicDrink::AlcoholicDrink(int percentage) : alcoholPercentage(percentage) {}

int AlcoholicDrink::getAlcoholPercentage() const {
    return alcoholPercentage;
}

bool AlcoholicDrink::setAlcoholPercentage(int percentage) {
    if (percentage >= 0 && percentage <= 100) {
        alcoholPercentage = percentage;
        return true;
    }
    return false;
}
