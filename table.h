#pragma once

#include "order.h";

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
	// Table(const Table &other) = delete;

	// Table &operator=(const Table &other);
	// Table &operator=(Table &&other) noexcept;

	Order *getOrder() const;
	inline int getNumber() const { return number; }

	bool setNumber(int newNumber);
	bool createNewOrder();
	bool AddItemToOrder(const MenuItem& menuItem, int quantity, char *comments);
	int closeBill();

	void printTable() const;

private:
	void clear();
};