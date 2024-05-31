#pragma once

#ifndef __INPATIENTDEPARTMENT_H
#define __INPATIENTDEPARTMENT_H
#include "Building.h"
#include "Department.h"

class InpatientDepartment : public Building
{
private:
	Department** allDepartments;

public:
	InpatientDepartment();
	bool addDepartment(const Department* department);
    bool removeDepartment(const Department* department);
    Department** getDepartments() const;
    void printInpatientDepartment() const;
};

#endif // __INPATIENTDEPARTMENT_H

