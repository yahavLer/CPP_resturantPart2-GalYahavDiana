#pragma once

class Department
{

public:
	int getNumOfWorkers() const inline;
	bool updateIngredientQuantity(char* name, int quantity);
	bool addIngredientToWarehouse(char* ingredientName, int section);

};