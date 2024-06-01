#include <iostream>
#include <vector>
#include <string>
#include "Artical.h"
#include "Building.h"
#include "Cafeteria.h"
#include "CafeteriaWorker.h"
#include "Department.h"
#include "DepartmentManager.h"
#include "Doctor.h"
#include "Hospital.h"
#include "InpatientDepartment.h"
#include "Nurse.h"
#include "Patient.h"
#include "Person.h"
#include "Researcher.h"
#include "Specialization.h"
#include "Worker.h"

using namespace std;

void addWorker(vector<Worker*>& workers);
void addPatient(vector<Patient*>& patients, vector<Doctor*>& doctors, vector<Department*>& departments);
void displayDepartments(const vector<Department*>& departments);
void displayWorkers(const vector<Worker*>& workers);
void displayPatients(const vector<Patient*>& patients);
void displayBuildings(const vector<Building*>& buildings);
void changeWorkerSalary(vector<Worker*>& workers);
void addResearchToResearcher(vector<Researcher*>& researchers);
void removePatient(vector<Patient*>& patients);
void removeWorker(vector<Worker*>& workers);

int main() {
    char* nameOfHospital;
    Hospital h1(nameOfHospital);
    vector<Worker*> workers;
    vector<Patient*> patients;
    vector<Department*> departments;
    vector<Building*> buildings;
    vector<Researcher*> researchers;
    vector<Doctor*> doctors;

    int choice;
    do {
        cout << "\nHospital Management System Menu:\n";
        cout << "1. Add Worker\n";
        cout << "2. Add Patient\n";
        cout << "3. Display Departments\n";
        cout << "4. Display Workers\n";
        cout << "5. Display Patients\n";
        cout << "6. Display Buildings\n";
        cout << "7. Change Worker Salary\n";
        cout << "8. Add Research to Researcher\n";
        cout << "9. Remove Patient\n";
        cout << "10. Remove Worker\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addWorker(workers);
            break;
        case 2:
            addPatient(patients, doctors, departments);
            break;
        case 3:
            displayDepartments(departments);
            break;
        case 4:
            displayWorkers(workers);
            break;
        case 5:
            displayPatients(patients);
            break;
        case 6:
            displayBuildings(buildings);
            break;
        case 7:
            changeWorkerSalary(workers);
            break;
        case 8:
            addResearchToResearcher(researchers);
            break;
        case 9:
            removePatient(patients);
            break;
        case 10:
            removeWorker(workers);
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    // Cleanup
    for (Worker* worker : workers) delete worker;
    for (Patient* patient : patients) delete patient;
    for (Department* department : departments) delete department;
    for (Building* building : buildings) delete building;
    for (Researcher* researcher : researchers) delete researcher;
    for (Doctor* doctor : doctors) delete doctor;

    return 0;
}

void addWorker(vector<Worker*>& workers) {
    string firstName, lastName;
    int id, seniority, salary;
    double numOfHours;
    bool isOnShift;

    cout << "Enter worker's first name: ";
    cin >> firstName;
    cout << "Enter worker's last name: ";
    cin >> lastName;
    cout << "Enter worker's ID: ";
    cin >> id;
    cout << "Enter worker's seniority: ";
    cin >> seniority;
    cout << "Enter worker's salary: ";
    cin >> salary;
    cout << "Enter worker's number of hours: ";
    cin >> numOfHours;
    cout << "Is the worker on shift (1 for yes, 0 for no): ";
    cin >> isOnShift;

    Worker* worker = new Worker(seniority, salary, numOfHours);
    worker->setFirstName(firstName.c_str());
    worker->setLastName(lastName.c_str());
    worker->setOnShift(isOnShift);

    workers.push_back(worker);
}

void addPatient(vector<Patient*>& patients, vector<Doctor*>& doctors, vector<Department*>& departments) {
    string firstName, lastName, diagnosis;
    int id;
    Doctor* doctor = nullptr;
    Department* department = nullptr;

    cout << "Enter patient's first name: ";
    cin >> firstName;
    cout << "Enter patient's last name: ";
    cin >> lastName;
    cout << "Enter patient's ID: ";
    cin >> id;
    cout << "Enter patient's diagnosis: ";
    cin >> diagnosis;

    if (doctors.empty()) {
        cout << "No doctors available. Add a doctor first." << endl;
        return;
    }

    cout << "Select doctor for the patient:\n";
    for (size_t i = 0; i < doctors.size(); ++i) {
        cout << i + 1 << ". " << doctors[i]->getFirstName() << " " << doctors[i]->getLastName() << endl;
    }
    int doctorIndex;
    cin >> doctorIndex;
    doctor = doctors[doctorIndex - 1];

    if (departments.empty()) {
        cout << "No departments available. Add a department first." << endl;
        return;
    }

    cout << "Select department for the patient:\n";
    for (size_t i = 0; i < departments.size(); ++i) {
        cout << i + 1 << ". " << departments[i]->getNameOfDepartment() << endl;
    }
    int departmentIndex;
    cin >> departmentIndex;
    department = departments[departmentIndex - 1];

    Patient* patient = new Patient(diagnosis.c_str(), doctor, department);
    patient->setFirstName(firstName.c_str());
    patient->setLastName(lastName.c_str());

    patients.push_back(patient);
}

void displayDepartments(const vector<Department*>& departments) {
    for (const Department* department : departments) {
        department->printDepartment();
    }
}

void displayWorkers(const vector<Worker*>& workers) {
    for (const Worker* worker : workers) {
        worker->printWorker();
    }
}

void displayPatients(const vector<Patient*>& patients) {
    for (const Patient* patient : patients) {
        patient->printPatient();
    }
}

void displayBuildings(const vector<Building*>& buildings) {
    for (const Building* building : buildings) {
        building->printBuilding();
    }
}

void changeWorkerSalary(vector<Worker*>& workers) {
    if (workers.empty()) {
        cout << "No workers available. Add a worker first." << endl;
        return;
    }

    cout << "Select worker to change salary:\n";
    for (size_t i = 0; i < workers.size(); ++i) {
        cout << i + 1 << ". " << workers[i]->getFirstName() << " " << workers[i]->getLastName() << endl;
    }
    int workerIndex;
    cin >> workerIndex;

    int newSalary;
    cout << "Enter new salary: ";
    cin >> newSalary;

    workers[workerIndex - 1]->setSalary(newSalary);
}

void addResearchToResearcher(vector<Researcher*>& researchers) {
    if (researchers.empty()) {
        cout << "No researchers available. Add a researcher first." << endl;
        return;
    }

    cout << "Select researcher to add research:\n";
    for (size_t i = 0; i < researchers.size(); ++i) {
        cout << i + 1 << ". " << researchers[i]->getFirstName() << " " << researchers[i]->getLastName() << endl;
    }
    int researcherIndex;
    cin >> researcherIndex;

    string researchName;
    cout << "Enter research name: ";
    cin >> researchName;

    Artical* newArtical = new Artical(researchName.c_str());
    researchers[researcherIndex - 1]->addArticle(newArtical);
}

void removePatient(vector<Patient*>& patients) {
    if (patients.empty()) {
        cout << "No patients available." << endl;
        return;
    }

    cout << "Select patient to remove:\n";
    for (size_t i = 0; i < patients.size(); ++i) {
        cout << i + 1 << ". " << patients[i]->getFirstName() << " " << patients[i]->getLastName() << endl;
    }
    int patientIndex;
    cin >> patientIndex;

    delete patients[patientIndex - 1];
    patients.erase(patients.begin() + patientIndex - 1);
}

void removeWorker(vector<Worker*>& workers) {
    if (workers.empty()) {
        cout << "No workers available." << endl;
        return;
    }

    cout << "Select worker to remove:\n";
    for (size_t i = 0; i < workers.size(); ++i) {
        cout << i + 1 << ". " << workers[i]->getFirstName() << " " << workers[i]->getLastName() << endl;
    }
    int workerIndex;
    cin >> workerIndex;

    //delete workers;
}
