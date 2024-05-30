#pragma once
#pragma once

#ifndef __WORKER_H
#define __WORKER_H
#include "Person.h"
//#define ID_SIZE 9
class DepartmentManager: public Researcher, public Person:
{
private:

	int Seniority;
	int	Salary;
	double numOfHours;
	bool isOnShift;

public:
	Worker(int Seniority, int Salary, double numOfHours, bool isOnShift);
	Worker(const Worker& other);
	void setSeniority(const int Seniority);
	void setSalary(const int Salary);
	void setnumOfHours(const double numOfHours);
	bool isOnShift(bool isOnShift);
	void getSeniority()const;
	void getSalary()const;
	void getnumOfHours()const;
	void print() const;
	~Worker();
};

#endif // __WORKER_H