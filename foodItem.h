#pragma once
#include "menuItem.h"

class FoodItem : virtual public MenuItem
{
private:
	int calories;
	bool kosher;

public:
	FoodItem();
	FoodItem(int calories, bool kosher);

	inline int getCalories() const { return calories; }
	inline bool getKosher() const { return kosher; }

	bool setCalories(int newCalories);
	bool setKosher(bool isKosher);
	void print() override;

};