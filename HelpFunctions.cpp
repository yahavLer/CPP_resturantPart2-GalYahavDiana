#include <iostream>
#include "helpFunctions.h"
#include "restaurant.h"

const int FOOD_DEPARTMENT = 1;
const int DRINK_DEPARTMENT = 0;
const int MAX_NAME_LENGTH = 20;
const int MAX_ADDRESS_LENGTH = 20;

// defalt constructor
HelpFunctions::HelpFunctions() {}
 
// default destructor
HelpFunctions::~HelpFunctions() {}

int HelpFunctions::userIntValidation() 
{
    int temp;
    while (!(cin >> temp)) 
    {
        cin.clear();
        cin.ignore();
        cout << "Invalid input. Please enter an integer: ";
    }
    return temp;
}

void HelpFunctions::initRestaurant(Restaurant* restaurant) 
{
    // Initiate case 1
    restaurant->addTables(5);
    restaurant->addTables(3);

    // Initiate case 2
    restaurant->addIngredientToWarehouse("Tomato", 4, FOOD_DEPARTMENT); // Kitchen Warehouse
    restaurant->addIngredientToWarehouse("Lemon", 4, DRINK_DEPARTMENT);  // Bar Warehouse
    restaurant->addIngredientToWarehouse("Chicken", 2, FOOD_DEPARTMENT); // Kitchen Warehouse
    restaurant->addIngredientToWarehouse("Mint", 0, DRINK_DEPARTMENT);  // Bar Warehouse

    // Initiate case 3
    restaurant->updateIngredientQuantity("Tomato", 10, FOOD_DEPARTMENT);
    restaurant->updateIngredientQuantity("Lemon", 20, DRINK_DEPARTMENT);
    restaurant->updateIngredientQuantity("Chicken", 30, FOOD_DEPARTMENT);
    restaurant->updateIngredientQuantity("Mint", 40, DRINK_DEPARTMENT);

    // Initiate case 4 
    list<Ingredient*> ingredientList;
    ingredientList.push_back(new Ingredient("Lemon", Ingredient::eSection::DAIRY, 2));
    restaurant->addDrinkItemToMenu("Lemonade", 100, DrinkItem::eGlassType::HIGHBOAL, 15, ingredientList, false);
    restaurant->addDrinkItemToMenu("Miranda", 50, DrinkItem::eGlassType::LOWBOAL, 25, ingredientList, true);

    // Initiate case 5 
    list<Ingredient*> ingredientList2;
    ingredientList2.push_back(new Ingredient("Tomato", Ingredient::eSection::VEGETABLES, 2));
    ingredientList2.push_back(new Ingredient("Chicken", Ingredient::eSection::MEAT, 2));
    restaurant->addFoodItemToMenu("Chicken Salad", ingredientList2, 30, FOOD_DEPARTMENT, false, true);
    restaurant->addFoodItemToMenu("Tomato Salad", ingredientList2, 20, FOOD_DEPARTMENT, true, false);
}

Ingredient* HelpFunctions::getValidIngredient(Warehouse& warehouse) 
{
    string ingredientName;
    Ingredient* ingredientToCopy = nullptr;

    while (ingredientToCopy == nullptr) 
    {
        cin.ignore();
        cout << "Please enter the ingredient name or type 'exit' to return to the menu: ";
        getline(cin, ingredientName);
        if (ingredientName == "exit") 
        {
            return nullptr;  // delete alocated pointers
        }
        ingredientToCopy = warehouse.getIngredientByName(ingredientName);
        if (ingredientToCopy == nullptr) 
        {
            cout << "The ingredient name does not exist in the warehouse. Please enter a different name or type 'exit' to return to the menu.\n";
        }
    }
    return ingredientToCopy;
}

void HelpFunctions::gatherDrinkInfo(string& mealName, int& price, int& volume, int& glassType, bool& special)
{
    bool validInput = false;
    while (!validInput)
    {
        try
        {
            cout << "Please enter the name of the drink (Max 20 characters):\n";
            cin.ignore();
            getline(cin, mealName);
            if (mealName.length() == 0)
            {
                throw runtime_error("Drink name cannot be empty!");
            }

            cout << "Please enter the price of the drink:\n";
            cin >> price;
            if (price < 0) {
                throw out_of_range("Price cannot be negative!");
            }

            cout << "what is the volume of alcohol in the drink? \n";
            cin >> volume;
            if (volume < 0)
            {
                throw out_of_range("Volume cannot be negative!");
            }

            cout << "Is this a special drink? y/n\n";
            char answer;
            cin >> answer;
            special = (answer == 'y');

            cout << "Which glass do you want? Enter number:\n0: Lowball\n1: Wine\n2: Beer\n3: Highball\n4: Paper cup\n";
            cin >> glassType;
            if (glassType < 0 || glassType > 4) {
                throw out_of_range("Invalid glass type selected!");
            }
            validInput = true; // If no exception was thrown, mark the input as valid
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
            cout << "Please try again.\n";
        }
    }
}

