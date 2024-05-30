#pragma once

#ifndef __BUILDING_H
#define __BUILDING_H
//#define ID_SIZE 9
class Building
{
private:
	char* address;
	char* name;

public:
	Building(const char* firstName, const char* lastName, const int id);
	Building(const Building& other);
	void setFirstName(const char* n);
	void setLastName(const char* n);
	char* getFirstName() const;
	char* getLastName() const;
	void print() const;
	~Building();
};

#endif // __BUILDING_H

