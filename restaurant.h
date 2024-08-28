#pragma once

#include "table.h"
#include "menu.h"
#include "department.h"
#include "drinkItem.h"
#include <list>
#include <string>
using namespace std;

class Order;

class Restaurant
{
private:
	static const int MAX_TABLES = 10;
	Table tables[MAX_TABLES];
	//Department** departments;
	//Order** dailyOrders;
	list<Department*> departments;
	list<Order*> dailyOrders;
	string name;
	string address;
	int dailyIncome;

public:
	Restaurant();
	Restaurant(const string& name,const string& address);
	Restaurant(const Restaurant& other) = delete;
	Restaurant(Restaurant&& other) noexcept;
	~Restaurant();

	Restaurant& operator=(const Restaurant& other) = delete;
	Restaurant& operator=(Restaurant&& other) noexcept;

	Table& getTables() const;
	const list<Department*>& getDepartments() const;
	const string& getName() const;
	const string& getAddress() const;

	bool setName(const string& name);
	bool setAddress(const string& address);
	void presentMenu() const;
	bool updateIngredientQuantity(const string& name, int quantity, int kitchen);
	void presentTables() const;
	bool createNewOrderInTable(int tableNum);
	bool addItemToOrder(int menuIemNum, int quantity, int tableNum, const string& comments);
	bool closeBill(int tableNum);
	bool addIngredientToWarehouse(const string& ingredientName, int section, int forKitchen);
	bool addTables(int numOfTables);
	bool isEmptyOfTable() const;
	void presentDailyIncome();
	void showKitchenWarehouse();
	void showBarWarehouse();
	void showMenuWarehouse();
	void showTablesWarehouse();
	bool addDrinkItemToMenu(const string& name, int volume, DrinkItem::eGlassType glass, int price, list<Ingredient*> ingredients, bool special);
	bool addFoodItemToMenu(const string& itemName, const list<Ingredient*>& list, int price, int department, bool special, bool kosher);
	int getTableIndex(int tableNum);
	void print() const;
};