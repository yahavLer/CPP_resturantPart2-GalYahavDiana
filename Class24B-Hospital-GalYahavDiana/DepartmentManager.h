#pragma once

#ifndef __DEPARTMENTMAMAGER_H
#define __DEPARTMENTMAMAGER_H
#include "Person.h"
//#define ID_SIZE 9
class DepartmentManager : public Researcher, public Person 
{
private:

	int Seniority;
	int	Salary;
	double numOfHours;
	bool isOnShift;

public:
	DepartmentManager(int Seniority, int Salary, double numOfHours, bool isOnShift);
	DepartmentManager(const Worker& other);
	void setSeniority(const int Seniority);
	void setSalary(const int Salary);
	void setnumOfHours(const double numOfHours);
	bool isOnShift(bool isOnShift);
	void getSeniority()const;
	void getSalary()const;
	void getnumOfHours()const;
	void print() const;
	~DepartmentManager();
};

#endif // __DEPARTMENTMAMAGER_H