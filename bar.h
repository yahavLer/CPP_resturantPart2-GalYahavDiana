#pragma once

#include "warehouse.h"
#include "Department.h"
#include "DrinkItem.h"

class Bar : public Department
{
private:
	DrinkItem **drinkItemList;

public:
	Bar();
	Bar(const Bar &other) = delete;
	Bar(Bar &&other)noexcept;
	~Bar();
	//const Bar &operator=(const Bar &other);
	const Bar &operator=(Bar &&other);

	inline int getNumOfWorkers() const;
	bool updateIngredientQuantity(const std::string& name, int quantity);
	bool addIngredientToWarehouse(const std::string& ingredientName, int section);
	inline DrinkItem **getDrinkItemList() const;
	inline const Warehouse& getWareHouse() const;
	void print() override;
};