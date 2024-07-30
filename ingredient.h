#pragma once



class Ingredient
{
public:
	enum eSection { HERBS, DAIRY, MEAT, FISH, VEGETABLES };
	const char* sections[5] = { "Herbs","Dairy","Meat","Fish","Vegetables" };
	Ingredient();
	Ingredient(const char* name, eSection section);


	inline char* getName()  const;
	inline eSection getSection() const;
	bool setName(const char* name);
	bool setSection(eSection section);

private:
	char name[20];
	eSection section;
};