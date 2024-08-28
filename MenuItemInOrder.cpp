#include <iostream>
#include "MenuItemInOrder.h"

// Constructor without arguments
MenuItemInOrder::MenuItemInOrder() :menuItem(nullptr), quantity(0), comment("") {}

// Constructor with menuItem, quantity, and comment
MenuItemInOrder::MenuItemInOrder(const MenuItem &menuItem, int quantity, const string& newComment)
    : menuItem(menuItem.clone()), quantity(quantity), comment(newComment){}

// Constructor with menuItem and quantity only
MenuItemInOrder::MenuItemInOrder(MenuItem* menuItem, int quantity)
    :comment(""), menuItem(menuItem), quantity(quantity) {}

// Destructor
MenuItemInOrder::~MenuItemInOrder() 
{
    delete menuItem;
}

// Operator +=
MenuItemInOrder& MenuItemInOrder::operator+=(int num) 
{
    quantity += num;
    return *this;
}

// Operator -=
MenuItemInOrder& MenuItemInOrder::operator-=(int num)
{
    quantity -= num;
	if (quantity < 0) quantity = 0; // Ensure quantity is not negative
    return *this;
}

// Operator +
MenuItemInOrder MenuItemInOrder::operator+(int num) const 
{
    MenuItemInOrder result(*this); // Copy the current object
    result.quantity += num; // Add the number to the quantity
    return result;
}

// Operator -
MenuItemInOrder MenuItemInOrder::operator-(int num) const 
{
    MenuItemInOrder result(*this); // Copy the current object
    result.quantity -= num; // Subtract the number from the quantity
    if (result.quantity < 0) result.quantity = 0; // Ensure quantity is not negative
    return result;
}

// Operator ++ (prefix)
MenuItemInOrder& MenuItemInOrder::operator++()
{
    ++quantity;
    return *this;
}


/**********
* Getters
**********/
MenuItem* MenuItemInOrder::getMenuItem() const
{
    return menuItem;
}

int MenuItemInOrder::getQuantity() const 
{
    return quantity;
}

const string& MenuItemInOrder::getComment() const 
{
    return comment;
}

/**********
* Setters
**********/
bool MenuItemInOrder::setQuantity(int quantity) 
{
    if (quantity >= 0) {
        this->quantity = quantity;
        return true;
    }
    return false;
}

bool MenuItemInOrder::setComment(const string& newComment)
{
    comment = newComment;
	return true;
}

void MenuItemInOrder::print() const 
{
    if (menuItem != nullptr) 
    {
        menuItem->print();  // using print function of menuItem 
    } else
    {
        cout << "No menu item assigned." << endl;
    }

    cout << "Quantity: " << quantity << endl;

    if (comment.length() > 0) 
    {
        cout << "Comment: " << comment << endl;
    }
}

