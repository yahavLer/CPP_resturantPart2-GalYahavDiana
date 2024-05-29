#pragma once

#ifndef __PATIENT_H
#define __PATIENT_H
//#define ID_SIZE 9
class Patient : class Person
{
private:
	char* diagnosis;
//	DATE hospitalizationDate; 
//	DATE dischargeDate;
	Doctor* doctor;
	Department* department;

public:
	Patient(char* diagnosis, Doctor* doctor, Department* department);
	Patient(const Patient& other);
	void setDoctor(Doctor* doctor);
	void getDoctor() const;
	void setDepartment(Department* department);
	void getDepartment() const;
	void setDiagnosis(char* diagnosis);
	void getDiagnosis() const;
	void print() const;
	~Patient();
};

#endif // __PATIENT_H