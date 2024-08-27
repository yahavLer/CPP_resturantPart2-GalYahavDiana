#pragma once

#include "table.h"
#include "menu.h"
#include "department.h"
#include "drinkItem.h"
class Order;

class Restaurant
{
private:
	Table tables[10];
	Department** departments;
	Order** dailyOrders;
	std::string name;
	std::string address;
	int dailyIncome;


public:
	Restaurant();
	Restaurant(const std::string& name,const std::string& address);
	Restaurant(const Restaurant& other) = delete;
	Restaurant(Restaurant&& other) noexcept;
	~Restaurant();


	Restaurant& operator=(const Restaurant& other) = delete;
	Restaurant& operator=(Restaurant&& other) noexcept;

	Table& getTables() const;
	Department** getDepartments() const;
	const std::string getName() const;
	const std::string getAddress() const;

	bool setName(const std::string& name);
	bool setAddress(const std::string& address);
	void presentMenu() const;
	bool updateIngredientQuantity(const std::string& name, int quantity, int kitchen);
	void presentTables() const;
	bool createNewOrderInTable(int tableNum);
	bool addItemToOrder(int menuIemNum, int quantity, int tableNum, std::string& comments);
	bool closeBill(int tableNum);
	bool addIngredientToWarehouse(const std::string& ingredientName, int section, int  forKitchen);
	bool addTables(int numOfTables);
	bool isEmptyOfTable();
	void presentDailyIncome();
	void showKitchenWarehouse();
	void showBarWarehouse();
	void showMenuWarehouse();
	void showTablesWarehouse();
	bool addDrinkItemToMenu(const std::string& name, int volume, DrinkItem::eGlassType glass, int price, Ingredient** ingredients, int numOfIngredients, bool special);
	bool addFoodItemToMenu(const std::string& itemName, const int numOfIngredients, Ingredient** list, int price, int department, bool special, bool kosher);
	int getTableIndex(int tableNum);
	void print() const;
};