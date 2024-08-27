#ifndef __MENUITEM_H
#define __MENUITEM_H

#include <iostream>
using namespace std;

#include "Ingredient.h"

class MenuItem
{
protected:
	int price;
	Ingredient** ingredientList;
	int numOfIngredients;
	std::string name;

public:
	MenuItem(const std::string& name, const int numOfIngredients, Ingredient** list, int price);
	virtual ~MenuItem();
	MenuItem();
	MenuItem(const MenuItem& other); //
	MenuItem(MenuItem&& other) noexcept; 
	MenuItem& operator=(const MenuItem& other); //
	MenuItem& operator=(MenuItem&& other) noexcept;
	inline const std::string getName() const { return name; }
	bool setName(const std::string& newName);
	inline int getPrice() const { return price; }
	Ingredient** const getIngredientList() const { return ingredientList; }
	bool setPrice(int newPrice);
	bool setIngredients(Ingredient** list, int size);
	virtual void print() = 0 ;
	virtual MenuItem* clone() const = 0;

private:

	void clearIngredients(); 


};
#endif// __MENUITEM_H