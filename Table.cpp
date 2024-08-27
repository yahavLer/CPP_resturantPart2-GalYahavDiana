#include <iostream>
using namespace std;

#include "Table.h"

Table::Table() : order(nullptr), number(0) {}

Table::Table(Table&& other) noexcept : order(other.order), number(other.number) 
{
    other.order = nullptr;
    other.number = 0;
}

Table::~Table()
{
    clear();
}

Table::Table(int number) : order(nullptr), number(number) 
{
    // Constructor with table number
}

Order* Table::getOrder() const
{
    return order;
}

bool Table::setNumber(int newNumber) 
{
    if (newNumber > 0) {
        number = newNumber;
        return true;
    }
    return false;
}

bool Table::createNewOrder() 
{
    if (order) 
    {
        delete order;
    }
    order = new Order(); 
    return true;
}

bool Table::addItemToOrder(const MenuItem& menuItem, int quantity, std::string& comments)
{
    if (!order)
    {
        return false;
    }
    order->addItemToOrder(menuItem, quantity, comments);
    return true;
}

int Table::closeBill() 
{
    if (!order) 
    {
        return 0;
    }
    order->print();
    int total = order->closeBill();
    delete order;
    order = nullptr;
    return total;
}

void Table::printTable() const 
{
    cout << "Table Number: " << number << endl;
    if (order)
    {
        order->print();
        cout << endl;
    }
    else 
    {
        cout << "No current order." << endl;
    }

}
void Table::clear() 
{
    if (order) 
    {
        delete order;  //deletin oreder if there is one
        order = nullptr;  
    }
    number = 0;  // intiate number of table
}