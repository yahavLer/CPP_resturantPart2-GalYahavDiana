#pragma once

#include "menuItem.h"

class MenuItemInOrder
{
private:
	MenuItem menuItem;
	int quantity;
	char comment[20];

public:
	MenuItemInOrder();
	MenuItemInOrder(const MenuItem& menuItem, int quantity, char& comment);
	MenuItemInOrder(const MenuItem& menuItem, int quantity);
	friend MenuItemInOrder operator-(int num, const MenuItemInOrder& item);
	friend MenuItemInOrder operator-(const MenuItemInOrder& item, int num);
	friend MenuItemInOrder operator+(int num, const MenuItemInOrder& item);
	friend MenuItemInOrder operator+(const MenuItemInOrder& item, int num);
	const MenuItemInOrder& operator+=(int num);
	const MenuItemInOrder& operator-=(int num);
	MenuItemInOrder operator++(int);
	const MenuItemInOrder& operator++();



	MenuItem& getMenuItem() const;
	int getQuantity() const;
	char* getComment() const;

	bool setQuantity(int quantity);
	bool setComment(char& comment);

	void print() const;
};