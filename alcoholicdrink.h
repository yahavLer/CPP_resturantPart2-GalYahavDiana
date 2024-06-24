#pragma once


class AlcoholicDrink
{
private:
	int alcoholPercentage;

public:
	AlcoholicDrink();
	AlcoholicDrink(int alcoholPercentage);
	int getAlcoholPercentage() const;
	bool setAlcoholPercentage();


};