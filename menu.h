#pragma once

#include "menuItem.h"

class Menu
{
private:
	MenuItem **menuItems;
	MenuItem **specials;
	int menuItemCount;
	int specialsCount;

public:
	Menu();
	Menu(Menu &&other) noexcept;
	~Menu();

	Menu &operator=(Menu &&other) noexcept;
	MenuItem **getMenuItems() const;
	MenuItem **getSpecials() const;
	bool addItemToMenu(MenuItem* menuItem, bool special);
	bool removeItemFromMenu(MenuItem &menuItem);
	MenuItem* getItemByIndex(int index) const;

	void print() const;

private: 
	void clear();
};