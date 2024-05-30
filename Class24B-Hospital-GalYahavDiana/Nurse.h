#pragma once

#ifndef __NURSE_H
#define __NURSE_H
#include "Worker.h"
#include "Patient.h"
class Nurse : public Worker
{
private:

	Patient** patientsGotCare;

public:
	Nurse();
	void addPatient(const Patient* patient);
	bool callDoctor(const Doctor* Doctor);
	~Nurse();
};

#endif // __NURSE_H

