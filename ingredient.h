#ifndef __INGREDIENT_H
#define __INGREDIENT_H

#include <iostream>
using namespace std;
class Ingredient
{
public:
	enum eSection { HERBS, DAIRY, MEAT, FISH, VEGETABLES };
	
	Ingredient();
	Ingredient(const std::string& name, eSection section, int quantity);


	inline std::string getName() const { return name; }
	inline int getQuantity() const { return quantityIng;  }
    inline eSection getSection() const { return section; }

	bool setName(const std::string& newName);
	bool setSection(eSection section);
	bool setQuantity(int quantity);
	void print();

private:
	std::string name;
	eSection section;
	int quantityIng;
};
#endif// __INGREDIENT_H