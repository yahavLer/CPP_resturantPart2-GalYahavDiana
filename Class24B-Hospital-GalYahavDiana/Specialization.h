#pragma once

#ifndef __SPECIALIZATION_H
#define __SPECIALIZATION_H
#include "Doctor.h"

class Specialization 
{
private:
	char* nameOfSpecialization;
	Doctor** listOfDoctorWithSpecial;
	int numOfDoctors;

public:
	Specialization(char* nameOfSpecialization);
	Specialization(const Specialization& other);
	bool setNameOfArtical(const char* nameOfArtical);
	char* getNameOfArtical() const;
	int getnumOfDoctors() const;
	Doctor** getListOfDoctorWithSpecial() const;
	bool addDoctorWithSpecial(const Doctor* doctor);
	bool removeDoctorWithSpecial(const Doctor* doctor);
	void printSpecialization() const;
	~Specialization();
};

#endif // __SPECIALIZATION_H