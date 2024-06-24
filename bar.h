#pragma once

#include "warehouse.h"

struct DrinkItem;

class Bar
{
private:
	Warehouse wareHouse;
	DrinkItem** drinkItemList;
	int numOfWorkers;
public:
	Bar();
	Bar(const Bar& other) = delete;
	Bar(Bar&& other);
	~Bar();
	const Bar& operator=(const Bar& other);
	const Bar& operator=(Bar&& other);

	inline int getNumOfWorkers() const ;
	bool updateIngredientQuantity(char* name, int quantity);
	bool addIngredientToWarehouse(char* ingredientName, int section);
	inline DrinkItem** getDrinkItemList() const;
	inline Warehouse& getWareHouse() const;
};