void HelpFunctions::gatherDrinkIngredients(list<Ingredient*> ingredientList, Restaurant* restaurant)
{
    string ingredientName;
    int quantity;
    char answer = 'n';
    do 
    {
        bool validInput = false;
        while (!validInput) 
        {
            try
            {
               
                list<Department*> temp = restaurant->getDepartments();
                Warehouse& ware = temp.front()->getWarehouse();
                Ingredient* ingredientToCopy = getValidIngredient(ware);
                // Ingredient* ingredientToCopy = ware.getIngredientByName(ingredientName);

                if (ingredientToCopy == nullptr) 
                    return;    // incase the ingedient not found in the warehouse

                cout << "What is the quantity of the ingredient that is needed?\n";
                cin >> quantity;
                if (quantity < 0) 
                    throw out_of_range("Quantity cannot be negative!");
                
                ingredientList.push_back(new Ingredient(ingredientName, ingredientToCopy->getSection(), quantity));
                validInput = true;
            }
            catch (const exception& e)
            {
                cout << "Error: " << e.what() << endl;
                cout << "Please try again.\n";
            }
        }
        cout << "Do you want to add another ingredient y/n?\n";
        cin >> answer;
    } while (answer == 'y');
}

void HelpFunctions::gatherFoodInfo(string& mealName, int& price, bool& special, bool& kosher)
{
    bool validInput = false;
    while (!validInput)
    {
        try {
            cout << "Please enter the name of the meal (Max 20 characters):\n";
            cin.ignore();
            getline(cin, mealName);
            if (mealName.length() == 0) 
            {
                throw runtime_error("Meal name cannot be empty!");
            }
            cout << "Please enter the price of the meal ($):\n";
            cin >> price;
            if (price < 0) 
            {
                throw out_of_range("Price cannot be negative!");
            }

            cout << "Is this a special meal? y/n\n";
            char answer;
            cin >> answer;
            special = (answer == 'y');

            cout << "Is this a kosher meal? y/n\n";
            cin >> answer;
            kosher = (answer == 'y');
            validInput = true;
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
            cout << "Please try again.\n";
        }
    }
}

void HelpFunctions::gatherFoodIngredients(list<Ingredient*> ingredientList, Restaurant* restaurant)
{
    string ingredientName;
    int quantity;
    char answer = 'n';
    do 
    {
        bool validInput = false;
        while (!validInput)
        {
            try 
            {

                list<Department*> temp = restaurant->getDepartments();
                Warehouse& ware = temp.back()->getWarehouse();
                Ingredient* ingredientToCopy = getValidIngredient(ware);
                if (ingredientToCopy == nullptr)
                {
                    return;  // in case the ingredient does not exists in ware house
                }

                cout << "What is the quantity of the ingredient that is needed?\n";
                cin >> quantity;
                if (quantity < 0)
                    throw out_of_range("Quantity cannot be negative!");


                ingredientList.push_back(new Ingredient(ingredientName, ingredientToCopy->getSection(), quantity));
                validInput = true;
            }
            catch (const exception& e) 
            {
                cout << "Error: " << e.what() << endl;
                cout << "Please try again.\n";
            }
        }
        cout << "Do you want to add another ingredient y/n?\n";
        cin >> answer;
    } while (answer == 'y');
}

void HelpFunctions::displayMenu() 
{
    cout << "Menu:\n";
    cout << "1. Add number to table in restaurant\n";
    cout << "2. Add new ingredient to warehouse\n";
    cout << "3. Add ingredient shipment to warehouse\n";
    cout << "4. Add drink to menu\n";
    cout << "5. Add meal food to menu\n";
    cout << "6. Open new order\n";
    cout << "7. Add menu items to order\n";
    cout << "8. Order checkout\n";
    cout << "9. Present Restaurant income report\n";
    cout << "10. Show kitchen warehouse\n";
    cout << "11. Show bar warehouse\n";
    cout << "12. Show menu\n";
    cout << "13. Show tables\n";
    cout << "14. Show resturant\n";
    cout << "15. Exit\n";
}