#pragma once

#include "menuItemInOrder.h"
#include <list>
using namespace std;

class Order
{
private:
	list<MenuItemInOrder*> orderedItems;
	//MenuItemInOrder **orderedItems;
	//int numItems;

public:
	Order();
	Order(const Order& other);
	Order(Order &&other) noexcept;
	~Order();

	// const Order& operator=(const Order& other);
	Order &operator=(Order &&other) noexcept;
	//MenuItemInOrder **getOrderedItems() const;
	const list<MenuItemInOrder*>& getOrderedItems() const;
	bool addItemToOrder(const MenuItem &menuItem, int quantity, const string& comments);
	int closeBill() const;
	void print() const;

private:
	void clear();
};