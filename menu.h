#pragma once

#include "menuItem.h"
#include "Observer.h"
#include <list>  // Include the list header
using namespace std;

// convert the menu of the restaurant into singleton
class Menu
{
private:
	/*MenuItem **menuItems;
	MenuItem **specials;
	int menuItemCount;
	int specialsCount;*/

	list<MenuItem*> menuItems;
	list<MenuItem*> specials;
	list<Observer*> observers;
	static Menu* instance;  // Static instance of Menu

	// Deleted copy constructor and assignment operator to prevent copying
	Menu(const Menu&) = delete;
	Menu& operator=(const Menu&) = delete;

	// Private constructor to prevent direct instantiation
	Menu();

	// Deleted move constructor and move assignment operator to prevent moving
	Menu(Menu&&) = delete;
	Menu& operator=(Menu&&) = delete;

	// Private destructor to prevent direct destruction
	~Menu();
	
public:
	static Menu* getInstance();

	//MenuItem **getMenuItems() const;
	//MenuItem **getSpecials() const;
	list<MenuItem*>& getMenuItems() const;
	list<MenuItem*>& getSpecials() const;

	bool addItemToMenu(MenuItem* menuItem, bool special, int notify);
	MenuItem* getItemByIndex(int index) const;
	void print() const;
	//bool removeItemFromMenu(MenuItem &menuItem);   - not defiened in the PDF file.

	// observer functions
	void addObserver(Observer* observer);
	void removeObserver(Observer* observer);
	void notifyObservers(const MenuItem& mealName, int notify);
private: 
	void clear();
};