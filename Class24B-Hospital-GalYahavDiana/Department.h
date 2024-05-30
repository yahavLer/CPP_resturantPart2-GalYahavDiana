#pragma once

#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H
#include "Person.h"
#include "DepartmentManager.h"
#include "Worker.h"
//#define ID_SIZE 9
class Department
{
private:
	char* nameOfDepartment;
	DepartmentManager* DepartmentManager;
	Patient** patientsOfDepartment;
	Worker** staffOfDepartment;

public:
	Department(char* nameOfDepartment, DepartmentManager* DepartmentManager, Patient** patientsOfDepartment);
	Department(const Department& other);
	void setNameOfDepartment(const char* nameOfDepartment);
	void getNameOfDepartment() const;
	void setDepartmentManager(const DepartmentManager* DepartmentManager);
	void getDepartmentManager()const;
	bool addWorkerToDepartment(const Worker& worker) ;
	bool RemoveWorkerToDepartment(const Worker& worker);
	bool hospitalizePatient(const Patient& patient) ;
	bool dischargedPatient(const Patient& patient);
	void print() const;
	~Department();
};

#endif // __DEPARTMENT_H