#include "Order.h"
#include <iostream>
using namespace std;

Order::Order() : orderedItems(nullptr), numItems(0) {}

Order::Order(const Order& other) : orderedItems(nullptr), numItems(0) {
    if (other.orderedItems) {
        orderedItems = new MenuItemInOrder*[other.numItems];
        for (int i = 0; i < other.numItems; ++i) {
            orderedItems[i] = new MenuItemInOrder(*other.orderedItems[i]);
        }
        numItems = other.numItems;
    }
}

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

bool Order::addItemToOrder(const MenuItem& menuItem, int quantity, char *comments) {
    MenuItemInOrder** newOrderedItems = new MenuItemInOrder*[numItems + 1];
    for (int i = 0; i < numItems; ++i) {
        newOrderedItems[i] = orderedItems[i];
    }
    newOrderedItems[numItems] = new MenuItemInOrder(menuItem, quantity, comments);  
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
        total += orderedItems[i]->getMenuItem()->getPrice() * orderedItems[i]->getQuantity();
    }
    return total;
}

void Order::print() const {
    cout << "Ordered Items:" << endl;
    if (orderedItems) {
        for (int i = 0; i < numItems; ++i) {
            orderedItems[i]->print();
        }
        cout << "Total: " << closeBill() << endl;
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
