#pragma once

#ifndef __WORKER_H
#define __WORKER_H
#include "Person.h"
class Worker: public Person
{
private:

	int seniority;
	int	salary;
	double numOfHours;
	bool isOnShift;

public:
	Worker(int seniority,int salary, double numOfHours);
	Worker(const Worker& other);
	bool setSeniority(const int seniority);
	bool setSalary(const int salary);
	bool setnumOfHours(const double numOfHours);
	bool setOnShift(bool isOnShift);
	char* getSeniority()const ;
	int getSalary()const;
	double getnumOfHours()const;
	bool isOnShift()const;
	void printWorker() const;
	~Worker();
};

#endif // __WORKER_H