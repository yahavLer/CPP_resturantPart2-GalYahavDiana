#include <iostream>
#include "restaurant.h"
#include <limits>

using namespace std;

const int MAX_NAME_LENGTH = 20;
const int MAX_ADDRESS_LENGTH = 20;

int userIntValidation() {
    int temp;
    while (!(cin >> temp)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter an integer: ";
    }
    return temp;
}

void displayMenu() {
    cout << "Menu:\n";
    cout << "1. Add number to table in restaurant\n";
    cout << "2. Add new ingredient to warehouse\n";
    cout << "3. Add ingredient shipment to warehouse\n";
    cout << "4. Add meals to menu\n";
    cout << "5. Open new order\n";
    cout << "6. Add menu items to order\n";
    cout << "7. Order checkout\n";
    cout << "8. Present Restaurant income report\n";
    cout << "9. Show kitchen warehouse\n";
    cout << "10. Show bar warehouse\n";
    cout << "11. Show menu\n";
    cout << "12. Show tables\n";
    cout << "13. Exit\n";
}

int main() {
    int choice;
    bool exit = false;
    Restaurant* restaurant = nullptr;

    
    // open new resturant insert name and address
    char name[MAX_NAME_LENGTH + 1];
    char address[MAX_ADDRESS_LENGTH + 1];

    cout << "Enter the name of the restaurant (20 characters max): ";
    cin.getline(name, MAX_NAME_LENGTH + 1);

    cout << "Enter the address of the restaurant (20 characters max): ";
    cin.getline(address, MAX_ADDRESS_LENGTH + 1);
    if (restaurant != nullptr)
        delete restaurant;  // in case the pointer of the returunt
    restaurant = new Restaurant(name, address);

    cout << "\nRestaurant Name: " << restaurant->getName() << "\n";
    cout << "Restaurant Address: " << restaurant->getAddress() << "\n\n";

    while (!exit) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
        {
            int numOfTables;
            cout << "Enter the desired number of tables you want to add to the restaurant\n";
            numOfTables = userIntValidation();
            restaurant->addTables(numOfTables);
            break;
        }
        case 2:
        {
            char newIngredientName[MAX_NAME_LENGTH + 1];
            int section, forKitchen;
            cout << "Enter the name of the ingredient (20 characters max): ";
            cin.ignore();
            cin.getline(newIngredientName, MAX_NAME_LENGTH + 1);
            cout << "Enter the number of the section the ingredient is part of:\n0 - Herbs\n1 - Dairy\n2 - Meat\n3 - Fish\n4 - Vegetables\n";
            section = userIntValidation();
            cout << "Choose to which warehouse the ingredient belongs to:\n0 - Bar Warehouse\n1 - Kitchen Warehouse\n";
            forKitchen = userIntValidation();
            restaurant->addIngredientToWarehouse(newIngredientName, section, forKitchen);
            break;

        }
        case 3:
        {
            char ingredientName[MAX_NAME_LENGTH + 1];
            int quantity, forKitchen;

            cout << "Enter the name of the ingredient (20 characters max): ";
            cin.ignore();
            cin.getline(ingredientName, MAX_NAME_LENGTH + 1);

            cout << "Enter the quantity of the ingredient: ";
            quantity = userIntValidation();

            cout << "\nIngredient Name: " << ingredientName << "\n";
            cout << "Quantity: " << quantity << "\n\n";

            cout << "Choose to which warehouse the ingredient belongs to:\n0 - Bar Warehouse\n1 - Kitchen Warehouse\n";
            cin >> forKitchen;
            while (forKitchen != 0 && forKitchen != 1) {
                cout << "Invalid input. Please enter 0 for Bar Warehouse or 1 for Kitchen Warehouse: ";
                cin >> forKitchen;
            }
            if (!restaurant->updateIngredientQuantity(ingredientName, quantity, forKitchen))
                cout << "No ingredient found with following name in the warehouse: " << ingredientName << "\n";

            break;
        }
        case 4:
        {
            if (restaurant->isEmptyOfTable())
            {
                break;
            }

            char mealName[MAX_NAME_LENGTH + 1];
            char ingredientName[MAX_NAME_LENGTH + 1];
            int price, numOfIngredients = 0, department, quantity;
            bool special, kosher;
            Ingredient** ingredientList = new Ingredient * [MAX_NAME_LENGTH];;
            cout << "Please enter the type of the meal (0 - drinks item, 1 - food item):\n";
            cin >> department;
            cin.ignore();
            cout << "Please enter the name of the meal (Max 20 characters):\n";
            cin.getline(mealName, MAX_NAME_LENGTH + 1);
            cout << "Please enter the price of the meal:\n";
            cin >> price;
            cin.ignore();

            cout << "Please eanter the ingridiants of the meal:\n";
            char answer = 'n';
            do
            {
                cout << "What is the name of the ingridient?\n";
                cin.getline(ingredientName, MAX_NAME_LENGTH + 1);
                cout << "What is the quantety of the ingridient that is needed?\n";
                cin >> quantity;

                Department** temp = restaurant->getDepartments();
                Warehouse& ware = temp[department]->getWarwhouse();
                Ingredient* ingrediantToCopy = ware.getIngredientByName(ingredientName);
                ingredientList[numOfIngredients] = new Ingredient(ingredientName, ingrediantToCopy->getSection(), quantity);
                numOfIngredients++;

                cout << "Do you wnat to add another ingredient y/n?\n";
                cin >> answer;
                cin.ignore();

            }while (answer == 'y');

            // Ger input from user about the kosher/special meal
            cout << "Is this a special meal? y/n\n";
            cin >> answer;
            if (answer == 'y')
                special = true;
            else
                special = false;
            cout << "Is this a kosher meal? y/n\n";
            cin >> answer;
            if (answer == 'y')
                kosher = true;
            else
                kosher = false;

            // passing the data to the resturant
            restaurant->addItemToMenu(mealName, numOfIngredients, ingredientList, price, department, special, kosher);
            break;
        }
        case 5:
        {
            int tableNum, menuItemNum, quantity, addMore = 1;
            restaurant->presentTables();
            cout << "Please enter the table's number you want to open a new order in:\n";
            tableNum = userIntValidation();

            if (!restaurant->createNewOrderInTable(tableNum))
                cout << "Couldn't find a table with the table number provided or there is already an order opened in table\n";
            else
            {
                while (addMore)
                {
                    cout << "Please enter the menu item's number you want to add to order:\n";
                    restaurant->presentMenu();
                    cin >> menuItemNum;
                    cout << "How many do you want to add to the order?\n";
                    cin >> quantity;
                    restaurant->AddItemToOrder(menuItemNum, quantity);
                    cout << "Do you want to add more to order? press 1 for yes and 0 for no\n";
                    cin >> addMore;
                }
            }
            break;
        }
        case 6:
        {
            int tableNum, quantity, addMore = 1;
           char menuItemName[MAX_NAME_LENGTH + 1];

           cout << "Please enter the table's number you want to add items to order:\n";
           restaurant->presentTables();
           tableNum = userIntValidation();

           while (addMore)
           {
               cout << "Please enter the menu item's name you want to add to order:\n";
               restaurant->presentMenu();
               cin.ignore();
               cin.getline(menuItemName, MAX_NAME_LENGTH + 1);
               cout << "How many do you want to add to the order?\n";
               cin >> quantity;
               cout << "Do you want to add more to order? press 1 for yes and 0 for no\n";
               cin >> addMore;
           }
           break;
        }
        case 7:
        {
            int tableNum;
           cout << "Please enter the table's number you want to close order's bill:\n";
           restaurant->presentTables();
           tableNum = userIntValidation();

           if (!restaurant->closeBill(tableNum))
               cout << "No table or order found\n";
           break;
        }
        case 8:
        {
            restaurant->presentDailyIncome();
            break;
        }
        case 9:
        {
            restaurant->showKitchenWarehouse();
            break;
        }
        case 10:
        {
            restaurant->showBarWarehouse();
            break;
        }
        case 11:
        {
            restaurant->showMenuWarehouse();
            break;
        }
        case 12:
        {
            restaurant->showTablesWarehouse();
            break;
        }
        case 13:
        {
            // add delete to allocated items
            exit = true;
            break;
        }
        default:
        {
            cout << "Invalid choice, please try again.\n";
            break;
        }
        }
    }

    cout << "Exiting program.\n";
    return 0;
}
