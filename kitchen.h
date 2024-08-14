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
	// Kitchen(const Kitchen &other) = delete;
	Kitchen(Kitchen &&other) noexcept;
	~Kitchen();
	Kitchen &operator=(const Kitchen &other);
	Kitchen &operator=(Kitchen &&other) noexcept;

	FoodItem **getFoodItemList() const;
	bool updateIngredientQuantity(char *name, int quantity);
	bool addIngredientToWarehouse(char *ingredientName, int section);
};