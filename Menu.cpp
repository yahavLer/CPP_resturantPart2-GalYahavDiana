#pragma warning (disable: 4996)

#include <iostream>
#include "menu.h"
#include "drinkItem.h"
#include "foodItem.h"
#include "Observer.h"

// Initialize static instance pointer to nullptr
Menu* Menu::instance = nullptr;


//private constructor 
Menu::Menu() : menuItems(), specials() {}

// private distructor
Menu::~Menu()
{
    clear();
    cout << "menu destroyed.\n";
}

// Static method to get the singleton instance
Menu* Menu::getInstance()
{
    if (instance == nullptr) 
    {
        instance = new Menu();
    }
    return instance;
}


list<MenuItem*>& Menu::getMenuItems() const
{
    return const_cast<list<MenuItem*>&>(menuItems);
}

list<MenuItem*>& Menu::getSpecials() const
{
    return const_cast<list<MenuItem*>&>(specials);
}


bool Menu::addItemToMenu(MenuItem* menuItem, bool special, int notify) 
{

    if (special) 
    {    
        specials.push_back(menuItem);
    }
    else 
    {
        menuItems.push_back(menuItem);
   
    }
    notifyObservers((*menuItem), notify);

    return true;
}


MenuItem* Menu::getItemByIndex(int index) const 
{
	if (index < menuItems.size()) 
    {
        list<MenuItem*>::const_iterator it = menuItems.begin();
        advance(it, index);
        return *it;
	}
	else if (index < menuItems.size() + specials.size()) 
    {
        list<MenuItem*>::const_iterator it = specials.begin();
        advance(it, index - menuItems.size());
		return *it;
	}
	return nullptr;
}


void Menu::print() const 
{
    cout << "--------------------------------------------------------------------------\n" << "Menu Items : "<<endl;
    int i = 1;
    for (MenuItem* menuItem: menuItems)
    {
        cout<< "No."<< i << endl;
        cout << menuItem->getName() << ".............................." << menuItem->getPrice() << "$" << endl;
        list<Ingredient*> toPrint = menuItem->getIngredientList();
        for (Ingredient* ingredient : toPrint)
        {
            cout << ingredient->getName() << ", ";
        }
		cout << endl << endl;
        ++i;
    }

    cout << "Specials:" << endl;
    for (MenuItem* menuItem : specials)
    {
        cout << "No." << i << endl;
        cout << menuItem->getName() << ".............................." << menuItem->getPrice() << "$" << endl;
        list<Ingredient*> toPrint = menuItem->getIngredientList();
        for (Ingredient* ingredient : toPrint)
        {
            cout << ingredient->getName() << ", ";
        }
        cout << endl << endl;
        ++i;
    }
    cout << "--------------------------------------------------------------------------" << endl;
}

// Observer functions
void Menu::addObserver(Observer* observer)
{
    observers.push_back(observer);
}

void Menu::removeObserver(Observer* observer)
{
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Menu::notifyObservers(const MenuItem& mealName, int notify) 
{
     
    if (notify == 0)
        observers.front()->update(mealName);  // notifies the bar about new drink
    else
        observers.back()->update(mealName);   // notifies the kitchen about new meal
    
}

// Private function for clearing the menu
void Menu::clear()
{
    for (MenuItem* item : menuItems) 
    {
        delete item;
    }
    menuItems.clear(); 

    for (MenuItem* item : specials) 
    {
        delete item;
    }
    specials.clear(); 
}