#pragma once

#ifndef __HOSPITAL_H
#define __HOSPITAL_H
#include "Building.h"
#include "Patient.h"
#include "Worker.h"


//#define ID_SIZE 9
class Hospital : public Building
{
private:
	Building* allBuilding;
	Patient** allPatients;
	Worker** allWorkers;

public:
	Hospital(const char* firstName, const char* lastName, const int id);
	bool hospitalize_patient(const Patient* patient);
	bool unhospitalize_patient(const Patient* patient);
	bool add_worker(const Worker* worker);
	bool fire_worker(const Worker* worker);
	Building* getBuilding() const;
	Patient** getPatients() const;
	Worker** getWorkers() const;
	~Hospital();
};

#endif // __HOSPITAL_H