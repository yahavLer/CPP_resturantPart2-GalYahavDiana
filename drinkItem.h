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
	DrinkItem(const char* name, int volume, eGlassType glass);

	inline const char* getName() const { return name; }
	inline int getVolume() const { return volume; };
	inline eGlassType getGlass() const { return glass; };

	bool setName(const char* newName);
	bool setVolume(int newVolume);
	bool setGlass(eGlassType newGlass);
	void print() override;

private:
	char name[20];
	int volume;
	eGlassType glass;
};
#endif // __DRINK_ITEM_H