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
	void setFirstName(const char* n);
	void setLastName(const char* n);
	char* getFirstName() const;
	char* getLastName() const;
	void print() const;
	~Worker();
};

#endif // __WORKER_H