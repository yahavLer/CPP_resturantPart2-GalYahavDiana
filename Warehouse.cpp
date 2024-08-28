#include "Warehouse.h"
#include "menuItemInOrder.h"
#include <iostream>
using namespace std;

Warehouse::Warehouse() {}

// Move constructor
Warehouse::Warehouse(Warehouse&& other) noexcept
    : ingredientList(move(other.ingredientList)), ingredientQuantityList(move(other.ingredientQuantityList)){}

// Destructor
Warehouse::~Warehouse() {
    clear();
}

// Move assignment operator
Warehouse& Warehouse::operator=(Warehouse&& other) noexcept 
{
    if (this != &other) {
        clear();  

        ingredientList = move(other.ingredientList);
        ingredientQuantityList = move(other.ingredientQuantityList);

        /*ingredientQuantityList = other.ingredientQuantityList;
        numIngredients = other.numIngredients;

        other.ingredientQuantityList = nullptr;
        other.numIngredients = 0;*/
    }
    return *this;
}

// Getters
LinkedList<Ingredient>& Warehouse::getIngredientList() 
{
    return ingredientList;
}

const list<int>& Warehouse::getIngredientQuantityList() const
{
    return ingredientQuantityList;
}

// Update ingredient quantity
bool Warehouse::updateIngredientQuantity(const Ingredient* ingredient, int quantity) 
{
    //LinkedList<Ingredient>::Node* currentIngredient = ingredientList.getHead();
    auto itQuantity = ingredientQuantityList.begin();
    LinkedList<Ingredient>::Iterator itIngredient = ingredientList.getHead();
    while (itIngredient != nullptr && itQuantity != ingredientQuantityList.end())
    {
        if ((*itIngredient).getName() == ingredient->getName())
        {
            *itQuantity += quantity;
            return true;
        }
        ++itIngredient;  // Move to the next node in the ingredient list
        ++itQuantity;
    }
    /*for (int i = 0; i < numIngredients; ++i) {
        if (compareStrings(ingredientList[i]->getName(), ingredient->getName())) {
            ingredientQuantityList[i] = quantity;
            return true;
        }
    }*/
    return false;
}

// Add ingredient to warehouse
bool Warehouse::addIngredientToWarehouse(const string& ingredientName, int section)
{
    Ingredient ingToAdd = Ingredient(ingredientName, static_cast<Ingredient::eSection>(section), 0);
    ingredientList.addToEnd(ingToAdd);
    ingredientQuantityList.push_back(0);

    print();
    return true;
}

void Warehouse::print() const 
{
    auto itQuantity = ingredientQuantityList.begin();
    LinkedList<Ingredient>::Iterator currentIngredient = ingredientList.getHead();
    if (currentIngredient != nullptr)
    {
        while (currentIngredient != nullptr && itQuantity != ingredientQuantityList.end())
        {
            (*currentIngredient).print();
            cout << "Current Quantity: " << *itQuantity << endl;
            ++currentIngredient;
			++itQuantity;
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
//void Warehouse::clear() {
//    if (numIngredients) {
//        //ingredientList.clear();
//        delete[] ingredientQuantityList;
//    }
//    ingredientQuantityList = nullptr;
//    numIngredients = 0;
//    /*
//    * GPT
//    * ingredientList.clear();  // Assuming you have implemented a clear() function in CustomLinkedList
//    ingredientQuantityList.clear();
//    numIngredients = 0;
//    */
//}
void Warehouse::clear() {
    ingredientList.clear(); //ask diana
    ingredientQuantityList.clear();
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
