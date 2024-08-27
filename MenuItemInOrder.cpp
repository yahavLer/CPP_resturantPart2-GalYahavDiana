#include <iostream>
using namespace std;

#include "MenuItemInOrder.h"

// Constructor without arguments
MenuItemInOrder::MenuItemInOrder() :comment(""), menuItem(nullptr), quantity(0) {
    comment[0] = '\0'; // Initialize comment as an empty string
}

// Constructor with menuItem, quantity, and comment
MenuItemInOrder::MenuItemInOrder(const MenuItem &menuItem, int quantity, const std::string& newComment)
    : menuItem(menuItem.clone()), quantity(quantity), comment(newComment){}

// Constructor with menuItem and quantity only
MenuItemInOrder::MenuItemInOrder(MenuItem* menuItem, int quantity)
    :comment(""), menuItem(menuItem), quantity(quantity) {}

// Destructor
MenuItemInOrder::~MenuItemInOrder() {
    delete menuItem;
}


MenuItemInOrder& MenuItemInOrder::operator+=(int num) {
    this->quantity += num;
    return *this;
}

MenuItemInOrder& MenuItemInOrder::operator-=(int num) {
    this->quantity -= num;
    if (this->quantity < 0) this->quantity = 0;
    return *this;
}

// Operator +
MenuItemInOrder MenuItemInOrder::operator+(int num) {
    MenuItemInOrder result(*this); // Copy the current object
    result.quantity += num; // Add the number to the quantity
    return result;
}

// Operator -
MenuItemInOrder MenuItemInOrder::operator-(int num) {
    MenuItemInOrder result(*this); // Copy the current object
    result.quantity -= num; // Subtract the number from the quantity
    if (result.quantity < 0) result.quantity = 0; // Ensure quantity is not negative
    return result;
}

MenuItemInOrder& MenuItemInOrder::operator++() {
    ++quantity;
    return *this;
}

MenuItem* MenuItemInOrder::getMenuItem() const {
    return menuItem;
}

int MenuItemInOrder::getQuantity() const {
    return quantity;
}

const std::string MenuItemInOrder::getComment() const {
    return comment;
}

bool MenuItemInOrder::setQuantity(int quantity) {
    if (quantity >= 0) {
        this->quantity = quantity;
        return true;
    }
    return false;
}

bool MenuItemInOrder::setComment(const std::string& newComment) {
    if (comment == "") {
        comment = newComment; // אם המחרוזת היא nullptr, נוודא שה-comment יהיה ריק
        return true;
    }
    return false;
}

void MenuItemInOrder::print() const {
    if (menuItem != nullptr) {
        menuItem->print();  // ����� ������ print �� �-MenuItem (����� �����)
    }
    else {
        cout << "No menu item assigned." << endl;
    }

    cout << "Quantity: " << quantity << endl;

    if (comment.length() > 0) {
        cout << "Comment: " << comment << endl;
    }
}

