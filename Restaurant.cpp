#define _CRT_SECURE_NO_WARNINGS
#include "restaurant.h"
#include "bar.h"
#include "kitchen.h"
#include <iostream>

// Helper function to copy strings
/*void copyString(char* destination, const char* source, size_t size) {
    for (size_t i = 0; i < size - 1 && source[i] != '\0'; ++i) {
        destination[i] = source[i];
    }
    destination[size - 1] = '\0';
}*/

// Default constructor
Restaurant::Restaurant() : departments(nullptr), dailyOrders(nullptr), dailyIncome(0) 
{
    Menu::getInstance();
    name[0] = '\0';
    address[0] = '\0';
}

// Parameterized constructor
Restaurant::Restaurant(const string name, const string address) : departments(new Department* [2]), dailyOrders(nullptr), dailyIncome(0) {
    strcpy(this->name, name);
    strcpy(this->address, address);
    // There are only two departnments in the restaurant 
    departments[0] = new Bar();      
    departments[1] = new Kitchen();
}

// Move constructor
Restaurant::Restaurant(Restaurant&& other) noexcept
    : departments(other.departments), dailyOrders(other.dailyOrders), dailyIncome(other.dailyIncome)
{
    copyString(this->name, other.name, sizeof(this->name));
    copyString(this->address, other.address, sizeof(this->address));

    other.departments = nullptr;
    other.dailyOrders = nullptr;
    other.name[0] = '\0';
    other.address[0] = '\0';
}

// Destructor
Restaurant::~Restaurant() {
    // Free every alocated object from the department
    if (departments != nullptr) {
        for (int i = 0; i < 2; ++i) {
            if (departments[i] != nullptr) {
                delete departments[i];
            }
            // שחרור המערך departments עצמו
            delete[] departments;
        }
        if (departments == nullptr) {
            cout << "departments destroyed.\n";
        }
    }    

    // Free every alocated object from the daily orders 
    if (dailyOrders != nullptr) {
        for (int i = 0; dailyOrders[i] != nullptr; ++i) {
            delete dailyOrders[i];
        }
        // Delete the array of daily oreders it self
        delete[] dailyOrders;
    }
    if (dailyOrders == nullptr) {
        cout << "dailyOrders destroyed.\n";
    }
   
    cout << "Restaurant destroyed.\n";
}

// Move assignment operator
Restaurant& Restaurant::operator=(Restaurant&& other) noexcept 
{
    if (this != &other) {
        delete[] departments;
        delete[] dailyOrders;

        //menu = std::move(other.menu);
        copyString(this->name, other.name, sizeof(this->name));
        copyString(this->address, other.address, sizeof(this->address));
        departments = other.departments;
        dailyOrders = other.dailyOrders;

        other.departments = nullptr;
        other.dailyOrders = nullptr;
        other.name[0] = '\0';
        other.address[0] = '\0';
        other.dailyIncome = 0;
    }
    return *this;
}

// Getters
Table& Restaurant::getTables() const 
{
    return const_cast<Table&>(tables[0]);
}

Department** Restaurant::getDepartments() const 
{
    return departments;
}


const char* Restaurant::getName() const
{
    return name;
}


const char* Restaurant::getAddress() const
{
    return address;
}

// Setters
bool Restaurant::setName(const char* name)
{
    copyString(this->name, name, sizeof(this->name));
    return true;
}

bool Restaurant::setAddress(const char* address)
{
    copyString(this->address, address, sizeof(this->address));
    return true;
}


// Method to present the menu
void Restaurant::presentMenu() const {
    Menu::getInstance()->print();  // Use the singleton instance to present the menu
}

bool Restaurant::updateIngredientQuantity(const char* name, int quantity, int kitchen) 
{
    if (departments && departments[kitchen]) {
        return departments[kitchen]->updateIngredientQuantity(name, quantity);
    }
    return false;
}

