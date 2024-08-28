#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H

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
	Department& operator=(const Department& other);

	inline int getNumOfWorkers() const { return numOfWorkers; }
	Warehouse& getWarehouse();
	bool updateIngredientQuantity(const char* name, int quantity);
	bool addIngredientToWarehouse(const char* ingredientName, int section);
    virtual void print() = 0; 
	void printWarehouse();

};
#endif  // __DEPARTMENT_H