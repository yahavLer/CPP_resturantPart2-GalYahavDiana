#include <iostream>
using namespace std;

#include "MenuItemInOrder.h"

// Constructor without arguments
MenuItemInOrder::MenuItemInOrder() : menuItem(nullptr), quantity(0) {
    comment[0] = '\0'; // Initialize comment as an empty string
}

// Constructor with menuItem, quantity, and comment
MenuItemInOrder::MenuItemInOrder(MenuItem* menuItem, int quantity, const char* comment)
    : menuItem(menuItem), quantity(quantity) {
    // Copy comment into member variable, ensure it's null-terminated
    int i = 0;
    while (comment[i] != '\0' && i < sizeof(this->comment) - 1) {
        this->comment[i] = comment[i];
        i++;
    }
    this->comment[i] = '\0';
}

// Constructor with menuItem and quantity only
MenuItemInOrder::MenuItemInOrder(MenuItem* menuItem, int quantity)
    : menuItem(menuItem), quantity(quantity) {
    comment[0] = '\0'; // Initialize comment as an empty string
}

// Destructor
MenuItemInOrder::~MenuItemInOrder() {
    // Optionally, you might want to manage the menuItem pointer here if it was dynamically allocated
    // delete menuItem; // Uncomment if menuItem was dynamically allocated
}

// Operator overloads for addition and subtraction
MenuItemInOrder operator-(int num, const MenuItemInOrder& item) {
    int newQuantity = num - item.getQuantity();
    if (newQuantity < 0) newQuantity = 0;
    return MenuItemInOrder(item.getMenuItem(), newQuantity, item.getComment());
}

MenuItemInOrder operator-(const MenuItemInOrder& item, int num) {
    int newQuantity = item.getQuantity() - num;
    if (newQuantity < 0) newQuantity = 0;
    return MenuItemInOrder(item.getMenuItem(), newQuantity, item.getComment());
}

MenuItemInOrder operator+(int num, const MenuItemInOrder& item) {
    int newQuantity = num + item.getQuantity();
    return MenuItemInOrder(item.getMenuItem(), newQuantity, item.getComment());
}

MenuItemInOrder operator+(const MenuItemInOrder& item, int num) {
    int newQuantity = item.getQuantity() + num;
    return MenuItemInOrder(item.getMenuItem(), newQuantity, item.getComment());
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
        menuItem->print();  // קריאה למתודת print של ה-MenuItem (מאפשר ירושה)
    }
    else {
        std::cout << "No menu item assigned." << std::endl;
    }

    std::cout << "Quantity: " << quantity << std::endl;

    if (strlen(comment) > 0) {
        std::cout << "Comment: " << comment << std::endl;
    }
}

