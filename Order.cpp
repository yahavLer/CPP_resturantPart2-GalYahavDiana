#include "Order.h"
#include <iostream>
using namespace std;

Order::Order() : orderedItems() {}

Order::Order(const Order& other) : orderedItems() {
    /*if (other.orderedItems) {
        orderedItems = new MenuItemInOrder*[other.numItems];
        for (int i = 0; i < other.numItems; ++i) {
            orderedItems[i] = new MenuItemInOrder(*other.orderedItems[i]);
        }
        numItems = other.numItems;
    }*/
	for (auto item : other.orderedItems) {
		orderedItems.push_back(new MenuItemInOrder(*item));
	}
}

Order::Order(Order&& other) noexcept : orderedItems(move(other.orderedItems)) {}

Order::~Order() {
    clear();
}

// Move Assignment Operator
Order& Order::operator=(Order&& other) noexcept {
    if (this != &other) {
        clear();
        orderedItems = move(other.orderedItems);
    }
    return *this;
}

const list<MenuItemInOrder*>& Order::getOrderedItems() const {
    return orderedItems;
}

//bool Order::addItemToOrder(const MenuItem& menuItem, int quantity, std::string& comments) {
//    MenuItemInOrder** newOrderedItems = new MenuItemInOrder*[numItems + 1];
//    for (int i = 0; i < numItems; ++i) {
//        newOrderedItems[i] = orderedItems[i];
//    }
//    newOrderedItems[numItems] = new MenuItemInOrder(menuItem, quantity, comments);  
//    delete[] orderedItems;
//    orderedItems = newOrderedItems;
//    numItems++;
//    return true;
//}

// Add Item to Order
bool Order::addItemToOrder(const MenuItem& menuItem, int quantity, const string& comments) {
    orderedItems.push_back(new MenuItemInOrder(menuItem, quantity, comments));
    return true;
}

//int Order::closeBill() const {
//    if (!orderedItems) {
//        return 0;
//    }
//    int total = 0;
//    for (int i = 0; i < numItems; ++i) {
//        total += orderedItems[i]->getMenuItem()->getPrice() * orderedItems[i]->getQuantity();
//    }
//    return total;
//}

// Close Bill
int Order::closeBill() const {
    int total = 0;
    for (auto item : orderedItems) {
        total += item->getMenuItem()->getPrice() * item->getQuantity();
    }
    return total;
}

void Order::print() const {
    cout << "Ordered Items:" << endl;
    if (!orderedItems.empty()) {
        for (auto item : orderedItems) {
            item->print();
        }
        cout << "Total: " << closeBill() << endl;
    }
    else {
        cout << "No items in the order." << endl;
    }
}

void Order::clear() {
	for (auto item : orderedItems) {
		delete item;
	}
	orderedItems.clear();
}

//void Order::clear() {
//    if (orderedItems) {
//        for (int i = 0; i < numItems; ++i) {
//            delete orderedItems[i];
//        }
//        delete[] orderedItems;
//    }
//    orderedItems = nullptr;
//    numItems = 0;
//}
