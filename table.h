#pragma once
#ifndef __TABLE_H
#define __TABLE_H
#include "order.h"

class Table
{
private:
	Order *order;
	int number;

public:
	Table();
	Table(int number);
	Table(Table &&other) noexcept;
	~Table();

	Order *getOrder() const;
	inline int getNumber() const { return number; }

	bool setNumber(int newNumber);
	bool createNewOrder();
	bool addItemToOrder(const MenuItem& menuItem, int quantity, std::string& comments);
	int closeBill();

	void printTable() const;

private:
	void clear();
};
#endif// __TABLE_H