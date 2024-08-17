#include <iostream>
using namespace std;

#include "MenuItemInOrder.h"

// Constructor without arguments
MenuItemInOrder::MenuItemInOrder() : menuItem(nullptr), quantity(0) {
    comment[0] = '\0'; // Initialize comment as an empty string
}

// Constructor with menuItem, quantity, and comment
MenuItemInOrder::MenuItemInOrder(const MenuItem &menuItem, int quantity, const char* comment)
    : menuItem(menuItem.clone()), quantity(quantity) {
    setComment(comment);
}

// Constructor with menuItem and quantity only
MenuItemInOrder::MenuItemInOrder(MenuItem* menuItem, int quantity)
    : menuItem(menuItem), quantity(quantity) {
    comment[0] = '\0'; // Initialize comment as an empty string
}

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

const char* MenuItemInOrder::getComment() const {
    return comment;
}

bool MenuItemInOrder::setQuantity(int quantity) {
    if (quantity >= 0) {
        this->quantity = quantity;
        return true;
    }
    return false;
}

bool MenuItemInOrder::setComment(const char* comment) {
    // Copy the comment into member variable, ensuring it's null-terminated
    int i = 0;
    while (comment[i] != '\0' && i < sizeof(this->comment) - 1) {
        this->comment[i] = comment[i];
        i++;
    }
    this->comment[i] = '\0';
    return true;
}

void MenuItemInOrder::print() const {
    if (menuItem != nullptr) {
        menuItem->print();  // ����� ������ print �� �-MenuItem (����� �����)
    }
    else {
        std::cout << "No menu item assigned." << std::endl;
    }

    std::cout << "Quantity: " << quantity << std::endl;

    if (strlen(comment) > 0) {
        std::cout << "Comment: " << comment << std::endl;
    }
}

