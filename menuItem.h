#ifndef __INGREDIENT_H
#define __CAT_H

#include <iostream>
using namespace std;
struct Ingredient;


class MenuItem
{
public:
	MenuItem(int numOfIngredients, Ingredient** list);
	~MenuItem();
	MenuItem();
	MenuItem(const MenuItem& other) = delete;
	MenuItem(MenuItem&& other);
	const MenuItem& operator=(const MenuItem& other);
	const MenuItem& operator=(MenuItem&& other);

	inline int getPrice() const;
	const Ingredient**& getIngredientList() const;
	bool setPrice(int newPrice);
	bool setIngredients(Ingredient** list, int size);




private:
	int price;
	Ingredient** ingredientList;



};