#pragma once

class FoodItem
{
public:
	FoodItem();
	FoodItem(int calories, bool kosher);
	inline int getCalories() const;
	inline bool getKosher() const;
	bool setCalories();
	bool setKosher();



private:
	int calories;
	bool kosher;

};