void Restaurant::presentTables() const
{
    for (int i = 0; i < 10; ++i) {
        tables[i].printTable();
    }
}

bool  Restaurant::addDrinkItemToMenu(const char* name, int volume, DrinkItem::eGlassType glass, int price, Ingredient** ingredients, int numOfIngredients, bool special)
{
    MenuItem* newItem = new DrinkItem(name, volume, glass, price, ingredients, numOfIngredients);
    if (Menu::getInstance()->addItemToMenu(newItem, special))
        return true;
    return false;
}

bool  Restaurant::addFoodItemToMenu(const char* itemName, const int numOfIngredients, Ingredient** list, int price, int department, bool special, bool kosher)
{
    MenuItem* newItem = new FoodItem(itemName, kosher, price, list, numOfIngredients, 0);
    if(Menu::getInstance()->addItemToMenu(newItem, special))
        return true;
    return false;
}

bool Restaurant::createNewOrderInTable(int tableNum)
{
    for (int i = 0; i < 10; i++)
    {
		if (tables[i].getNumber() == tableNum)
		{
			return tables[i].createNewOrder();
		}
    }
    return false;
}

bool Restaurant::addItemToOrder(int menuItemNum, int quantity, int tableNum, char* comments)
{
	//add item to order
	if (tableNum >= 0 && tableNum < 10) {
        MenuItem* item= Menu::getInstance()->getItemByIndex(menuItemNum);
        if (item != nullptr) {
			int index = getTableIndex(tableNum);
			if (index == -1)
			{
				cout << "Table with that number not found. \n" << endl;
				return false;
            }
            else {
                return tables[index].addItemToOrder(*item, quantity, comments);
            }
        }
        else {
            cout << "Menu item not found.\n" << endl;
            return false;
        }
	}
    return true;
}

bool Restaurant::closeBill(int tableNum)
{
	int index = getTableIndex(tableNum);
	if (index == -1)
	{
		cout << "Table with that number not found. \n" << endl;
		return false;
	}
    int total = tables[index].closeBill();
    dailyIncome += total;
    return total > 0;
}

bool Restaurant::addIngredientToWarehouse(const string ingredientName, int section, int forKitchen) {
    if (departments && departments[forKitchen]) {
        return departments[forKitchen]->addIngredientToWarehouse(ingredientName, section);
    }
    return false;
}

bool Restaurant::addTables(int numOfTable) {
    for (int i = 0; i < 10; i++)
    {
        if (tables[i].getNumber() == 0 )
        {
            tables[i].setNumber(numOfTable);
            return true;
        }
        else if(tables[i].getNumber() == numOfTable){
			return false;
        }
    }
    return false;
}

bool Restaurant::isEmptyOfTable()
{
    for (int i = 0; i < 10; i++)
    {
        if (tables[i].getNumber() != 0)
            return true;
    }
    return false;
}

void Restaurant::presentDailyIncome()
{
    cout << "The daily income of the resturunt is " << dailyIncome << endl;
}

void Restaurant::showKitchenWarehouse() 
{
    if (departments[1]) 
    {
        departments[1]->printWarehouse();
    }
}

void Restaurant::showBarWarehouse() {
    if (departments[0])
    {
        departments[0]->printWarehouse();
    }
}

void Restaurant::showMenuWarehouse() {
    Menu::getInstance()->print();
}

void Restaurant::showTablesWarehouse() {
    for (int i = 0; i < 10; ++i) {
        tables[i].printTable();
    }
}

int Restaurant::getTableIndex(int tableNum) {
	for (int i = 0; i < 10; ++i) {
		if (tables[i].getNumber() == tableNum) {
			return i;
		}
	}
	return -1;
}

void Restaurant::print() const 
{
    std::cout << "Restaurant Name: " << name << std::endl;
    std::cout << "Restaurant Address: " << address << std::endl;
    presentMenu();
    presentTables();
}