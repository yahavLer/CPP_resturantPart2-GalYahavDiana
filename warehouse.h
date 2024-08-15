#pragma once

#include "Ingredient.h"

class Warehouse
{
private:
	Ingredient** ingredientList; 
	int* ingredientQuantityList;
	int numIngredients;

public:
	Warehouse();
	Warehouse(const Warehouse& other) = delete;
	Warehouse(Warehouse&& other) noexcept;
	~Warehouse();
    Warehouse& operator=(const Warehouse& other) = delete;
    Warehouse& operator=(Warehouse&& other) noexcept;
	
	Ingredient** getIngredientList() const;
	Ingredient* getIngredientByName(const char* ingredientName) const; 
	int* getIngredientQuantityList() const;
	bool updateIngredientQuantity(const Ingredient* ingredient, int quantity);  
	bool addIngredientToWarehouse(const char* ingredientName, int section);
	void print() const;

private:
    void clear();  
    bool compareStrings(const char* str1, const char* str2) const;   
};
