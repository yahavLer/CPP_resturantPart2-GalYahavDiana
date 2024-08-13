#pragma once

class Department
{

public:
	inline int getNumOfWorkers() const;
	bool updateIngredientQuantity(char* name, int quantity);
	bool addIngredientToWarehouse(char* ingredientName, int section);

};