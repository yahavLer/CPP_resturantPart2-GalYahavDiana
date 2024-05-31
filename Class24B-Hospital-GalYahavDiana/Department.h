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
	DepartmentManager* departmentManager;
	Patient** patientsOfDepartment;
	Worker** staffOfDepartment;

public:
	Department(char* nameOfDepartment, DepartmentManager* DepartmentManager);
	Department(const Department& other);
	bool setNameOfDepartment(const char* nameOfDepartment);
	char* getNameOfDepartment() const;
	bool setDepartmentManager(DepartmentManager* DepartmentManager);
	DepartmentManager* getDepartmentManager()const;
	bool addWorkerToDepartment(Worker& worker) ;
	bool removeWorkerFromDepartment(Worker& worker);
	bool addPatient(Patient& patient) ;
	bool removePatient(Patient& patient);
	Worker** getAllstaffOfDepartment()const;
	Patient** getAllpatientsOfDepartment()const;
	void printDepartment() const;
	~Department();
};

#endif // __DEPARTMENT_H