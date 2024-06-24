#pragma warning (disable: 4996)

#include <iostream>
using namespace std;
#include "Menu.h"
#include <iostream>

struct MenuItem {
    // Assuming some members and methods for MenuItem
};

Menu::Menu() : menuItems(nullptr), specials(nullptr) {
    // Constructor implementation
}

Menu::Menu(Menu&& other) : menuItems(other.menuItems), specials(other.specials) {
    other.menuItems = nullptr;
    other.specials = nullptr;
}

Menu::~Menu() {
    // Destructor implementation
    delete[] menuItems;
    delete[] specials;
}

const Menu& Menu::operator=(const Menu& other) {
    if (this == &other) return *this;

    // Deep copy logic, assuming deep copy of MenuItem pointers is required
    delete[] menuItems;
    delete[] specials;

    // Assuming some method to get the count of items to allocate the correct size
    // Here you would also need to allocate and copy each MenuItem
    // menuItems = new MenuItem*[other.getMenuItemCount()];
    // specials = new MenuItem*[other.getSpecialsCount()];

    // Deep copy code here

    return *this;
}

const Menu& Menu::operator=(Menu&& other) {
    if (this == &other) return *this;

    delete[] menuItems;
    delete[] specials;

    menuItems = other.menuItems;
    specials = other.specials;

    other.menuItems = nullptr;
    other.specials = nullptr;

    return *this;
}

MenuItem** Menu::getMenuItems() const {
    return menuItems;
}

MenuItem** Menu::getSpecials() const {
    return specials;
}

bool Menu::addItemToMenu(const MenuItem& menuItem, bool special) {
    // Logic to add item to menu
    // This could involve resizing the array and adding the new item
    return true;
}

bool Menu::removeItemFromMenu(MenuItem& menuItem) {
    // Logic to remove item from menu
    // This could involve finding the item and removing it from the array
    return true;
}

void Menu::print() const {
    // Logic to print the menu items and specials
    std::cout << "Menu Items:" << std::endl;
    // Print menuItems here

    std::cout << "Specials:" << std::endl;
    // Print specials here
}