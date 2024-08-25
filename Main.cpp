#include <iostream>
#include "restaurant.h"
#include <limits>
#define FOOD_DEPARTMENT 1
#define DRINK_DEPARTMENT 0
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
void init(Restaurant* restaurant) {
    // Initialize the restaurant with sample data
    if (restaurant != nullptr)
        delete restaurant;

    // Sample restaurant name and address
    const char* sampleName = "Sample Restaurant";
    const char* sampleAddress = "123 Sample St.";
    restaurant = new Restaurant(sampleName, sampleAddress);

    // Case 1: Add number of tables
    int numOfTables = 10; // Example: adding 10 tables
    restaurant->addTables(numOfTables);

    // Case 2: Add new ingredients to the warehouse
    restaurant->addIngredientToWarehouse("Tomato", 4, 1); // Vegetables, Kitchen Warehouse
    restaurant->addIngredientToWarehouse("Milk", 1, 1); // Dairy, Kitchen Warehouse
    restaurant->addIngredientToWarehouse("Vodka", 0, 0); // Herbs, Bar Warehouse
    restaurant->addIngredientToWarehouse("Potato", 4, 1); // Vegetables, Kitchen Warehouse
    restaurant->addIngredientToWarehouse("Melon", 4, 1); // Vegetables, Kitchen Warehouse

    // Case 3: Add ingredient shipment to warehouse
    restaurant->updateIngredientQuantity("Tomato", 50, 1); // Add 50 tomatoes to Kitchen Warehouse
    restaurant->updateIngredientQuantity("Milk", 20, 1); // Add 20 milk to Kitchen Warehouse
    restaurant->updateIngredientQuantity("Vodka", 15, 0); // Add 15 vodka to Bar Warehouse
    restaurant->updateIngredientQuantity("Potato", 100, 1); // Add 100 potatoes to Kitchen Warehouse
    restaurant->updateIngredientQuantity("Melon", 30, 1); // Add 30 melons to Kitchen Warehouse

    // Case 4: Add drink to menu
    Ingredient* drinkIngredients[] = {
        new Ingredient("Vodka", 0, 1),
        new Ingredient("Tomato", 4, 2)
    };
    restaurant->addDrinkItemToMenu("Bloody Mary", 10, DrinkItem::eGlassType::Lowball, 20, drinkIngredients, 2, true);

    // Case 5: Add meal food to menu
    Ingredient* mealIngredients[] = {
        new Ingredient("Tomato", 4, 2),
        new Ingredient("Milk", 1, 1),
        new Ingredient("Potato", 4, 3) // Adding Potato as an ingredient
    };
    restaurant->addFoodItemToMenu("Tomato Soup", 3, mealIngredients, 30, FOOD_DEPARTMENT, false, true);

    cout << "Sample data initialized successfully.\n";
}

void displayMenu() {
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
    cout << "12. Show tables\n";
    cout << "14. Exit\n";
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
    init(restaurant);
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
            if (restaurant->addTables(numOfTables))
                cout << "table added successfully\n";
            else
                cout << "table added cencel - the resturant is full\n";
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
            char mealName[MAX_NAME_LENGTH + 1];
            char ingredientName[MAX_NAME_LENGTH + 1];
            int price, numOfIngredients = 0, quantity;
            int volume, glassType;
            bool special;
            //DrinkItem::eGlassType glass;
            Ingredient** ingredientList = new Ingredient * [MAX_NAME_LENGTH];;
            cout << "Please enter the name of the drink (Max 20 characters):\n";
            cin.ignore();
            cin.getline(mealName, MAX_NAME_LENGTH + 1);
            cout << "Please enter the price of the drink:\n";
            cin >> price;
            cin.ignore();

            cout << "Please enter the ingridiants of the drink:\n";
            char answer = 'n';
            do
            {
                cout << "What is the name of the ingridient?\n";
                cin.getline(ingredientName, MAX_NAME_LENGTH + 1);
                cout << "What is the quantety of the ingredient that is needed?\n";
                cin >> quantity;
                cin.ignore();
                Department** temp = restaurant->getDepartments();
                Warehouse& ware = temp[DRINK_DEPARTMENT]->getWarwhouse();
                Ingredient* ingrediantToCopy = ware.getIngredientByName(ingredientName);
                ingredientList[numOfIngredients] = new Ingredient(ingredientName, ingrediantToCopy->getSection(), quantity);
                numOfIngredients++;

                cout << "Do you want to add another ingredient y/n?\n";
                cin >> answer;
                cin.ignore();

            } while (answer == 'y');

            cout << "what is the volume of alcholl in the drink? \n";
            cin >> volume;
            cout << "Is this a special drink? y/n\n";
            cin >> answer;
            if (answer == 'y')
                special = true;
            else
            {
                special = false;
            }
            cout << "which glass do you want? enter number of one of the next options:\n 0: Lowball\n 1: Wine\n 2: Beer\n 3: Highball\n 4: Paper cup\n";
            cin >> glassType;
            restaurant->addDrinkItemToMenu(mealName, volume, static_cast<DrinkItem::eGlassType>(glassType), price, ingredientList, numOfIngredients, special);
            break;
        }
        case 5:
        {
            char mealName[MAX_NAME_LENGTH + 1];
            char ingredientName[MAX_NAME_LENGTH + 1];
            int price, numOfIngredients = 0, quantity;
            bool special, kosher;
            Ingredient** ingredientList = new Ingredient * [MAX_NAME_LENGTH];
            cout << "Please enter the name of the meal (Max 20 characters):\n";
            cin.ignore();
            cin.getline(mealName, MAX_NAME_LENGTH + 1);
            cout << "Please enter the price of the meal:\n";
            cin >> price;
            cin.ignore();

            cout << "Please enter the ingridiants of the meal:\n";
            char answer = 'n';
            do
            {
                cout << "What is the name of the ingridient?\n";
                cin.getline(ingredientName, MAX_NAME_LENGTH + 1);
                cout << "What is the quantety of the ingridient that is needed?\n";
                cin >> quantity;

                Department** temp = restaurant->getDepartments();
                Warehouse& ware = temp[FOOD_DEPARTMENT]->getWarwhouse();
                Ingredient* ingrediantToCopy = ware.getIngredientByName(ingredientName);
                ingredientList[numOfIngredients] = new Ingredient(ingredientName, ingrediantToCopy->getSection(), quantity);
                numOfIngredients++;

                cout << "Do you want to add another ingredient y/n?\n";
                cin >> answer;
                cin.ignore();

            } while (answer == 'y');

            // passing the data to the resturant
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
            restaurant->addFoodItemToMenu(mealName, numOfIngredients, ingredientList, price, FOOD_DEPARTMENT, special, kosher);
            break;
        }
        case 6:
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
        case 7:
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
        case 8:
        {
            int tableNum;
            cout << "Please enter the table's number you want to close order's bill:\n";
            restaurant->presentTables();
            tableNum = userIntValidation();

            if (!restaurant->closeBill(tableNum))
                cout << "No table or order found\n";
            break;
        }
        case 9:
        {
            restaurant->presentDailyIncome();
            break;
        }
        case 10:
        {
            restaurant->showKitchenWarehouse();
            break;
        }
        case 11:
        {
            restaurant->showBarWarehouse();
            break;
        }
        case 12:
        {
            restaurant->showMenuWarehouse();
            break;
        }
        case 13:
        {
            restaurant->showTablesWarehouse();
            break;
        }
        case 14:
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
