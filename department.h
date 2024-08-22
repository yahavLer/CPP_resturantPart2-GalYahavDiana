#pragma once
#include "warehouse.h"

class Department
{
protected:
	Warehouse wareHouse;
	int numOfWorkers;

public:
	Department();
	Department(int workers);
    virtual ~Department() = default;

	Department(Department&& other) noexcept;

	inline int getNumOfWorkers() const { return numOfWorkers; }
	bool updateIngredientQuantity(const char* name, int quantity);
	bool addIngredientToWarehouse(const char* ingredientName, int section);
    virtual void print() = 0; 
	Department& operator=(const Department& other);

};