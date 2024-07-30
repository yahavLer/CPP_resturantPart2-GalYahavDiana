#ifndef __MENUITEM_H
#define __MENUITEM_H

#include <iostream>
using namespace std;

struct Ingredient;

class MenuItem
{
private:
	int price;
	Ingredient** ingredientList;
public:
	MenuItem(const int numOfIngredients, Ingredient** list);
	~MenuItem();
	MenuItem();
	MenuItem(const MenuItem& other) = delete;
	MenuItem(MenuItem&& other);
	const MenuItem& operator=(const MenuItem& other);
	const MenuItem& operator=(MenuItem&& other);

	inline int getPrice() const { return price; }
	const Ingredient** getIngredientList() const { return ingredientList; }
	bool setPrice(int newPrice);
	bool setIngredients(Ingredient** list, int size);



};
#endif// __MENUITEM_H