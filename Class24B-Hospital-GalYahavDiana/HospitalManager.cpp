#include "HospitalManager.h"
#include <iostream>
#include <cstring>

using namespace std;

HospitalManager::HospitalManager() {
    workerCount = 0;
    patientCount = 0;
    departmentCount = 0;
    buildingCount = 0;
    researcherCount = 0;
    doctorCount = 0;
    departmentManagerCount = 0;
}


HospitalManager::~HospitalManager() {
    for (int i = 0; i < workerCount; ++i) delete workers[i];
    for (int i = 0; i < patientCount; ++i) delete patients[i];
    for (int i = 0; i < departmentCount; ++i) delete departments[i];
    for (int i = 0; i < buildingCount; ++i) delete buildings[i];
    for (int i = 0; i < researcherCount; ++i) delete researchers[i];
    for (int i = 0; i < doctorCount; ++i) delete doctors[i];
}

void HospitalManager::addWorker() {
    char firstName[50], lastName[50];
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
    worker->setFirstName(firstName);
    worker->setLastName(lastName);
    worker->setOnShift(isOnShift);

    workers[workerCount++] = worker;
}

void HospitalManager::addPatient() {
    char firstName[50], lastName[50], diagnosis[100];
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

    if (doctorCount == 0) {
        cout << "No doctors available. Add a doctor first." << endl;
        return;
    }

    cout << "Select doctor for the patient:\n";
    for (int i = 0; i < doctorCount; ++i) {
        cout << i + 1 << ". " << doctors[i]->getFirstName() << " " << doctors[i]->getLastName() << endl;
    }
    int doctorIndex;
    cin >> doctorIndex;
    doctor = doctors[doctorIndex - 1];

    if (departmentCount == 0) {
        cout << "No departments available. Add a department first." << endl;
        return;
    }

    cout << "Select department for the patient:\n";
    for (int i = 0; i < departmentCount; ++i) {
        cout << i + 1 << ". " << departments[i]->getNameOfDepartment() << endl;
    }
    int departmentIndex;
    cin >> departmentIndex;
    department = departments[departmentIndex - 1];

    Patient* patient = new Patient(diagnosis, doctor, department);
    patient->setFirstName(firstName);
    patient->setLastName(lastName);

    patients[patientCount++] = patient;
}

void HospitalManager::displayDepartments() const {
    for (int i = 0; i < departmentCount; ++i) {
        departments[i]->printDepartment();
    }
}

void HospitalManager::displayWorkers() const {
    for (int i = 0; i < workerCount; ++i) {
        workers[i]->printWorker();
    }
}

void HospitalManager::displayPatients() const {
    for (int i = 0; i < patientCount; ++i) {
        patients[i]->printPatient();
    }
}

void HospitalManager::displayBuildings() const {
    for (int i = 0; i < buildingCount; ++i) {
        buildings[i]->printBuilding();
    }
}

void HospitalManager::changeWorkerSalary() 
{
    if (workerCount == 0) {
        cout << "No workers available. Add a worker first." << endl;
        return;
    }

    cout << "Select worker to change salary:\n";
    for (int i = 0; i < workerCount; ++i) {
        cout << i + 1 << ". " << workers[i]->getFirstName() << " " << workers[i]->getLastName() << endl;
    }
    int workerIndex;
    cin >> workerIndex;

    int newSalary;
    cout << "Enter new salary: ";
    cin >> newSalary;

    workers[workerIndex - 1]->setSalary(newSalary);
}

void HospitalManager::addArticleToResearcher() 
{
    if (researcherCount == 0) {
        cout << "No researchers available. Add a researcher first." << endl;
        return;
    }

    cout << "Select researcher to add research:\n";
    for (int i = 0; i < researcherCount; ++i) {
        cout << i + 1 << ". " << researchers[i]->getFirstName() << " " << researchers[i]->getLastName() << endl;
    }
    int researcherIndex;
    cin >> researcherIndex;

    char researchName[100];
    cout << "Enter research name: ";
    cin >> researchName;

    Artical* newArtical = new Artical(researchName);
    researchers[researcherIndex - 1]->addArticle(*newArtical);
}

void HospitalManager::removePatient()
{
    if (patientCount == 0) {
        cout << "No patients available." << endl;
        return;
    }

    cout << "Select patient to remove:\n";
    for (int i = 0; i < patientCount; ++i) {
        cout << i + 1 << ". " << patients[i]->getFirstName() << " " << patients[i]->getLastName() << endl;
    }
    int patientIndex;
    cin >> patientIndex;

    delete patients[patientIndex - 1];
    for (int i = patientIndex - 1; i < patientCount - 1; ++i) {
        patients[i] = patients[i + 1];
    }
    --patientCount;
}

void HospitalManager::removeWorker() 
{
    if (workerCount == 0) {
        cout << "No workers available." << endl;
        return;
    }

    cout << "Select worker to remove:\n";
    for (int i = 0; i < workerCount; ++i) {
        cout << i + 1 << ". " << workers[i]->getFirstName() << " " << workers[i]->getLastName() << endl;
    }
    int workerIndex;
    cin >> workerIndex;

    delete workers[workerIndex - 1];
    for (int i = workerIndex - 1; i < workerCount - 1; ++i) {
        workers[i] = workers[i + 1];
    }
    --workerCount;
}
void HospitalManager::changeDepartmentManager()
{
    if (departmentCount == 0) {
        cout << "No departments available. Add a department first." << endl;
        return;
    }

    cout << "Select department to change manager:\n";
    for (int i = 0; i < departmentCount; ++i) {
        cout << i + 1 << ". " << departments[i]->getNameOfDepartment() << endl;
    }
    int departmentIndex;
    cin >> departmentIndex;

    if (departmentManagerCount == 0) {
        cout << "No department managers available. Add a department manager first." << endl;
        return;
    }

    cout << "Select new manager for the department:\n";
    for (int i = 0; i < departmentManagerCount; ++i) {
        cout << i + 1 << ". " << departmentManagers[i]->getFirstName() << " " << departmentManagers[i]->getLastName() << endl;
    }
    int managerIndex;
    cin >> managerIndex;

    departments[departmentIndex - 1]->setDepartmentManager(departmentManagers[managerIndex - 1]);
}
void HospitalManager::displayWorkerOnShift()
{

}
