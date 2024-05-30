#pragma once

#ifndef __WORKER_H
#define __WORKER_H
#include "Person.h"
//#define ID_SIZE 9
class Worker: public Person
{
private:

	int Seniority;
	int	Salary;
	double numOfHours;
	bool isOnShift;

public:
	Worker(int Seniority,int Salary, double numOfHours, bool isOnShift);
	Worker(const Worker& other);
	void setSeniority(const char* n);
	void setSalary(const char* n);
	void setnumOfHours(const char* n);
	bool isOnShift(bool isOnShift);
	void getSeniority(const char* n);
	void getSalary(const char* n);
	void getnumOfHours(const char* n);
	void print() const;
	~Worker();
};

#endif // __WORKER_H