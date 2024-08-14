#pragma once

#include "warehouse.h"
#include "Department.h"
struct DrinkItem;

class Bar : public Department
{
private:
	DrinkItem **drinkItemList;

public:
	Bar();
	Bar(const Bar &other) = delete;
	Bar(Bar &&other)noexcept;
	~Bar();
	const Bar &operator=(const Bar &other);
	const Bar &operator=(Bar &&other);

	inline int getNumOfWorkers() const;
	bool updateIngredientQuantity(const char *name, int quantity);
	bool addIngredientToWarehouse(const char *ingredientName, int section);
	inline DrinkItem **getDrinkItemList() const;
	inline Warehouse &getWareHouse() const;
};