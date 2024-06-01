#pragma once

#ifndef __DEPARTMENTMAMAGER_H
#define __DEPARTMENTMAMAGER_H
#include "Doctor.h"
#include "Researcher.h"

//#define ID_SIZE 9
class DepartmentManager : public Researcher, public Doctor 
{
private:
	int bonus;

public:
	DepartmentManager(const int bonus);
	DepartmentManager(const DepartmentManager& other);
	bool setBonus(const int bonus);
	int getBonus() const;
	void printDepartmentManager() const;
	~DepartmentManager();

};

#endif // __DEPARTMENTMAMAGER_H