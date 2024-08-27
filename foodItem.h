#pragma once
#include "menuItem.h"

class FoodItem : virtual public MenuItem
{
private:
	int calories;
	bool kosher;

public:
	FoodItem();
	FoodItem(const std::string& name, bool kosher, int price, Ingredient** ingredients, int numOfIngredients,int calories);

	inline int getCalories() const { return calories; }
	inline bool getKosher() const { return kosher; }

	bool setCalories(int newCalories);
	bool setKosher(bool isKosher);
	void print() override;

	FoodItem* clone() const override
	{
		return new FoodItem(*this);
	}

};