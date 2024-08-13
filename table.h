#pragma once

struct Order;

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

	const Table &operator=(const Table &other);
	//Table &operator=(Table &&other) noexcept;

	Order *getOrder() const;
	int getNumber() const { return number; }

	bool setNumber(int newNumber);
	bool createNewOrder();
	bool AddItemToOrder(int menuIemNum, int quantity);
	int closeBill();

	void printTable() const;

private:
	void clear();
};