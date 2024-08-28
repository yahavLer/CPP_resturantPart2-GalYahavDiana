#ifndef __MENU_H
#define __MENU_H

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
	// bool removeItemFromMenu(MenuItem &menuItem); - not defined in the story pdf. 
	MenuItem* getItemByIndex(int index) const;

	void print() const;

private: 
	void clear();
};

#endif // __MENU_H