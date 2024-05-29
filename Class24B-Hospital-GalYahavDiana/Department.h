#pragma once
#pragma once

#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H
//#define ID_SIZE 9
class Department
{
private:
	char* nameOfDepartment;
	DepartmentManager* DepartmentManager;
	Patient patientsOfDepartment**

public:
	Department(const char* firstName, const char* lastName, const int id);
	Department(const Department& other);
	void setFirstName(const char* n);
	void setLastName(const char* n);
	char* getFirstName() const;
	char* getLastName() const;
	void print() const;
	~Department();
};

#endif // __DEPARTMENT_H