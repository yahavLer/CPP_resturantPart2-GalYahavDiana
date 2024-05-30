#pragma once

#ifndef __CAFETERIAWORKER_H
#define __CAFETERIAWORKER_H
#include "Worker.h"
#include "Specialization.h"
class CafeteriaWorker : public Worker
{
private:

	Patient** patientsOfDoctor;
	Specialization* specialization;


public:
	Doctor(const Specialization* Specialization);
	void putDiagnosis(const Patient* patient, const char* Diagnosis);
	~Doctor();
};

#endif // __CAFETERIAWORKER_H

