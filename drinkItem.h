#ifndef __DRINK_ITEM_H
#define __DRINK_ITEM_H
#include  "menuItem.h"

class DrinkItem : virtual public MenuItem
{
public:
	enum eGlassType
	{
		LOWBOAL,
		WINE,
		BEER,
		HIGHBOAL,
		PAPERCUP
	};
	static const char *glassTypes[5];

	DrinkItem();
	DrinkItem(const char* name, int volume, eGlassType glass ,int price, Ingredient** ingredients, int numOfIngredients);
	DrinkItem(const DrinkItem& other);
	DrinkItem& operator=(const DrinkItem& other);

	inline int getVolume() const { return volume; };
	inline eGlassType getGlass() const { return glass; };
	bool setVolume(int newVolume);
	bool setGlass(eGlassType newGlass);
	void print() override;
	virtual DrinkItem* clone() const override; 

private:
	int volume;
	eGlassType glass;
};
#endif // __DRINK_ITEM_H