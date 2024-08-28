#pragma warning (disable: 4996)

#include <iostream>
#include "bar.h"
#include "drinkItem.h"

// Default constructor
Bar::Bar():Department(),drinkItemList() {
}

// Move constructor
Bar::Bar(Bar&& other) noexcept : Department(move(other)), drinkItemList(move(other.drinkItemList)) {
}

// Destructor
Bar::~Bar() {
    drinkItemList.clear();
}

// Move assignment operator
const Bar& Bar::operator=(Bar&& other) noexcept {
    if (this != &other) {
        Department::operator=(move(other));
        drinkItemList = move(other.drinkItemList);
    }
    return *this;
}

// Get number of workers
int Bar::getNumOfWorkers() const {
    return Department::getNumOfWorkers();
}

// Update ingredient quantity in the warehouse
bool Bar::updateIngredientQuantity(const string& name, int quantity) {
    return Department::updateIngredientQuantity(name, quantity);
}

// Add ingredient to the warehouse
bool Bar::addIngredientToWarehouse(const string& ingredientName, int section) {
    return Department::addIngredientToWarehouse(ingredientName, section);
}

// Get drink item list
const list<DrinkItem*>& Bar::getDrinkItemList() const {
    return drinkItemList;
}

// Get warehouse
inline const Warehouse& Bar::getWareHouse() const {
    return wareHouse;
}

void Bar::update(const MenuItem& newDrink)
{
    cout << "Bar Notification new drink had been added to menu recently: " << endl;
    cout << newDrink.getName() << endl; 
}

void Bar::print() {
    cout << "Bar Department:" << endl;
    cout << "Number of Workers: " << getNumOfWorkers() << endl;

    if (!drinkItemList.empty()) {
        cout << "Drink Items in the Bar:" << endl;
        for (DrinkItem* drink : drinkItemList) {
            drink->print();
        }
    }
    else {
        cout << "No drinks in the bar." << endl;
    }

    cout << "Warehouse status:" << endl;
    getWareHouse().print();  // הנחה ש-wareHouse כולל פונקציה להדפסת המצב שלו
}
