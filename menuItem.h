#pragma once

struct Ingredient;


class MenuItem
{
public:
	MenuItem(int numOfIngredients, Ingredient** list);
	~MenuItem();
	MenuItem();
	MenuItem(const MenuItem& other) = delete;
	MenuItem(MenuItem&& other);
	const MenuItem& operator=(const MenuItem& other);
	const MenuItem& operator=(MenuItem&& other);

	inline int getPrice() const;
	const Ingredient**& getIngredientList() const;
	bool setPrice();
	bool setIngredients();




private:
	int price;
	Ingredient** ingredientList;



};