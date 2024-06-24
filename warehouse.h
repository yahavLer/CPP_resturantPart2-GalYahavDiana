#pragma once

struct Ingrediant;

class Warehouse
{
private:
	Ingrediant** ingrediantList;
	int* ingrediantQuantityList;
public:
	Warehouse();
	Warehouse(const Warehouse& other) = delete;
	Warehouse(Warehouse&& other);
	~Warehouse();
	const Warehouse& operator=(const Warehouse& other);
	const Warehouse& operator=(Warehouse&& other);
	
	Ingrediant** getIngrediantList() const;
	int* getIngrediantQuantityList()const;
	bool updateIngredientQuantity(Ingrediant ingrediant, int quantity);
	bool addIngredientToWarehouse(char* ingredientName, int section);
};