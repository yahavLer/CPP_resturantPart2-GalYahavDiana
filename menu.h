#pragma once

struct MenuItem;

class Menu
{
private:
	MenuItem** menuItems;
	MenuItem** specials;

public:
	Menu();
	Menu(const Menu& other) = delete;
	Menu(Menu&& other);
	~Menu();
	const Menu& operator=(const Menu& other);
	const Menu& operator=(Menu&& other);


	MenuItem** getMenuItems() const;
	MenuItem** getSpecials() const;
	bool addItemToMenu(const MenuItem& menuItem, bool special);
	bool removeItemFromMenu(MenuItem& menuItem);

	void print() const;
};