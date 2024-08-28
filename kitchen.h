#pragma once

#include "warehouse.h"
#include "Department.h"
#include "FoodItem.h"
#include "Observer.h"
#include <list>
using namespace std;

class Kitchen : public Department 
{
private:
	//FoodItem **foodItemList;
	list<FoodItem*> foodItemList;

public:
	Kitchen();
	Kitchen(Kitchen &&other) noexcept;
	~Kitchen();
	Kitchen &operator=(const Kitchen &other);
	Kitchen &operator=(Kitchen &&other) noexcept;

	//FoodItem **getFoodItemList() const;
	list<FoodItem*>& getFoodItemList();
	bool updateIngredientQuantity(string& name, int quantity);
	bool addIngredientToWarehouse(string& ingredientName, int section);
	void update(const MenuItem& newMeal) override;
	void print() override;
};