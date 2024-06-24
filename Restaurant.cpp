#include "Restaurant.h"
#include <cstring>
#include <iostream>

// Default constructor
Restaurant::Restaurant() : departments(nullptr), dailyOrders(nullptr) {
    std::strcpy(name, "");
    std::strcpy(address, "");
}

// Parameterized constructor
Restaurant::Restaurant(char* name, char* address) : departments(nullptr), dailyOrders(nullptr) {
    std::strcpy(this->name, name);
    std::strcpy(this->address, address);
}

// Move constructor
Restaurant::Restaurant(Restaurant&& other)
    : menu(std::move(other.menu)) {
    std::strcpy(name, other.name);
    std::strcpy(address, other.address);
    departments = other.departments;
    dailyOrders = other.dailyOrders;

    other.departments = nullptr;
    other.dailyOrders = nullptr;
    std::strcpy(other.name, "");
    std::strcpy(other.address, "");
}

// Destructor
Restaurant::~Restaurant() {
    delete[] departments;
    delete[] dailyOrders;
}

// Move assignment operator
const Restaurant& Restaurant::operator=(Restaurant&& other) {
    if (this != &other) {
        delete[] departments;
        delete[] dailyOrders;

        menu = std::move(other.menu);
        std::strcpy(name, other.name);
        std::strcpy(address, other.address);
        departments = other.departments;
        dailyOrders = other.dailyOrders;

        other.departments = nullptr;
        other.dailyOrders = nullptr;
        std::strcpy(other.name, "");
        std::strcpy(other.address, "");
    }
    return *this;
}

// Getters
Table& Restaurant::getTables() const {
    return const_cast<Table&>(tables[0]);  // Assuming a single table is returned, you might need to adjust this based on your design
}

Department**& Restaurant::getDepartments() const {
    return const_cast<Department**&>(departments);
}

Menu Restaurant::getMenu() const {
    return menu;
}

char& Restaurant::getName() const {
    return const_cast<char&>(name[0]);
}

char& Restaurant::getAdress() const {
    return const_cast<char&>(address[0]);
}

// Setters
bool Restaurant::setName(char* name) {
    std::strcpy(this->name, name);
    return true;
}

bool Restaurant::setAdress(char* address) {
    std::strcpy(this->address, address);
    return true;
}

// Method implementations
void Restaurant::presentMenu() {
    menu.print();
}

bool Restaurant::updateIngredientQuantity(char* name, int quantity, int kitchen) {
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
    // Assuming logic to add item to an order
    return true;
}

bool Restaurant::closeBill(int tableNum) {
    if (tableNum >= 0 && tableNum < 10) {
        return tables[tableNum].closeBill() > 0;
    }
    return false;
}

bool Restaurant::addIngredientToWarehouse(char* ingredientName, int section, int forKitchen) {
    if (departments && departments[forKitchen]) {
        return departments[forKitchen]->addIngredientToWarehouse(ingredientName, section);
    }
    return false;
}

bool Restaurant::addTables(int numOfTables) {
    // Assuming logic to add tables
    return true;
}

void Restaurant::presentDailyIncome() {
    // Assuming logic to present daily income
}

void Restaurant::print() const {
    std::cout << "Restaurant Name: " << name << std::endl;
    std::cout << "Restaurant Address: " << address << std::endl;
    presentMenu();
    presentTables();
}
