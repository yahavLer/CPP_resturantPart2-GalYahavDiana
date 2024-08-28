#include <iostream>

#include "Kitchen.h"

Kitchen::Kitchen() : foodItemList()
{
}

Kitchen::Kitchen(Kitchen &&other) noexcept : Department(move(other)), foodItemList(move(other.foodItemList))
{
}

Kitchen::~Kitchen()
{
    foodItemList.clear();
}

Kitchen &Kitchen::operator=(const Kitchen &other)
{
    if (this != &other)
    {
        Department::operator=(move(other)); 
        foodItemList = other.foodItemList;
    }
    return *this;
}

Kitchen &Kitchen::operator=(Kitchen &&other) noexcept 
{
    if (this != &other) {
        Department::operator=(move(other));  // Move assignment of base class
        foodItemList = move(other.foodItemList);
    }
    return *this;
}

list<FoodItem*>& Kitchen::getFoodItemList()
{
    return foodItemList;
}

bool Kitchen::updateIngredientQuantity(string& name, int quantity)
{
    Ingredient* ingredient = wareHouse.getIngredientByName(name);
    if (ingredient) {
        return wareHouse.updateIngredientQuantity(ingredient, quantity);
    }
    return false;
}

bool Kitchen::addIngredientToWarehouse(string& ingredientName, int section)
{
    return wareHouse.addIngredientToWarehouse(ingredientName, section);
}

void Kitchen::update(const MenuItem& newMeal)
{
    cout << "Kitchen Notification: new meal had been added to menu recently: " << endl;
    cout << newMeal.getName() << endl;
}

void Kitchen::print() {
    cout << "Kitchen Department:" << endl;
    cout << "Number of Workers: " << getNumOfWorkers() << endl;

    if (!foodItemList.empty()) {
        cout << "Food Items in the Kitchen:" << endl;
        for (FoodItem* food : foodItemList) {
            food->print();
        }
    }
    else {
        cout << "No food items in the kitchen." << endl;
    }

    cout << "Warehouse status:" << endl;
    wareHouse.print();
}