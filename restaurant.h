#pragma once

#include "table.h"
#include "menu.h"
#include "department.h"
class Order;

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
	Restaurant(const char* name,const char* address);                                                                                                    
	Restaurant(const Restaurant& other) = delete;
	Restaurant(Restaurant&& other);
	~Restaurant();


	Restaurant& operator=(const Restaurant& other) = delete;
	Restaurant& operator=(Restaurant&& other) noexcept;

	Table& getTables() const;
	Department** getDepartments() const;
	const Menu& getMenu() const;
	const char* getName() const;
	const char* getAddress() const;

	bool setName(const char* name);
	bool setAddress(const char* address);
	void presentMenu() const;
	bool updateIngredientQuantity(const char* name, int quantity, int kitchen);
	void presentTables() const;
	bool createNewOrderInTable(int tableNum);
	bool AddItemToOrder(int menuIemNum, int quantity);
	bool closeBill(int tableNum);
	bool addIngredientToWarehouse(const char* ingredientName, int section, int  forKitchen);
	bool addTables(int numOfTables);
	void presentDailyIncome();
	void showKitchenWarehouse();
	void showBarWarehouse();
	void showMenuWarehouse();
	void showTablesWarehouse();

	void print() const;
};