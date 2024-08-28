#pragma warning (disable: 4996)

#include <iostream>
#include "menu.h"
#include "drinkItem.h"
#include "foodItem.h"

// Initialize static instance pointer to nullptr
Menu* Menu::instance = nullptr;

Menu::Menu() : menuItems(), specials() {}

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

list<MenuItem*>& Menu::getMenuItems() const {
    return const_cast<list<MenuItem*>&>(menuItems);
}

list<MenuItem*>& Menu::getSpecials() const {
    return const_cast<list<MenuItem*>&>(specials);
}


bool Menu::addItemToMenu(MenuItem* menuItem, bool special) {
    // Clone the item to be added
    //MenuItem* newItem = menuItem.clone();

    if (special) {    
        specials.push_back(menuItem);
        // Expand the specials array
         
        //MenuItem** newSpecials = new MenuItem * [specialsCount + 1];
        //for (int i = 0; i < specialsCount; ++i) {
        //    newSpecials[i] = specials[i];
        //}
        //newSpecials[specialsCount] = menuItem;  // Add new item to the end
        //delete[] specials;
        //specials = newSpecials;
        //specialsCount++;
    }
    else {
        menuItems.push_back(menuItem);
        // Expand the menuItems array
        /*
        MenuItem** newMenuItems = new MenuItem * [menuItemCount + 1];
        for (int i = 0; i < menuItemCount; ++i) {
            newMenuItems[i] = menuItems[i];
        }
        newMenuItems[menuItemCount] = menuItem;  // Add new item to the end
        delete[] menuItems;
        menuItems = newMenuItems;
        menuItemCount++;*/
    }

    return true;
}

/*bool Menu::removeItemFromMenu(MenuItem& menuItem) {
    // Logic to remove item from menu
    // This could involve finding the item and removing it from the array
    return true;
}*/

MenuItem* Menu::getItemByIndex(int index) const {
	if (index < menuItems.size()) {
        list<MenuItem*>::const_iterator it = menuItems.begin();
        advance(it, index);
        return *it;
	}
	else if (index < menuItems.size() + specials.size()) {
        list<MenuItem*>::const_iterator it = specials.begin();
        advance(it, index - menuItems.size());
		return *it;
	}
	return nullptr;
}

void Menu::print() const {
    cout << "Menu Items:\n" << "--------------------------------------------------------------------------"<<endl;
    int i = 0;
    for (MenuItem* menuItem: menuItems) {
        cout<<i <<endl;
        menuItem->print();
		cout << endl;
        ++i;
    }

    cout << "Specials:" << endl;
    for (MenuItem* menuItem : specials) {
        cout << i << endl;
        menuItem->print();
        cout << endl;
        ++i;
    }
    cout << "--------------------------------------------------------------------------" << endl;

}

void Menu::clear() {
    for (MenuItem* item : menuItems) {
        delete item;
    }
    menuItems.clear(); 

    for (MenuItem* item : specials) {
        delete item;
    }
    specials.clear(); 
}