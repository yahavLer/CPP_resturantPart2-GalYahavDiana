#ifndef __MENUITEM_H
#define __MENUITEM_H

#include <iostream>
#include <list> 
#include <string>
using namespace std;

#include "Ingredient.h"

class MenuItem
{
protected:
	int price;
	/*Ingredient** ingredientList;
	int numOfIngredients;*/
	list<Ingredient*> ingredientList;
	string name;

public:
	//MenuItem(const string& name, const int numOfIngredients, Ingredient** list, int price);
	MenuItem(const string& name, list<Ingredient*> list, int price);
	virtual ~MenuItem();
	MenuItem();
	MenuItem(const MenuItem& other); 
	MenuItem(MenuItem&& other) noexcept; 
	MenuItem& operator=(const MenuItem& other); 
	MenuItem& operator=(MenuItem&& other) noexcept;
	inline const string getName() const { return name; }
	bool setName(const string& newName);
	inline int getPrice() const { return price; }
	//Ingredient** const getIngredientList() const { return ingredientList; }
	const list<Ingredient*>& getIngredientList() const;  // Return a reference to the list
	bool setPrice(int newPrice);
	//bool setIngredients(Ingredient** list, int size);
	bool setIngredients(list<Ingredient*> list);
	virtual void print() = 0 ;
	virtual MenuItem* clone() const = 0;

private:
	void clearIngredients(); 
};
#endif// __MENUITEM_H