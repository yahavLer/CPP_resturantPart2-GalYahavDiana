#pragma warning (disable: 4996)

#include <iostream>
using namespace std;
#include "menu.h"
#include "drinkItem.h"
#include "foodItem.h"

// Initialize static instance pointer to nullptr
Menu* Menu::instance = nullptr;

Menu::Menu() : menuItems(nullptr), specials(nullptr), menuItemCount(0), specialsCount(0) {}

/*Menu::Menu(Menu&& other) noexcept : menuItems(other.menuItems), specials(other.specials),
                                    menuItemCount(other.menuItemCount), specialsCount(other.specialsCount) {
    other.menuItems = nullptr;
    other.specials = nullptr;
    other.menuItemCount = 0;
    other.specialsCount = 0;
}*/

// private distructor
Menu::~Menu() {
    clear();
    cout << "menu destroyed.\n";
}

// Static method to get the singleton instance
Menu* Menu::getInstance() {
    if (instance == nullptr) {
        instance = new Menu();
    }
    return instance;
}

/*Menu& Menu::operator=(Menu&& other) noexcept {
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
}*/

MenuItem** Menu::getMenuItems() const {
    return menuItems;
}

MenuItem** Menu::getSpecials() const {
    return specials;
}


bool Menu::addItemToMenu(MenuItem* menuItem, bool special) {
    // Clone the item to be added
    //MenuItem* newItem = menuItem.clone();

    if (special) {                                     
        // Expand the specials array
        MenuItem** newSpecials = new MenuItem * [specialsCount + 1];
        for (int i = 0; i < specialsCount; ++i) {
            newSpecials[i] = specials[i];
        }
        newSpecials[specialsCount] = menuItem;  // Add new item to the end
        delete[] specials;
        specials = newSpecials;
        specialsCount++;
    }
    else {
        // Expand the menuItems array
        MenuItem** newMenuItems = new MenuItem * [menuItemCount + 1];
        for (int i = 0; i < menuItemCount; ++i) {
            newMenuItems[i] = menuItems[i];
        }
        newMenuItems[menuItemCount] = menuItem;  // Add new item to the end
        delete[] menuItems;
        menuItems = newMenuItems;
        menuItemCount++;
    }

    return true;
}

/*bool Menu::removeItemFromMenu(MenuItem& menuItem) {
    // Logic to remove item from menu
    // This could involve finding the item and removing it from the array
    return true;
}*/

MenuItem* Menu::getItemByIndex(int index) const {
	if (index < menuItemCount) {
		return menuItems[index];
	}
	else if (index < menuItemCount + specialsCount) {
		return specials[index - menuItemCount];
	}
	return nullptr;
}

void Menu::print() const {
    cout << "Menu Items:\n" << endl;
    int i = 0;
    for (; i < menuItemCount; ++i) {
        cout<<i <<endl;
        menuItems[i]->print();
		cout << endl;
    }

    cout << "Specials:" << endl;
    for (int j = 0;j < specialsCount; ++j, ++i) {
        cout << i << endl;
        specials[j]->print();
        cout << endl;
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