#include <iostream>
#include "HospitalManager.h"

using namespace std;

int main() {
    HospitalManager manager;
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
        cout << "8. Add Article to Researcher\n";
        cout << "9. Remove Patient\n";
        cout << "10. Remove Worker\n";
        cout << "11. Change Department Manager\n";
        cout << "12. display Worker On Shift\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            manager.addWorker();
            break;
        case 2:
            manager.addPatient();
            break;
        case 3:
            manager.displayDepartments();
            break;
        case 4:
            manager.displayWorkers();
            break;
        case 5:
            manager.displayPatients();
            break;
        case 6:
            manager.displayBuildings();
            break;
        case 7:
            manager.changeWorkerSalary();
            break;
        case 8:
            manager.addArticleToResearcher();
            break;
        case 9:
            manager.removePatient();
            break;
        case 10:
            manager.removeWorker();
            break;
        case 11:
            manager.changeDepartmentManager();
            break;
        case 12:
            manager.displayWorkerOnShift();
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
