#pragma once
#include "DrinkItem.h"
#include "AlcoholicDrink.h"

class Cocktail : virtual public DrinkItem, virtual public AlcoholicDrink
{
public:
	enum eAlcoholLevel { regular, doubleDose, weak, virgin };
	static const char* alcoholLevelNames[4];
private:
	eAlcoholLevel alcoholLevel;
	int doubleDosePrice;
public:
	
	Cocktail(int doubleDosePrice);

	eAlcoholLevel getAlcoholLevel() const;
	int getDoubleDosePrice() const;

	bool setAlcoholLevel(eAlcoholLevel newAlcoholLevel);
	bool setDoubleDosePrice(int doubleDosePrice);

	void print() const;
};
