#pragma once

#ifndef __CAFETERIA_H
#define __CAFETERIA_H
#include "Building.h"
#include "CafeteriaWorker.h"

//#define ID_SIZE 9
class Hospital : public Building
{
private:
	CafeteriaWorker** cafeteriaWorkers;

public:
	Hospital(const char* firstName, const char* lastName, const int id);
	bool hospitalize_patient(Patient* patient);
	~Hospital();
};

#endif // __CAFETERIA_H
