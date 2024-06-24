#include <iostream>
using namespace std;

#include "Table.h"

// Assuming a basic structure for Order to be defined
struct Order {
    // Members and methods for Order
    // For example: int items; (number of items)
};

Table::Table() : order(nullptr), number(0) {
    // Default constructor implementation
}

Table::Table(Table&& other) : order(other.order), number(other.number) {
    other.order = nullptr;
    other.number = 0;
}

Table::~Table() {
    delete order;
}

Table::Table(int number) : order(nullptr), number(number) {
    // Constructor with table number
}

const Table& Table::operator=(const Table& other) {
    if (this == &other) return *this;

    delete order;

    // Assuming deep copy logic for Order
    if (other.order) {
        order = new Order(*other.order);
    }
    else {
        order = nullptr;
    }

    number = other.number;

    return *this;
}

const Table& Table::operator=(Table&& other) {
    if (this == &other) return *this;

    delete order;

    order = other.order;
    number = other.number;

    other.order = nullptr;
    other.number = 0;

    return *this;
}

Order* Table::getOrder() const {
    return order;
}

int Table::getNumber() const {
    return number;
}

bool Table::setNumber(int newNumber) {
    if (newNumber > 0) {
        number = newNumber;
        return true;
    }
    return false;
}

bool Table::createNewOrder() {
    if (order) {
        delete order;
    }
    order = new Order();  // Assuming default constructor for Order
    return true;
}

bool Table::AddItemToOrder(int menuItemNum, int quantity) {
    if (!order) {
        return false;
    }
    // Assuming Order has a method to add items, e.g., addItem(menuItemNum, quantity)
    // order->addItem(menuItemNum, quantity);
    return true;
}

int Table::closeBill() {
    if (!order) {
        return 0;
    }
    // Assuming Order has a method to calculate the total, e.g., getTotal()
    int total = 0; // = order->getTotal();
    delete order;
    order = nullptr;
    return total;
}

void Table::printTable() const {
    cout << "Table Number: " << number << endl;
    if (order) {
        // Assuming Order has a method to print details, e.g., printOrder()
        // order->printOrder();
    }
    else {
        cout << "No current order." << endl;
    }
}