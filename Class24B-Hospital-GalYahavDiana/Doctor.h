#pragma once
#pragma once

#ifndef __DOCTOR_H
#define __DOCTOR_H
#include "Worker.h"
#include "Specialization.h"
class Doctor : public Worker
{
private:

	Patient** patientsOfDoctor;
	Specialization* specialization;


public:
	Doctor(const Specialization* Specialization);
	void putDiagnosis(const Patient* patient, const char* Diagnosis);
	~Doctor();
};

#endif // __RESEARCHER_H

