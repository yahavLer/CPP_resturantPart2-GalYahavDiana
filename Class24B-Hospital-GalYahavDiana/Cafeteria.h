#pragma once

#ifndef __CAFETERIA_H
#define __CAFETERIA_H
#include "Building.h"
#include "CafeteriaWorker.h"

class Cafeteria : public Building
{
private:
	CafeteriaWorker** cafeteriaWorkers;

public:
	Cafeteria(const char* firstName, const char* lastName, const int id);
	bool addWorker(const Worker* worker);
	bool fireWorker(const Worker* worker);
	CafeteriaWorker** getCafeteriaWorkers() const;
	void printCafeteria()const;
	~Cafeteria();
};

#endif // __CAFETERIA_H

