#pragma once
#ifndef __WAREHOUSE_H
#define __WAREHOUSE_H
#include "Ingredient.h"
#include "linkedList.h"
#include <string>
#include <list> 
using namespace std;

class Warehouse
{
private:
	// Ingredient** ingredientList; 
	LinkedList<Ingredient> ingredientList;    //  Replacing the array with a linked list
	list<int> ingredientQuantityList;
	//int numIngredients;

public:
	Warehouse();
	Warehouse(const Warehouse& other) = delete;
	Warehouse(Warehouse&& other) noexcept;
	~Warehouse();
    Warehouse& operator=(const Warehouse& other) = delete;
    Warehouse& operator=(Warehouse&& other) noexcept;
	
	LinkedList<Ingredient>& getIngredientList();
	Ingredient* getIngredientByName(const string& ingredientName) const;
	const list<int>& getIngredientQuantityList() const;
	//int* getIngredientQuantityList() const;
	bool updateIngredientQuantity(const Ingredient* ingredient, int quantity);  
	bool addIngredientToWarehouse(const string& ingredientName, int section);
	void print() const;

	// Iterator pattern design 
	typename LinkedList<Ingredient>::Iterator begin() { return ingredientList.begin(); }
	typename LinkedList<Ingredient>::Iterator end() { return ingredientList.end(); }
	typename LinkedList<Ingredient>::ConstIterator begin() const { return ingredientList.begin(); }
	typename LinkedList<Ingredient>::ConstIterator end() const { return ingredientList.end(); }

private:
    void clear();  
    //bool compareStrings(const char* str1, const char* str2) const;   ->use strsmp insted
};
#endif// __WAREHOUSE_H