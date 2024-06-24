#pragma once



class Ingredient
{
public:
	enum eSection { HERBS, DAIRY, MEAT, FISH, VEGETABLES };
	Ingredient();
	Ingredient(const char* ingredientName, eSection ingredientSection);


	inline char* getName()  const;
	inline eSection getSection() const;
	bool setName(char* name);
	bool setSection(eSection section);

private:
	char name[20];
	eSection section;
};