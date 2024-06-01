#pragma once

#ifndef __DOCTOR_H
#define __DOCTOR_H
#include "Patient.h"
#include "Specialization.h"
class Doctor : public Worker
{
private:

	Patient** patientsOfDoctor;
	Specialization** specialization;


public:
	Doctor(const Specialization* Specialization);
	bool healPatient(Patient* patient);
	bool putDiagnosis(Patient* patient, const char* Diagnosis);
	bool addPatient(Patient* patient);
	bool removePatient(Patient* patient); //remove patient from the doctor's list to other doctor
	Patient** getPatients() const;
	Specialization** getSpecialization() const;
	void printDoctor() const;
	~Doctor();
};

#endif // __DOCTOR_H

