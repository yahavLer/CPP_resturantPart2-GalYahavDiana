#include <iostream>
using namespace std;

#include "MenuItemInOrder.h"

MenuItemInOrder::MenuItemInOrder() : quantity(0) {
    comment[0] = '\0'; // Initialize comment as an empty string
}

MenuItemInOrder::MenuItemInOrder(const MenuItem& menuItem, int quantity, const char* comment) : menuItem(menuItem), quantity(quantity) {
    // Copy comment into member variable, ensure it's null-terminated
    int i = 0;
    while (comment[i] != '\0' && i < sizeof(this->comment) - 1) {
        this->comment[i] = comment[i];
        i++;
    }
    this->comment[i] = '\0';
}

MenuItemInOrder::MenuItemInOrder(const MenuItem& menuItem, int quantity) : menuItem(menuItem), quantity(quantity) {
    comment[0] = '\0'; // Initialize comment as an empty string
}

MenuItemInOrder operator-(int num, const MenuItemInOrder& item) {
    int newQuantity = num - item.quantity;
    if (newQuantity < 0) newQuantity = 0;
    return MenuItemInOrder(item.menuItem, newQuantity, item.comment);
}

MenuItemInOrder operator-(const MenuItemInOrder& item, int num) {
    int newQuantity = item.quantity - num;
    if (newQuantity < 0) newQuantity = 0;
    return MenuItemInOrder(item.menuItem, newQuantity, item.comment);
}

MenuItemInOrder operator+(int num, const MenuItemInOrder& item) {
    int newQuantity = num + item.quantity;
    return MenuItemInOrder(item.menuItem, newQuantity, item.comment);
}

MenuItemInOrder operator+(const MenuItemInOrder& item, int num) {
    int newQuantity = item.quantity + num;
    return MenuItemInOrder(item.menuItem, newQuantity, item.comment);
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

// MenuItemInOrder MenuItemInOrder::operator++(int) {
//     MenuItemInOrder temp(*this);
//     ++(*this);
//     return temp;
// }

MenuItemInOrder& MenuItemInOrder::operator++() {
    ++quantity;
    return *this;
}

MenuItem& MenuItemInOrder::getMenuItem() const {
    return const_cast<MenuItem&>(menuItem);  // Return non-const reference to allow modification
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

// void MenuItemInOrder::print() const {
//     cout << "Menu Item: " << menuItem.getName() << ", Quantity: " << quantity << ", Comment: " << comment << endl;
// }
