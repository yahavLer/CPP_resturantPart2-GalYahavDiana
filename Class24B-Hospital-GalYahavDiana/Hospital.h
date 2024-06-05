#pragma once

#ifndef __HOSPITAL_H
#define __HOSPITAL_H
class Building;
#include "Patient.h"
class Worker;

class Hospital : public Building
{
private:
	char* nameOfHospital;
	Building* allBuilding;
	Patient** allPatients;
	Worker** allWorkers;
	int numOfWorkers;
	int numOfPatients;

public:
	Hospital(const char* nameOfHospital);
	bool hospitalize_patient(Patient* patient);
	bool unhospitalize_patient(Patient* patient);
	bool add_worker(const Worker* worker);
	bool fire_worker(const Worker* worker);
	Building* getBuilding() const;
	Patient** getPatients() const;
	Worker** getWorkers() const;
	void printHospital() const;
	int getNumOfWorkers()const;
	int getNumOfPatients()const;

	~Hospital();
};

#endif // __HOSPITAL_H