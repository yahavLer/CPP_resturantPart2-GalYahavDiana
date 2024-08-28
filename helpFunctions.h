#pragma once

#ifndef HELPFUNCTIONS_H
#define HELPFUNCTIONS_H
#include <list>
#include "restaurant.h"
using namespace std;

class HelpFunctions
{
public:
	HelpFunctions();
	~HelpFunctions();

	int userIntValidation();
	void initRestaurant(Restaurant* restaurant);
	Ingredient* getValidIngredient(Warehouse& warehouse);
	void gatherDrinkInfo(string& mealName, int& price, int& volume, int& glassType, bool& special);
	void gatherDrinkIngredients(list<Ingredient*> ingredientList, Restaurant* restaurant);
	void gatherFoodInfo(string& mealName, int& price, bool& special, bool& kosher);
	void gatherFoodIngredients(list<Ingredient*> ingredientList, Restaurant* restaurant);
	void displayMenu();

};


#endif; // HELPFUNCTIONS_H