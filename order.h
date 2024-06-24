#pragma once

#include "menuItemInOrder.h"

class Order
{
private:
	MenuItemInOrder** orderedItems;

public:
	Order();
	Order(const Order& other) = delete;
	Order(Order&& other);
	~Order();

	const Order& operator=(const Order& other);
	const Order& operator=(Order&& other);

	MenuItemInOrder**& getOrderedItems() const;

	bool addItemToOrder(const MenuItem& menuItem);
	int closeBill() const;

	void print() const;
};