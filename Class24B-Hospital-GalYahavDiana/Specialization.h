#pragma once

#ifndef __SPECIALIZATION_H
#define __SPECIALIZATION_H

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
	bool addResearcher(const Researcher& researcher);
	void printSpecialization() const;
	~Specialization();
};

#endif // __SPECIALIZATION_H