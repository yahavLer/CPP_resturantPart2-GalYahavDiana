#pragma once

#ifndef __PATIENT_H
#define __PATIENT_H
#include "Doctor.h"
#include "Department.h"
#include "Person.h"
#include "Nurse.h"

class Patient : public Person
{
private:
	char* diagnosis;
//	DATE hospitalizationDate; 
//	DATE dischargeDate;
	Doctor* doctor; // Pointer to the doctor who treats the patient
	Department* department;

public:
	Patient(char* diagnosis, Doctor* doctor, Department* department);
	Patient(const Patient& other);
	bool setDoctor(Doctor* doctor);
	Doctor* getDoctor() const;
	bool setDepartment(Department* department);
	Department* getDepartment() const;
	bool setDiagnosis(char* diagnosis);
	char* getDiagnosis() const;
	Nurse* callNurse();
	void printPatient() const;
	~Patient();
};

#endif // __PATIENT_H