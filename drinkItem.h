#ifndef __DRINK_ITEM_H
#define __DRINK_ITEM_H
#include "menuItem.h"

class DrinkItem : virtual public MenuItem
{
public:
	enum eGlassType { LOWBOAL, WINE, BEER, HIGHBOAL, PAPERCUP };
	const char* glassTypes[5] = { "Lowball", "Wine", "Beer","Highball","Paper cup" };

	DrinkItem();
	DrinkItem(char* name, int volume, eGlassType glass);


	inline const char* getName() const { return name; }
	inline int getVolume() const { return volume; };
	inline eGlassType getGlass() const { return glass; };
	bool setName();
	bool setVolume();
	bool setGlass();


private:
	char name[20];
	int volume;
	eGlassType glass;

};
#endif// __DRINK_ITEM_H