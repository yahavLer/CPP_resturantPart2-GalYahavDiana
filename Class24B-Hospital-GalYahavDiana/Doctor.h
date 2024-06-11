#pragma once

#ifndef __DOCTOR_H
#define __DOCTOR_H
#include "Worker.h"
#include "Specialization.h"
class Patient;
class Doctor : public Worker
{
private:

	Patient** patientsOfDoctor;
	Specialization** specialization;
	int numOfPatientsOfDoctor;
	int numOfSpecialization;

public:
	Doctor();
	Doctor(const Doctor& other);
	bool healPatient(Patient* patient);
	bool putDiagnosis(Patient* patient, const char* Diagnosis);
	bool addPatient(Patient* patient);
	bool removePatient(Patient* patient); //remove patient from the doctor's list to other doctor
	Patient** getPatients() const;
	bool addSpecialization(const Specialization* specialization);
	Specialization** getSpecializations() const;
	int getNumOfPatientsOfDoctor() const;
	int getNumOfSpecialization() const;
	void printDoctor() const;
	~Doctor();
};

#endif // __DOCTOR_H

