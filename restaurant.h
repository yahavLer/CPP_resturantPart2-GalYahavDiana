#ifndef __RESTAURANT_H
#define __RESTAURANT_H

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
	Menu menu;
	char name[20];
	char address[20];
	int dailyIncome;


public:
	Restaurant();
	Restaurant(const char* name,const char* address);                                                                                                    
	Restaurant(const Restaurant& other) = delete;
	Restaurant(Restaurant&& other) noexcept;
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
	bool addItemToOrder(int menuIemNum, int quantity, int tableNum, char* comments);
	bool closeBill(int tableNum);
	bool addIngredientToWarehouse(const char* ingredientName, int section, int  forKitchen);
	bool addTables(int numOfTables);
	bool isEmptyOfTable();
	void presentDailyIncome();
	void showKitchenWarehouse();
	void showBarWarehouse();
	void showMenuWarehouse();
	void showTablesWarehouse();
	bool addDrinkItemToMenu(const char* name, int volume, DrinkItem::eGlassType glass, int price, Ingredient** ingredients, int numOfIngredients, bool special);
	bool addFoodItemToMenu(const char* itemName, const int numOfIngredients, Ingredient** list, int price, int department, bool special, bool kosher);
	int getTableIndex(int tableNum);
	void print() const;
};
#endif  // __RESTAURANT_H