#pragma once

#include "table.h"
#include "menu.h"

struct Department;
struct Order;

class Restaurant
{
private:
	Table tables[10];
	Department** departments;
	Order** dailyOrders;
	Menu menu;
	char name[20];
	char address[20];


public:
	Restaurant();
	Restaurant(char* name, char* address);
	Restaurant(const Restaurant& other) = delete;
	Restaurant(Restaurant&& other);
	~Restaurant();

	const Restaurant& operator=(const Restaurant& other);
	const Restaurant& operator=(Restaurant&& other);

	Table& getTables() const;
	Department**& getDepartments() const;
	Menu getMenu() const;
	char& getName() const;
	char& getAdress() const;

	bool setName(char* name);
	bool setAdress(char* address);

	void presentMenu();
	bool updateIngredientQuantity(char* name, int quantity, int kitchen);
	void presentTables() const;
	bool createNewOrderInTable(int tableNum);
	bool AddItemToOrder(int menuIemNum, int quantity);
	bool closeBill(int tableNum);
	bool addIngredientToWarehouse(char* ingredientName, int section, int  forKitchen);
	bool addTables(int numOfTables);
	void presentDailyIncome();
	void showKitchenWarehouse();
	void showBarWarehouse();
	void showMenuWarehouse();
	void showTablesWarehouse();

	void print() const;
};