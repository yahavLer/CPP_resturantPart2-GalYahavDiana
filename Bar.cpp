#pragma warning (disable: 4996)

#include <iostream>
using namespace std;
#include "bar.h"
#include "drinkItem.h"

// Default constructor
Bar::Bar():Department(),drinkItemList(nullptr) {
}

// Move constructor
Bar::Bar(Bar&& other) noexcept : Department(std::move(other)), drinkItemList(other.drinkItemList) {
    other.drinkItemList = nullptr;
}

// Destructor
Bar::~Bar() {
    delete[] drinkItemList;
}

// Move assignment operator
const Bar& Bar::operator=(Bar&& other) {
    if (this != &other) {
        Department::operator=(std::move(other));

        delete[] drinkItemList;
        drinkItemList = other.drinkItemList;
        other.drinkItemList = nullptr;
    }
    return *this;
}

// Get number of workers
int Bar::getNumOfWorkers() const {
    return Department::getNumOfWorkers();
}

// Update ingredient quantity in the warehouse
bool Bar::updateIngredientQuantity(const char* name, int quantity) {
    return Department::updateIngredientQuantity(name, quantity);
}

// Add ingredient to the warehouse
bool Bar::addIngredientToWarehouse(const char* ingredientName, int section) {
    return Department::addIngredientToWarehouse(ingredientName, section);
}

// Get drink item list
DrinkItem** Bar::getDrinkItemList() const {
    return drinkItemList;
}

// Get warehouse
inline const Warehouse& Bar::getWareHouse() const {
    return wareHouse;
}

void Bar::print() {
    cout << "Bar Department:" << endl;
    cout << "Number of Workers: " << getNumOfWorkers() << endl;

    if (drinkItemList) {
        cout << "Drink Items in the Bar:" << endl;
        // הנחה שיש לך פונקציה שתדפיס את פרטי כל משקה ב-bar
        for (int i = 0; drinkItemList[i] != nullptr; ++i) {
            // דוגמה להדפסה של משקה - הנח שיש לפונקציה זו מתודת print משלה
            drinkItemList[i]->print();
        }
    }
    else {
        cout << "No drinks in the bar." << endl;
    }

    cout << "Warehouse status:" << endl;
    getWareHouse().print();  // הנחה ש-wareHouse כולל פונקציה להדפסת המצב שלו
}
