#ifndef __MENUITEM_H
#define __MENUITEM_H

#include <iostream>
using namespace std;

#include "Ingredient.h";

class MenuItem
{
protected:
	int price;
	Ingredient** ingredientList;
	int numOfIngredients;

public:
	MenuItem(const int numOfIngredients, Ingredient** list);
	~MenuItem();
	MenuItem();
	MenuItem(const MenuItem& other); //
	MenuItem(MenuItem&& other) noexcept; 
	MenuItem& operator=(const MenuItem& other); //
	MenuItem& operator=(MenuItem&& other) noexcept;

	inline int getPrice() const { return price; }
	Ingredient** const getIngredientList() const { return ingredientList; }
	bool setPrice(int newPrice);
	bool setIngredients(Ingredient** list, int size);
	virtual void print()=0 ;

private:
	void clearIngredients(); 


};
#endif// __MENUITEM_H