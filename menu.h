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

	// Menu(const Menu &other) = delete;
	// const Menu &operator=(const Menu &other);
	Menu &operator=(Menu &&other) noexcept;
	MenuItem **getMenuItems() const;
	MenuItem **getSpecials() const;
	bool addItemToMenu(MenuItem* menuItem, bool special);
	bool removeItemFromMenu(MenuItem &menuItem);

	void print() const;

private: 
	void clear();
};