#include "Warehouse.h"
#include "Ingredient.h"
#include "menuItemInOrder.h"
#include "linkedList.h"
#include <string>
#include <iostream>


using namespace std;

Warehouse::Warehouse() : ingredientQuantityList(nullptr), numIngredients(0)
{
}

// Move constructor
Warehouse::Warehouse(Warehouse&& other) noexcept
    : ingredientList(std::move(other.ingredientList)), ingredientQuantityList(other.ingredientQuantityList), numIngredients(other.numIngredients)
{
    other.ingredientQuantityList = nullptr;
    other.numIngredients = 0;
}

// Destructor
Warehouse::~Warehouse() {
    clear();
}

// Move assignment operator
Warehouse& Warehouse::operator=(Warehouse&& other) noexcept 
{
    if (this != &other) {
        clear();  

        ingredientList = std::move(other.ingredientList);
        ingredientQuantityList = other.ingredientQuantityList;
        numIngredients = other.numIngredients;

        other.ingredientQuantityList = nullptr;
        other.numIngredients = 0;
    }
    return *this;
}

// Getters
LinkedList<Ingredient>& Warehouse::getIngredientList() 
{
    return ingredientList;
}

int* Warehouse::getIngredientQuantityList() const 
{
    return ingredientQuantityList;
}

// Update ingredient quantity
bool Warehouse::updateIngredientQuantity(const Ingredient* ingredient, int quantity) 
{

    //LinkedList<Ingredient>::Node* currentIngredient = ingredientList.getHead();
    LinkedList<Ingredient>::Iterator temp = ingredientList.getHead();
    while (temp != nullptr)
    {
        int index = 0;

        if ((*temp).getName() == ingredient->getName())
        {
            ingredientQuantityList[index] = quantity;
            return true;
        }

        ++temp;  // Move to the next node in the ingredient list

    }
    /*for (int i = 0; i < numIngredients; ++i) {
        if (compareStrings(ingredientList[i]->getName(), ingredient->getName())) {
            ingredientQuantityList[i] = quantity;
            return true;
        }
    }
    return false;*/
    return false;
}

// Add ingredient to warehouse
bool Warehouse::addIngredientToWarehouse(const std::string& ingredientName, int section)
{
    // Create new lists with one additional slot
    //Ingredient** newIngredientList = new Ingredient*[numIngredients + 1];
    int* newIngredientQuantityList = new int[numIngredients + 1];

    // Copy existing data to new lists
    for (int i = 0; i < numIngredients; ++i) {
        //newIngredientList[i] = ingredientList[i];
        newIngredientQuantityList[i] = ingredientQuantityList[i];
    }

    // Add the new ingredient
    Ingredient ingToAdd =  Ingredient(ingredientName, static_cast<Ingredient::eSection>(section), 0);
    ingredientList.addToEnd(ingToAdd);
    //newIngredientList[numIngredients] = new Ingredient(ingredientName, static_cast<Ingredient::eSection>(section), 0);
    newIngredientQuantityList[numIngredients] = 0;

    // Clean up old list
    delete[] ingredientQuantityList;

    // Assign new lists to class members
    //ingredientList = newIngredientList;
    ingredientQuantityList = newIngredientQuantityList;
    numIngredients++;
    print();

    return true;
}

void Warehouse::print() const 
{
    LinkedList<Ingredient>::Iterator currentIngredient = ingredientList.getHead();
    if (currentIngredient != nullptr)
    {
        int index = 0;
        while (currentIngredient != nullptr)
        {
            (*currentIngredient).print();
            cout << "Current Quantity: " << ingredientQuantityList[index] << endl;
            ++currentIngredient;
        }
    }
    else {
        cout << "Warehouse is empty or uninitialized." << endl;
    }
    /* GPT
    * Node<Ingredient>* currentIngredient = ingredientList.getHead();

    while (currentIngredient != nullptr && currentQuantity != nullptr)
    {
        currentIngredient->data.print(); // Assuming Ingredient has a print() method
        std::cout << "Quantity: " << currentQuantity->data << std::endl;
        currentIngredient = currentIngredient->next;
        currentQuantity = currentQuantity->next;
    }

    if (ingredientList.isEmpty()) {
        std::cout << "Warehouse is empty or uninitialized." << std::endl;
    }
    */
}


// Internal function for memory cleaning
void Warehouse::clear() {
    if (numIngredients) {
        //ingredientList.clear();
        delete[] ingredientQuantityList;
    }
    ingredientQuantityList = nullptr;
    numIngredients = 0;
    /*
    * GPT
    * ingredientList.clear();  // Assuming you have implemented a clear() function in CustomLinkedList
    ingredientQuantityList.clear();
    numIngredients = 0;
    */
}

// fumction for comparing strings 
/*bool Warehouse::compareStrings(const char* str1, const char* str2) const
{
    while (*str1 && (*str1 == *str2))
    {
        ++str1;
        ++str2;
    }
    return *str1 == *str2;
}*/

// function for finding ingridient by name 
Ingredient* Warehouse::getIngredientByName(const std::string& ingredientName) const
{

    LinkedList<Ingredient>::Iterator currentIngredient = ingredientList.getHead();

    while (currentIngredient != nullptr) {
        if ((*currentIngredient).getName() == ingredientName)
        {
    
            return &(*currentIngredient);  // return the address of the ingredient
        }
        ++currentIngredient;
    }
    return nullptr;
    /*GPT
      Node<Ingredient>* current = ingredientList.getHead();
    while (current != nullptr) {
        if (compareStrings(current->data.getName(), ingredientName)) {
            return &current->data;
        }
        current = current->next;
    }
    return nullptr;
    */
}
