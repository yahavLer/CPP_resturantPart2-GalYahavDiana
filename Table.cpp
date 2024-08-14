#include <iostream>
using namespace std;

#include "Table.h"

Table::Table() : order(nullptr), number(0) {}

Table::Table(Table&& other) : order(other.order), number(other.number) {
    other.order = nullptr;
    other.number = 0;
}

Table::~Table() {
    clear();
}

Table::Table(int number) : order(nullptr), number(number) {
    // Constructor with table number
}

// Table& Table::operator=(const Table& other) {
//    if (this != &other) {
//         delete order;
//         if (other.order) {
//             order = new Order(*other.order); 
//         } else {
//             order = nullptr;
//         }
//         // העתקת מספר השולחן
//         number = other.number;
//     }
//     return *this;
// }

// Table& Table::operator=(const Table&& other) {
//     if (this == &other) return *this;
//     delete order;
//     order = other.order;
//     number = other.number;
//     other.order = nullptr;
//     other.number = 0;
//     return *this;
// }

Order* Table::getOrder() const {
    return order;
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
    order = new Order(); 
    return true;
}

bool Table::AddItemToOrder(const MenuItem& menuItem, int quantity, char *comments) {
    if (!order) {
        return false;
    }
    order->addItemToOrder(menuItem, quantity, comments);
    return true;
}

int Table::closeBill() {
    if (!order) {
        return 0;
    }
    order->print();
    int total = 0; // = order->getTotal();
    delete order;
    order = nullptr;
    return total;
}

void Table::printTable() const {
    cout << "Table Number: " << number << endl;
    if (order) {
        order->print();
    }
    else {
        cout << "No current order." << endl;
    }
}