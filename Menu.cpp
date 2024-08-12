#pragma warning (disable: 4996)

#include <iostream>
using namespace std;
#include "menu.h"

Menu::Menu() : menuItems(nullptr), specials(nullptr), menuItemCount(0), specialsCount(0) {}

Menu::Menu(Menu&& other) noexcept : menuItems(other.menuItems), specials(other.specials),
                                    menuItemCount(other.menuItemCount), specialsCount(other.specialsCount) {
    other.menuItems = nullptr;
    other.specials = nullptr;
    other.menuItemCount = 0;
    other.specialsCount = 0;
}

Menu::~Menu() {
    clear();
}

// const Menu& Menu::operator=(const Menu& other) {
//     if (this == &other) return *this;

//     // Deep copy logic, assuming deep copy of MenuItem pointers is required
//     delete[] menuItems;
//     delete[] specials;

//     // Assuming some method to get the count of items to allocate the correct size
//     // Here you would also need to allocate and copy each MenuItem
//     // menuItems = new MenuItem*[other.getMenuItemCount()];
//     // specials = new MenuItem*[other.getSpecialsCount()];

//     // Deep copy code here

//     return *this;
// }

Menu& Menu::operator=(Menu&& other) noexcept {
    if (this != &other) {
        clear();

        menuItems = other.menuItems;
        specials = other.specials;
        menuItemCount = other.menuItemCount;
        specialsCount = other.specialsCount;

        other.menuItems = nullptr;
        other.specials = nullptr;
        other.menuItemCount = 0;
        other.specialsCount = 0;
    }
    return *this;
}

MenuItem** Menu::getMenuItems() const {
    return menuItems;
}

MenuItem** Menu::getSpecials() const {
    return specials;
}

bool Menu::addItemToMenu(const MenuItem& menuItem, bool special) {
    if (special) {
        MenuItem** newSpecials = new MenuItem*[specialsCount + 1];
        for (int i = 0; i < specialsCount; ++i) {
            newSpecials[i] = specials[i];
        }
        newSpecials[specialsCount] = new MenuItem(menuItem);
        delete[] specials;
        specials = newSpecials;
        specialsCount++;
    } else {
        MenuItem** newMenuItems = new MenuItem*[menuItemCount + 1];
        for (int i = 0; i < menuItemCount; ++i) {
            newMenuItems[i] = menuItems[i];
        }
        newMenuItems[menuItemCount] = new MenuItem(menuItem);
        delete[] menuItems;
        menuItems = newMenuItems;
        menuItemCount++;
    }
    return true;
}

bool Menu::removeItemFromMenu(MenuItem& menuItem) {
    // Logic to remove item from menu
    // This could involve finding the item and removing it from the array
    return true;
}

void Menu::print() const {
    std::cout << "Menu Items:" << std::endl;
    for (int i = 0; i < menuItemCount; ++i) {
        // assuming MenuItem has a print method
        // menuItems[i]->print();
    }

    std::cout << "Specials:" << std::endl;
    for (int i = 0; i < specialsCount; ++i) {
        // assuming MenuItem has a print method
        // specials[i]->print();
    }
}

void Menu::clear() {
    if (menuItems) {
        for (int i = 0; i < menuItemCount; ++i) {
            delete menuItems[i];
        }
        delete[] menuItems;
        menuItems = nullptr;
    }
    if (specials) {
        for (int i = 0; i < specialsCount; ++i) {
            delete specials[i];
        }
        delete[] specials;
        specials = nullptr;
    }
    menuItemCount = 0;
    specialsCount = 0;
}