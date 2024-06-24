#pragma once



class DrinkItem
{
public:
	enum eGlassType { LOWBOAL, WINE, BEER, HIGHBOAL, PAPERCUP };
	const char* glassTypes[5] = { "Lowball", "Wine", "Beer","Highball","Paper cup" };

	DrinkItem();
	DrinkItem(char* name, int volume, eGlassType glass);


	inline char* getName() const;
	inline int getVolume() const;
	inline eGlassType getGlass() const;
	bool setName();
	bool setVolume();
	bool setGlass();


private:
	char name[20];
	int volume;
	eGlassType glass;

};