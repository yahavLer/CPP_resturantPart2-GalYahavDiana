#ifndef __ALCOHOLICDRINK_H
#define __ALCOHOLICDRINK_H


class AlcoholicDrink
{
private:
	int alcoholPercentage;

public:
	AlcoholicDrink();
	AlcoholicDrink(int alcoholPercentage);
	int getAlcoholPercentage() const;
	bool setAlcoholPercentage(int percentage);
};
#endif// __ALCOHOLICDRINK_H