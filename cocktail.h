#pragma once
#include "DrinkItem.h"
#include "AlcoholicDrink.h"

class Cocktail : virtual public DrinkItem, virtual public AlcoholicDrink
{
private:
	enum eAlcoholLevel;
	int doubleDosePrice;
public:
	enum eAlcoholLevel { regular, doubleDose, weak, virgin };
	const char* alcoholLevel[4] = { "regular","doubleDose","weak","virgin" };

	Cocktail(int doubleDosePrice);

	eAlcoholLevel getAlcoholLevel() const;
	int getDoubleDosePrice() const;

	bool setAlcoholLevel(eAlcoholLevel newAlcoholLevel);
	bool setDoubleDosePrice(int doubleDosePrice);

	void print() const;
};
