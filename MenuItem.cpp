#include "MenuItem.h"
#include <iostream>
#include <utility>

MenuItem::MenuItem(const string& itemName, list<Ingredient*> list, int price)
    : name(itemName), price(price), ingredientList(list) {}

// Default constructor
MenuItem::MenuItem() :name(""), price(0), ingredientList() {}

// Destructor
MenuItem::~MenuItem() {
    clearIngredients();
}

// Move constructor
MenuItem::MenuItem(MenuItem&& other) noexcept
    :name(move(other.name)), price(other.price), ingredientList(move(other.ingredientList))
{}

// Copy constructor
MenuItem::MenuItem(const MenuItem& other)
    : name(other.name), price(other.price), ingredientList(other.ingredientList) { }

// Copy assignment operator
MenuItem& MenuItem::operator=(const MenuItem& other)
{
    if (this != &other)
    {
       clearIngredients();
       name = other.name;
       price = other.price;
       ingredientList = other.ingredientList;
    }
    return *this;
}

// Move assignment operator
MenuItem& MenuItem::operator=(MenuItem&& other) noexcept 
{
    if (this != &other) 
    {
        clearIngredients();
        name = move(other.name);
        price = other.price;
        ingredientList = move(other.ingredientList);
    }
    return *this;
}

/*********
* Satters 
**********/
bool MenuItem::setPrice(int newPrice)
{
    if (price != 0)
    {
        price = newPrice;
        return true;
    }
    return false; 
}

bool MenuItem::setIngredients(list<Ingredient*> list)
{
    clearIngredients();
    ingredientList = move(list);
    return true;
}

void MenuItem::clearIngredients() 
{
    ingredientList.clear();
}

const list<Ingredient*>& MenuItem::getIngredientList() const
{
    return ingredientList;
}


bool MenuItem::setName(const std::string& newName)
{
    if (!newName.empty()) {
        name = newName;
        return true;
    }
    return false;
}

