#pragma once

#include "menuItemInOrder.h"

class Order
{
private:
	MenuItemInOrder **orderedItems;
	int numItems;

public:
	Order();
	// Order(const Order& other) = delete;
	Order(Order &&other) noexcept;
	~Order();

	// const Order& operator=(const Order& other);
	Order &operator=(Order &&other) noexcept;
	MenuItemInOrder **getOrderedItems() const;
	bool addItemToOrder(const MenuItem &menuItem);
	int closeBill() const;
	void print() const;

private:
	void clear();
};