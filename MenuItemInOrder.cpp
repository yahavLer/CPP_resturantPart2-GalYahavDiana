#include <iostream>
using namespace std;

#include "MenuItemInOrder.h"

MenuItemInOrder::MenuItemInOrder() : quantity(0) {
    // Default constructor implementation
    comment[0] = '\0'; // Ensure comment is initialized as an empty string
}

MenuItemInOrder::MenuItemInOrder(const MenuItem& menuItem, int quantity, char& comment) : menuItem(menuItem), quantity(quantity) {
    // Constructor with menuItem, quantity, and comment
    // Copy comment up to 19 characters (with null terminator)
    strncpy(this->comment, &comment, sizeof(this->comment) - 1);
    this->comment[sizeof(this->comment) - 1] = '\0'; // Ensure null termination
}

MenuItemInOrder::MenuItemInOrder(const MenuItem& menuItem, int quantity) : menuItem(menuItem), quantity(quantity) {
    // Constructor with menuItem and quantity (comment defaults to empty)
    comment[0] = '\0'; // Ensure comment is initialized as an empty string
}

MenuItemInOrder operator-(int num, const MenuItemInOrder& item) {
    // Subtract quantity from num and return new MenuItemInOrder with updated quantity
    int newQuantity = num - item.quantity;
    if (newQuantity < 0) newQuantity = 0;
    return MenuItemInOrder(item.menuItem, newQuantity, item.comment);
}

MenuItemInOrder operator-(const MenuItemInOrder& item, int num) {
    // Subtract num from quantity and return new MenuItemInOrder with updated quantity
    int newQuantity = item.quantity - num;
    if (newQuantity < 0) newQuantity = 0;
    return MenuItemInOrder(item.menuItem, newQuantity, item.comment);
}

MenuItemInOrder operator+(int num, const MenuItemInOrder& item) {
    // Add quantity to num and return new MenuItemInOrder with updated quantity
    int newQuantity = num + item.quantity;
    return MenuItemInOrder(item.menuItem, newQuantity, item.comment);
}

MenuItemInOrder operator+(const MenuItemInOrder& item, int num) {
    // Add num to quantity and return new MenuItemInOrder with updated quantity
    int newQuantity = item.quantity + num;
    return MenuItemInOrder(item.menuItem, newQuantity, item.comment);
}

const MenuItemInOrder& MenuItemInOrder::operator+=(int num) {
    // Add num to current quantity
    this->quantity += num;
    return *this;
}

const MenuItemInOrder& MenuItemInOrder::operator-=(int num) {
    // Subtract num from current quantity, ensure quantity doesn't go below 0
    this->quantity -= num;
    if (this->quantity < 0) this->quantity = 0;
    return *this;
}

MenuItemInOrder MenuItemInOrder::operator++(int) {
    // Post-increment operator: increase quantity by 1
    MenuItemInOrder temp(*this);
    ++(*this);
    return temp;
}

const MenuItemInOrder& MenuItemInOrder::operator++() {
    // Pre-increment operator: increase quantity by 1
    ++quantity;
    return *this;
}

MenuItem& MenuItemInOrder::getMenuItem() const {
    return menuItem;
}

int MenuItemInOrder::getQuantity() const {
    return quantity;
}

char* MenuItemInOrder::getComment() const {
    return comment;
}

bool MenuItemInOrder::setQuantity(int quantity) {
    // Set quantity, ensure it's not negative
    if (quantity >= 0) {
        this->quantity = quantity;
        return true;
    }
    return false;
}

bool MenuItemInOrder::setComment(char& comment) {
    // Set comment, copy up to 19 characters (with null terminator)
    strncpy(this->comment, &comment, sizeof(this->comment) - 1);
    this->comment[sizeof(this->comment) - 1] = '\0'; // Ensure null termination
    return true;
}

void MenuItemInOrder::print() const {
    cout << "Menu Item: " << menuItem.getName() << ", Quantity: " << quantity << ", Comment: " << comment << endl;
}