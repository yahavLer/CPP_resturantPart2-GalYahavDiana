#pragma once

#ifndef __BUILDING_H
#define __BUILDING_H
class Building
{
private:
	char* address;
	char* nameOfBuilding;

public:
	Building(const char* name, const char* address);
	Building(const Building& other);
	bool setBuildingName(const char* name);
	char* getBuildingName() const;
	char* getAddress() const;
	void printBuilding() const;
	~Building();
};

#endif // __BUILDING_H

