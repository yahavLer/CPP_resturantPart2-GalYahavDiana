#define _CRT_SECURE_NO_WARNINGS
#include "restaurant.h"
#include "bar.h"
#include "kitchen.h"
#include <iostream>

// Helper function to copy strings
void copyString(char* destination, const char* source, size_t size) {
    for (size_t i = 0; i < size - 1 && source[i] != '\0'; ++i) {
        destination[i] = source[i];
    }
    destination[size - 1] = '\0';
}

// Default constructor
Restaurant::Restaurant() : departments(nullptr), dailyOrders(nullptr), dailyIncome(0) {
    name[0] = '\0';
    address[0] = '\0';
}

// Parameterized constructor
Restaurant::Restaurant(const char* name, const char* address) : departments(new Department* [2]), dailyOrders(nullptr), dailyIncome(0 {
    copyString(this->name, name, sizeof(this->name));
    copyString(this->address, address, sizeof(this->address));
    // אתחול המחלקות עם המחלקות הנכונות - 0 עבור הבר, 1 עבור המטבח
    departments[0] = new Bar();      // בר
    departments[1] = new Kitchen();  // מטבח
}

// Move constructor
Restaurant::Restaurant(Restaurant&& other) noexcept
    : menu(std::move(other.menu)), departments(other.departments), dailyOrders(other.dailyOrders), dailyIncome(0 {
    copyString(this->name, other.name, sizeof(this->name));
    copyString(this->address, other.address, sizeof(this->address));

    other.departments = nullptr;
    other.dailyOrders = nullptr;
    other.name[0] = '\0';
    other.address[0] = '\0';
}

// Destructor
Restaurant::~Restaurant() {
    delete departments[0];  // מחיקת הבר
    delete departments[1];  // מחיקת המטבח
    delete[] departments;
    delete[] dailyOrders;
}

// Move assignment operator
Restaurant& Restaurant::operator=(Restaurant&& other) noexcept {
    if (this != &other) {
        delete[] departments;
        delete[] dailyOrders;

        menu = std::move(other.menu);
        copyString(this->name, other.name, sizeof(this->name));
        copyString(this->address, other.address, sizeof(this->address));
        departments = other.departments;
        dailyOrders = other.dailyOrders;

        other.departments = nullptr;
        other.dailyOrders = nullptr;
        other.name[0] = '\0';
        other.address[0] = '\0';
        other.dailyIncom = 0;
    }
    return *this;
}

// Getters
Table& Restaurant::getTables() const {
    return const_cast<Table&>(tables[0]);
}

Department** Restaurant::getDepartments() const {
    return departments;
}

const Menu& Restaurant::getMenu() const {
    return menu;
}

const char* Restaurant::getName() const {
    return name;
}


const char* Restaurant::getAddress() const {
    return address;
}

// Setters
bool Restaurant::setName(const char* name) {
    copyString(this->name, name, sizeof(this->name));
    return true;
}

bool Restaurant::setAddress(const char* address) {
    copyString(this->address, address, sizeof(this->address));
    return true;
}

// Method implementations
void Restaurant::presentMenu() const {
    menu.print();
}

bool Restaurant::updateIngredientQuantity(const char* name, int quantity, int kitchen) {
    if (departments && departments[kitchen]) {
        return departments[kitchen]->updateIngredientQuantity(name, quantity);
    }
    return false;
}

void Restaurant::presentTables() const {
    for (int i = 0; i < 10; ++i) {
        tables[i].printTable();
    }
}

bool Restaurant::createNewOrderInTable(int tableNum) {
    if (tableNum >= 0 && tableNum < 10) {
        return tables[tableNum].createNewOrder();
    }
    return false;
}

bool Restaurant::AddItemToOrder(int menuItemNum, int quantity) {
    return true;
}

bool Restaurant::closeBill(int tableNum) {
    if (tableNum >= 0 && tableNum < 10) {
        int total = tables[tableNum].closeBill();
        dailyIncome += total;
        return total > 0;
    }
    return false;
}

bool Restaurant::addIngredientToWarehouse(const char* ingredientName, int section, int forKitchen) {
    if (departments && departments[forKitchen]) {
        return departments[forKitchen]->addIngredientToWarehouse(ingredientName, section);
    }
    return false;
}

bool Restaurant::addTables(int numOfTables) {
    return true;
}

void Restaurant::presentDailyIncome() {
    cout << "The daily income of the resturunt is " << dailyIncome << endl;
}

void Restaurant::showKitchenWarehouse() {
    if (departments) {
        int i = 0;
        while (departments[i] != nullptr) {
            if (departments[i]) {
                departments[i]->print();
            }
            i++;
        }
    }
}

void Restaurant::showBarWarehouse() {
    if (departments) {
        int i = 0;
        while (departments[i] != nullptr) {
            if (departments[i]) {
                departments[i]->print();
            }
            i++;
        }
    }
}

void Restaurant::showMenuWarehouse() {
    menu.print();
}

void Restaurant::showTablesWarehouse() {
    for (int i = 0; i < 10; ++i) {
        tables[i].printTable();
    }
}

void Restaurant::print() const {
    std::cout << "Restaurant Name: " << name << std::endl;
    std::cout << "Restaurant Address: " << address << std::endl;
    presentMenu();
    presentTables();
}