#pragma once

#ifndef __PATIENT_H
#define __PATIENT_H
#include "Person.h"
#include "Date.h"
class Doctor;
class Nurse;
class Department;
class Patient : public Person
{
private:
	char* diagnosis;
	Date hospitalizationDate; 
	Date dischargeDate;
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
	Date getHospitalizationDate()const;
	void setDischargeDate();
	Date getDischargeDate()const;

	~Patient();
};

#endif // __PATIENT_H