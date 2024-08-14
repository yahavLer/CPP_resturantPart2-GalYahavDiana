#pragma once

class Department
{
protected:
	Warehouse *wareHouse;
	int numOfWorkers;

public:
	Department();
    Department(int workers = 0);
    virtual ~Department() = default;

	inline int getNumOfWorkers() const;
	bool updateIngredientQuantity(char* name, int quantity);
	bool addIngredientToWarehouse(char* ingredientName, int section);

    virtual void manageDepartment() = 0; 

};