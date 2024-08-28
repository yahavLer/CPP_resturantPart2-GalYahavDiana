#pragma once
#include "menuItem.h"
#include "list"
using namespace std;

class FoodItem : virtual public MenuItem
{
private:
	int calories;
	bool kosher;

public:
	FoodItem();
	FoodItem(const string& name, bool kosher, int price, const list<Ingredient*>& list,int calories);

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