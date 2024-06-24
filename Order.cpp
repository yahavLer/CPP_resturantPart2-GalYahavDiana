#include <iostream>
using namespace std;

#include "Order.h"

// Assuming basic structure and methods for MenuItem and MenuItemInOrder
struct MenuItem {
    // Members and methods for MenuItem
};

Order::Order() : orderedItems(nullptr) {
    // Default constructor implementation
}

Order::Order(Order&& other) : orderedItems(other.orderedItems) {
    other.orderedItems = nullptr;
}

Order::~Order() {
    delete[] orderedItems;
}

const Order& Order::operator=(const Order& other) {
    if (this == &other) return *this;

    delete[] orderedItems;

    // Assuming deep copy logic for MenuItemInOrder pointers
    // orderedItems = new MenuItemInOrder*[other.getOrderedItemsSize()];
    // Deep copy code here

    return *this;
}

const Order& Order::operator=(Order&& other) {
    if (this == &other) return *this;

    delete[] orderedItems;

    orderedItems = other.orderedItems;
    other.orderedItems = nullptr;

    return *this;
}

MenuItemInOrder**& Order::getOrderedItems() const {
    return const_cast<MenuItemInOrder**&>(orderedItems);
}

bool Order::addItemToOrder(const MenuItem& menuItem) {
    // Logic to add item to order
    // This could involve resizing the array and adding the new item
    return true;
}

int Order::closeBill() const {
    if (!orderedItems) {
        return 0;
    }
    int total = 0;
    // Logic to calculate the total bill from orderedItems
    // for (int i = 0; i < getOrderedItemsSize(); ++i) {
    //     total += orderedItems[i]->getPrice();
    // }
    return total;
}

void Order::print() const {
    cout << "Ordered Items:" << endl;
    if (orderedItems) {
        // Print each ordered item
        // for (int i = 0; i < getOrderedItemsSize(); ++i) {
        //     orderedItems[i]->print();
        // }
    }
    else {
        cout << "No items in the order." << endl;
    }
}