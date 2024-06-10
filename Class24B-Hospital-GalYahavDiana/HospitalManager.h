#pragma once
#ifndef __HOSPITAL_MANAGER_H
#define __HOSPITAL_MANAGER_H

#include "Worker.h"
#include "Patient.h"
#include "Department.h"
#include "Building.h"
#include "Researcher.h"
#include "Doctor.h"

class HospitalManager {
private:
    Worker* workers[100];
    Patient* patients[100];
    Department* departments[100];
    Building* buildings[100];
    Researcher* researchers[100];
    Doctor* doctors[100];

    int workerCount;
    int patientCount;
    int departmentCount;
    int buildingCount;
    int researcherCount;
    int doctorCount;
    int departmentManagerCount;

public:
    HospitalManager();
    ~HospitalManager();

    void addWorker();
    void addPatient();
    void displayDepartments() const;
    void displayWorkers() const;
    void displayPatients() const;
    void displayBuildings() const;
    void changeWorkerSalary();
    void addArticleToResearcher();
    void removePatient();
    void removeWorker();
    void changeDepartmentManager();
    void displayWorkerOnShift();
};

#endif // __HOSPITAL_MANAGER_H
