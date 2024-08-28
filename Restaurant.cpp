#define _CRT_SECURE_NO_WARNINGS
#include "restaurant.h"
#include "bar.h"
#include "kitchen.h"
#include <iostream>
#define BAR 0
#define KITCHEN 1

// Helper function to copy strings
/*void copyString(char* destination, const char* source, size_t size) {
    for (size_t i = 0; i < size - 1 && source[i] != '\0'; ++i) {
        destination[i] = source[i];
    }
    destination[size - 1] = '\0';
}*/

// Default constructor
Restaurant::Restaurant() : dailyIncome(0) 
{
    departments.push_back(new Bar());
    departments.push_back(new Kitchen());
    Menu::getInstance()->addObserver(departments.front());
    Menu::getInstance()->addObserver(departments.back());
}

// Parameterized constructor
Restaurant::Restaurant(const string& name, const string& address)
    : name(name), address(address), dailyIncome(0) 
{
    departments.push_back(new Bar());
    departments.push_back(new Kitchen());
    Menu::getInstance()->addObserver(departments.front());
    Menu::getInstance()->addObserver(departments.back());
}

// Move constructor
Restaurant::Restaurant(Restaurant&& other) noexcept
    :name(move(other.name)), address(move(other.address)), departments(other.departments), dailyOrders(move(other.dailyOrders)), dailyIncome(other.dailyIncome)
{
    for (int i = 0; i < MAX_TABLES && tables[i].getNumber()!=0; ++i)
    {
        tables[i] = move(other.tables[i]);
    }
    other.dailyIncome = 0;
}

// Destructor
Restaurant::~Restaurant() 
{
    for (auto department : departments) 
    {
        delete department;
    }
    for (auto order : dailyOrders) {
        delete order;
    }
    cout << "Restaurant destroyed.\n";
}

// Move assignment operator
Restaurant& Restaurant::operator=(Restaurant&& other) noexcept 
{
    if (this != &other)
    {
        for (auto department : departments) 
        {
            delete department;
        }
        for (auto order : dailyOrders)
        {
            delete order;
        }

        //menu = std::move(other.menu);
        for (int i = 0; i < MAX_TABLES && tables[i].getNumber() != 0; ++i) {
            tables[i] = move(other.tables[i]);
        }
        departments = move(other.departments);
        dailyOrders = move(other.dailyOrders);
        name = move(other.name);
        address = move(other.address);
        dailyIncome = other.dailyIncome;
        other.dailyIncome = 0;
    }
    return *this;
}

// Getters
Table& Restaurant::getTables() const 
{
    return const_cast<Table&>(tables[0]);
}

const list<Department*>& Restaurant::getDepartments() const 
{
    return departments;
}

const string& Restaurant::getName() const 
{
    return name;
}

const string& Restaurant::getAddress() const 
{
    return address;
}

// Setters
bool Restaurant::setName(const string& name)
{
	if (name.empty())
		return false;
    this->name=name;
    return true;
}

bool Restaurant::setAddress(const std::string& address)
{
    this->address=address;
    return true;
}


// Method to present the menu
void Restaurant::presentMenu() const 
{
    Menu::getInstance()->print();  // Use the singleton instance to present the menu
}

bool Restaurant::updateIngredientQuantity(const string& name, int quantity, int kitchen)
{
    auto it = departments.begin();
    advance(it, kitchen);
    if (it != departments.end() && *it) 
    {
        return (*it)->updateIngredientQuantity(name, quantity);
    }
    return false;
}

void Restaurant::presentTables() const
{
    for (int i = 0; i < MAX_TABLES && tables[i].getNumber() != 0; ++i) 
    {
        tables[i].printTable();
    }
}

bool Restaurant::addDrinkItemToMenu(const string& name, int volume, DrinkItem::eGlassType glass, int price, list<Ingredient*> ingredients, bool special)
{
    MenuItem* newItem = new DrinkItem(name, volume, glass, price, ingredients);
    return Menu::getInstance()->addItemToMenu(newItem, special, BAR);
}

bool  Restaurant::addFoodItemToMenu(const string& itemName, const list<Ingredient*>& list, int price, int department, bool special, bool kosher)
{
    MenuItem* newItem = new FoodItem(itemName, kosher, price, list, 0);
    return Menu::getInstance()->addItemToMenu(newItem, special, KITCHEN);
}

bool Restaurant::createNewOrderInTable(int tableNum)
{
    for (int i = 0; i < MAX_TABLES && tables[i].getNumber() != 0; i++)
    {
		if (tables[i].getNumber() == tableNum)
		{
			return tables[i].createNewOrder();
		}
    }
    return false;
}

bool Restaurant::checkAvailableIngredients(MenuItem* item) 
{
    const list<Ingredient*>& ingredients = item->getIngredientList();  //copy of ingredients for the new menu item 
    for (Ingredient* ingredient : ingredients)
    {
        bool found = false;
        for (Department* department : departments) 
        {
            Warehouse& warehouse = department->getWarehouse();
            Ingredient* warehouseIngredient = warehouse.getIngredientByName(ingredient->getName());
            if (warehouseIngredient && warehouseIngredient->getQuantity() >= ingredient->getQuantity())
            {
                found = true;
                break;
            }
        }
        if (!found) 
        {
            cout << "Error: Not enough " << ingredient->getName() << " in the warehouse to order " << item->getName() << ".\n";
            return false;
        }
    }
    return true;
}

//add item to order
bool Restaurant::addItemToOrder(int menuItemNum, int quantity, int tableNum, const string& comments)
{
	int tableIndex=getTableIndex(tableNum);
	if (tableIndex!=-1)
    {
        MenuItem* item= Menu::getInstance()->getItemByIndex(menuItemNum);
        if (item != nullptr)
        {
			if(checkAvailableIngredients(item))
                return tables[tableIndex].addItemToOrder(*item, quantity, comments);        
        }
        else 
        {
            cout << "Menu item not found.\n" << endl;
            return false;
        }
    }
    else {
        cout << "Table with that number not found.\n";
        return false;
    }
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

bool Restaurant::addIngredientToWarehouse(const string& ingredientName, int section, int forKitchen)
{
    auto it = departments.begin();
    advance(it, forKitchen);
    if (it != departments.end() && *it)
    {
        return (*it)->addIngredientToWarehouse(ingredientName, section);
    }
    return false;
}

bool Restaurant::addTables(int numOfTable) 
{
    for (int i = 0; i < MAX_TABLES; i++)
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

// Check if there are empty tables
bool Restaurant::isEmptyOfTable() const
{
    for (int i = 0; i < MAX_TABLES; i++)
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
    auto it = departments.begin();
	advance(it, 1);
    if (it != departments.end() && *it)
    {
        (*it)->printWarehouse();
    }
}

void Restaurant::showBarWarehouse() 
{
    if (!departments.empty() && departments.front())
    {
        departments.front()->printWarehouse();
    }
}

void Restaurant::showMenuWarehouse()
{
    Menu::getInstance()->print();
}

void Restaurant::showTablesWarehouse()
{
    for (int i = 0; i < MAX_TABLES && tables[i].getNumber() != 0; ++i)
    {
        tables[i].printTable();
    }
}

int Restaurant::getTableIndex(int tableNum) 
{
	for (int i = 0; i < MAX_TABLES && tables[i].getNumber() != 0; ++i)
    {
		if (tables[i].getNumber() == tableNum) 
        {
			return i;
		}
	}
	return -1;
}

void Restaurant::print() const 
{
    cout << "Restaurant Name: " << name << std::endl;
    cout << "Restaurant Address: " << address << std::endl;
    presentMenu();
    presentTables();
}