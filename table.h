#pragma once

struct Order;

class Table
{
private:
	Order* order;
	int number;

public:
	Table();
	Table(const Table& other) = delete;
	Table(Table&& other);
	~Table();
	Table(int number);
	const Table& operator=(const Table& other);
	const Table& operator=(Table&& other);

	Order* getOrder() const;
	int getNumber() const;

	bool setNumber(int newNumber);
	bool createNewOrder();
	bool AddItemToOrder(int menuIemNum, int quantity);
	int closeBill();
	

	void printTable() const;
};