#include "Order.h"
#include <iostream>
using namespace std;

Order::Order() : orderedItems(nullptr), numItems(0) {}

Order::Order(Order&& other) noexcept : orderedItems(other.orderedItems), numItems(other.numItems) {
    other.orderedItems = nullptr;
    other.numItems = 0;
}

Order::~Order() {
    clear();
}

Order& Order::operator=(Order&& other) noexcept {
    if (this != &other) {
        clear();

        orderedItems = other.orderedItems;
        numItems = other.numItems;

        other.orderedItems = nullptr;
        other.numItems = 0;
    }
    return *this;
}

MenuItemInOrder** Order::getOrderedItems() const {
    return orderedItems;
}

bool Order::addItemToOrder(const MenuItem& menuItem) {
    MenuItemInOrder** newOrderedItems = new MenuItemInOrder*[numItems + 1];
    for (int i = 0; i < numItems; ++i) {
        newOrderedItems[i] = orderedItems[i];
    }
    newOrderedItems[numItems] = new MenuItemInOrder(menuItem, 1);  // Assuming 1 quantity by default
    delete[] orderedItems;
    orderedItems = newOrderedItems;
    numItems++;
    return true;
}

int Order::closeBill() const {
    if (!orderedItems) {
        return 0;
    }
    int total = 0;
    for (int i = 0; i < numItems; ++i) {
        // Assuming MenuItemInOrder has a method to get the total price of the item
        // total += orderedItems[i]->getPrice();
    }
    return total;
}

void Order::print() const {
    cout << "Ordered Items:" << endl;
    if (orderedItems) {
        for (int i = 0; i < numItems; ++i) {
            // Assuming MenuItemInOrder has a print method
            // orderedItems[i]->print();
        }
    }
    else {
        cout << "No items in the order." << endl;
    }
}

void Order::clear() {
    if (orderedItems) {
        for (int i = 0; i < numItems; ++i) {
            delete orderedItems[i];
        }
        delete[] orderedItems;
    }
    orderedItems = nullptr;
    numItems = 0;
}
