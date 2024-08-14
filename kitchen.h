#pragma once

#include "warehouse.h"
#include "Department.h"
struct FoodItem;

class Kitchen : public Department
{
private:
	FoodItem **foodItemList;

public:
	Kitchen();
	Kitchen(const Kitchen &other) = delete;
	Kitchen(Kitchen &&other);
	~Kitchen();
	const Kitchen &operator=(const Kitchen &other);
	const Kitchen &operator=(Kitchen &&other);

	inline Warehouse getWareHouse() const;
	inline FoodItem **getFoodItemList() const;
	inline int getNumOfWorkers() const;
	bool updateIngredientQuantity(char *name, int quantity);
	bool addIngredientToWarehouse(char *ingredientName, int section);
};