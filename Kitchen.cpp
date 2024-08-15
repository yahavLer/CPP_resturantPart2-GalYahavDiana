#include <iostream>
using namespace std;

#include "Kitchen.h"

Kitchen::Kitchen() : foodItemList(nullptr)
{
}

Kitchen::Kitchen(Kitchen &&other) noexcept : Department(std::move(other)), foodItemList(other.foodItemList)
{
    other.foodItemList = nullptr;
}

Kitchen::~Kitchen()
{
    delete[] foodItemList;
}

Kitchen &Kitchen::operator=(const Kitchen &other)
{
    if (this != &other)
    {
        delete[] foodItemList;
        Department::operator=(other); // Assuming Warehouse has an appropriate assignment operator
        foodItemList = other.foodItemList;
    }

    return *this;
}

Kitchen &Kitchen::operator=(Kitchen &&other) noexcept 
{
    if (this != &other) {
        Department::operator=(std::move(other));  // Move assignment of base class
        delete[] foodItemList;
        foodItemList = other.foodItemList;
        other.foodItemList = nullptr;
    }
    return *this;
}

inline FoodItem **Kitchen::getFoodItemList() const
{
    return foodItemList;
}

bool Kitchen::updateIngredientQuantity(char *name, int quantity)
{
    Ingredient* ingredient = wareHouse->getIngredientByName(name);
    if (ingredient) {
        return wareHouse->updateIngredientQuantity(ingredient, quantity);
    }
    return false;
}

bool Kitchen::addIngredientToWarehouse(char *ingredientName, int section)
{
        return wareHouse->addIngredientToWarehouse(ingredientName, section);
}

void Kitchen::print() {
    cout << "Kitchen Department:" << endl;
    cout << "Number of Workers: " << getNumOfWorkers() << endl;

    if (foodItemList) {
        cout << "Food Items in the Kitchen:" << endl;
        for (int i = 0; foodItemList[i] != nullptr; ++i) {
            foodItemList[i]->print();
        }
    }
    else {
        cout << "No food items in the kitchen." << endl;
    }

    cout << "Warehouse status:" << endl;
    wareHouse->print();  // הנחה ש-wareHouse כולל פונקציה להדפסת המצב שלו
}