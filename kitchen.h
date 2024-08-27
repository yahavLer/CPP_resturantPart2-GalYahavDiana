#pragma once

#include "warehouse.h"
#include "Department.h"
#include "FoodItem.h"

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
	bool updateIngredientQuantity(std::string& name, int quantity);
	bool addIngredientToWarehouse(std::string& ingredientName, int section);
	void print() override;
};