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
	Warehouse& getWarwhouse();
	bool updateIngredientQuantity(const std::string& name, int quantity);
	bool addIngredientToWarehouse(const std::string& ingredientName, int section);
    virtual void print() = 0; 
	void printWarehouse();

};