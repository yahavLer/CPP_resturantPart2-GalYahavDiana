#pragma once
#include <iostream>
using namespace std;


class Cocktail
{
public:
	enum eAlcoholLevel { regular, doubleDose, weak, virgin };
	const char* alcoholLevel[4] = { "regular","doubleDose","weak","virgin" };

	Cocktail(int doubleDosePrice);

	eAlcoholLevel getAlcoholLevel() const;
	int getDoubleDosePrice() const;

	bool setAlcoholLevel(eAlcoholLevel newAlcoholLevel);
	bool setDoubleDosePrice(int doubleDosePrice);

	void print() const;

private:
	enum eAlcoholLevel;
	int doubleDosePrice;

};