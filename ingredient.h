#ifndef __INGREDIENT_H
#define __INGREDIENT_H

#include <iostream>
using namespace std;
class Ingredient
{
public:
	enum eSection { HERBS, DAIRY, MEAT, FISH, VEGETABLES };
	const char* sections[5];
	
	Ingredient();
	Ingredient(const char* name, eSection section);


	inline char* getName() const {
        return const_cast<char*>(name);
    }

    inline eSection getSection() const {
        return section;
    }

	bool setName(const char* name);
	bool setSection(eSection section);
	void print();

private:
	char name[20];
	eSection section;
};
#endif// __INGREDIENT_H