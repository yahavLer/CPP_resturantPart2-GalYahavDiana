#pragma once

class FoodItem
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
};