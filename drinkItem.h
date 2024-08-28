#ifndef __DRINK_ITEM_H
#define __DRINK_ITEM_H
#include  "menuItem.h"
#include <string>
#include "list"
using namespace std;

class DrinkItem : virtual public MenuItem
{
public:
	enum eGlassType{LOWBOAL,WINE,BEER,HIGHBOAL,PAPERCUP};

	DrinkItem();
	DrinkItem(const string& name, int volume, eGlassType glass ,int price, list<Ingredient*>& ingredients);
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