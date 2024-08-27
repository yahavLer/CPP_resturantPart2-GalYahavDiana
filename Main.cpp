#include <iostream>
#include <stdexcept> // for standard exceptions
#include "restaurant.h"
#include <limits>
using namespace std;
const int FOOD_DEPARTMENT = 1;
const int DRINK_DEPARTMENT = 0;
const int MAX_NAME_LENGTH = 20;
const int MAX_ADDRESS_LENGTH = 20;

int userIntValidation() {
    int temp;
    while (!(cin >> temp)) {
        cin.clear();
        cin.ignore();
        cout << "Invalid input. Please enter an integer: ";
    }
    return temp;
}

void initRestaurant(Restaurant* restaurant) {
    // הוספת שולחנות
    restaurant->addTables(5);
    restaurant->addTables(3);

    // הוספת מרכיבים למחסן case 2
    restaurant->addIngredientToWarehouse("Tomato", 4, 1); // Kitchen Warehouse
    restaurant->addIngredientToWarehouse("Lemon", 4, 0);  // Bar Warehouse
    restaurant->addIngredientToWarehouse("Chicken", 2, 1); // Kitchen Warehouse
    restaurant->addIngredientToWarehouse("Mint", 0, 0);  // Bar Warehouse

    // הוספת פריטים לתפריט case 3
	restaurant->updateIngredientQuantity("Tomato", 10, 1);
	restaurant->updateIngredientQuantity("Lemon", 20, 0);
	restaurant->updateIngredientQuantity("Chicken", 30, 1);
	restaurant->updateIngredientQuantity("Mint", 40, 0);

	// הוספת מנות לתפריט case 4
    Department** temp = restaurant->getDepartments();
    Warehouse& ware = temp[DRINK_DEPARTMENT]->getWarwhouse();
	Ingredient** ingredientList = new Ingredient * [MAX_NAME_LENGTH];
    ingredientList[0] = new Ingredient("Lemon", Ingredient::eSection::DAIRY, 2);
	restaurant->addDrinkItemToMenu("Lemonade", 100, DrinkItem::eGlassType::HIGHBOAL, 15, ingredientList, 1, false);
    restaurant->addDrinkItemToMenu("Miranda", 50, DrinkItem::eGlassType::LOWBOAL, 25, ingredientList, 1, true);

    Ingredient** ingredientList2 = new Ingredient * [MAX_NAME_LENGTH];
	ingredientList2[0] = new Ingredient("Tomato", Ingredient::eSection::VEGETABLES, 2);
	ingredientList2[1] = new Ingredient("Chicken", Ingredient::eSection::MEAT, 2);
	restaurant->addFoodItemToMenu("Chicken Salad", 2, ingredientList2, 30, FOOD_DEPARTMENT, false, true);
	restaurant->addFoodItemToMenu("Tomato Salad", 1, ingredientList2, 20, FOOD_DEPARTMENT, true, false);
}

void gatherDrinkInfo(std::string& mealName, int& price, int& volume, int& glassType, bool& special) {
    bool validInput = false;
    while (!validInput) {
        try {
            cout << "Please enter the name of the drink (Max 20 characters):\n";
            cin.ignore();
            cin.getline(mealName, MAX_NAME_LENGTH + 1);
            if (mealName.length() == 0) {
                throw runtime_error("Drink name cannot be empty!");
            }
            cout << "Please enter the price of the drink:\n";
            cin >> price;
            if (price < 0) {
                throw out_of_range("Price cannot be negative!");
            }
            cout << "what is the volume of alcohol in the drink? \n";
            cin >> volume;
            if (volume < 0) {
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

void gatherDrinkIngredients(Ingredient** ingredientList, int& numOfIngredients, Restaurant* restaurant) {
	char ingredientName[MAX_NAME_LENGTH + 1];
	int quantity;
	char answer = 'n';
	do {
        bool validInput = false;
        while (!validInput) {
            try {
		        cout << "What is the name of the ingredient?\n";
		        cin.ignore();
		        cin.getline(ingredientName, MAX_NAME_LENGTH + 1);
                if (strlen(ingredientName) == 0) {
                    throw runtime_error("Ingredient name cannot be empty!");
                }
		        cout << "What is the quantity of the ingredient that is needed?\n";
		        cin >> quantity;
                if (quantity < 0) {
                    throw out_of_range("Quantity cannot be negative!");
                }
		        Department** temp = restaurant->getDepartments();
		        Warehouse& ware = temp[DRINK_DEPARTMENT]->getWarwhouse();
		        Ingredient* ingredientToCopy = ware.getIngredientByName(ingredientName);
		        ingredientList[numOfIngredients] = new Ingredient(ingredientName, ingredientToCopy->getSection(), quantity);
		        numOfIngredients++;
                validInput = true;
            } catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
                cout << "Please try again.\n";
            }
        }
		cout << "Do you want to add another ingredient y/n?\n";
		cin >> answer;
	} while (answer == 'y');
}

void gatherFoodInfo(std::string& mealName, int& price, bool& special, bool& kosher) {
    bool validInput = false;
    while (!validInput) {
        try {
            cout << "Please enter the name of the meal (Max 20 characters):\n";
	        cin.ignore();
	        cin.getline(mealName, MAX_NAME_LENGTH + 1);
            if (strlen(mealName) == 0) {
                throw runtime_error("Meal name cannot be empty!");
            }
	        cout << "Please enter the price of the meal:\n";
	        cin >> price;
            if (price < 0) {
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

void gatherFoodIngredients(Ingredient** ingredientList, int& numOfIngredients, Restaurant* restaurant) {
    char ingredientName[MAX_NAME_LENGTH + 1];
    int quantity;
    char answer = 'n';
    do {
        bool validInput = false;
        while (!validInput) {
            try {
                cout << "What is the name of the ingredient?\n";
                cin.ignore();
                cin.getline(ingredientName, MAX_NAME_LENGTH + 1);
                if (strlen(ingredientName) == 0) {
                    throw runtime_error("Ingredient name cannot be empty!");
                }
                cout << "What is the quantity of the ingredient that is needed?\n";
                cin >> quantity;
                if (quantity < 0) {
                    throw out_of_range("Quantity cannot be negative!");
                }
                Department** temp = restaurant->getDepartments();
                Warehouse& ware = temp[FOOD_DEPARTMENT]->getWarwhouse();
                Ingredient* ingredientToCopy = ware.getIngredientByName(ingredientName);
                ingredientList[numOfIngredients] = new Ingredient(ingredientName, ingredientToCopy->getSection(), quantity);
                numOfIngredients++;
                validInput = true;
            }
            catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
                cout << "Please try again.\n";
            }
        }
        cout << "Do you want to add another ingredient y/n?\n";
        cin >> answer;
    } while (answer == 'y');
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
    cout << "13. Show tables\n";
    cout << "14. Show resturant\n";
    cout << "15. Exit\n";
}

int main() {
    try {
        int choice;
        bool exit = false;
        //Restaurant* restaurant = new Restaurant("Sample Restaurant", "123 Sample St.");
        Restaurant* restaurant = nullptr;

        // open new resturant insert name and address
        char name[MAX_NAME_LENGTH + 1];
        char address[MAX_ADDRESS_LENGTH + 1];

        cout << "Enter the name of the restaurant (20 characters max): ";
        cin.getline(name, MAX_NAME_LENGTH + 1);
        if (strlen(name) == 0) {
            throw runtime_error("Restaurant name cannot be empty!");
        }
        cout << "Enter the address of the restaurant (20 characters max): ";
        cin.getline(address, MAX_ADDRESS_LENGTH + 1);
        if (strlen(address) == 0) {
            throw runtime_error("Restaurant address cannot be empty!");
        }
        if (restaurant != nullptr)
            delete restaurant;  // in case the pointer of the returunt
        restaurant = new Restaurant(name, address);
        initRestaurant(restaurant);
        restaurant->print();

        cout << "\nRestaurant Name: " << restaurant->getName() << "\n";
        cout << "Restaurant Address: " << restaurant->getAddress() << "\n\n";

        while (!exit) {
            displayMenu();
            cout << "Enter your choice: ";
            cin >> choice;
            try {
                switch (choice) {
		            case 1: // Add number to table in restaurant
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
		            case 2: // Add new ingredient to warehouse
                    {
                        char newIngredientName[MAX_NAME_LENGTH + 1];
                        int section, forKitchen;
                        cout << "Enter the name of the ingredient (20 characters max): ";
                        cin.ignore();
                        cin.getline(newIngredientName, MAX_NAME_LENGTH + 1);
                        if (strlen(newIngredientName) == 0) {
                            throw runtime_error("Ingredient name cannot be empty!");
                        }
                        cout << "Enter the number of the section the ingredient is part of:\n0 - Herbs\n1 - Dairy\n2 - Meat\n3 - Fish\n4 - Vegetables\n";
                        section = userIntValidation();
                        if (section < 0 || section > 4) {
                            throw out_of_range("Invalid section number!");
                        }
                        cout << "Choose to which warehouse the ingredient belongs to:\n0 - Bar Warehouse\n1 - Kitchen Warehouse\n";
                        forKitchen = userIntValidation();
                        if (forKitchen != 0 && forKitchen != 1) {
                            throw out_of_range("Invalid warehouse selection!");
                        }
                        restaurant->addIngredientToWarehouse(newIngredientName, section, forKitchen);
                        break;

                    }
		            case 3: // Add ingredient shipment to warehouse
                    {
                        char ingredientName[MAX_NAME_LENGTH + 1];
                        int quantity, forKitchen;

                        cout << "Enter the name of the ingredient (20 characters max): ";
                        cin.ignore();
                        cin.getline(ingredientName, MAX_NAME_LENGTH + 1);
                        if (strlen(ingredientName) == 0) {
                            throw runtime_error("Ingredient name cannot be empty!");
                        }

                        cout << "Enter the quantity of the ingredient: ";
                        quantity = userIntValidation();
                        if (quantity < 0) {
                            throw out_of_range("Quantity cannot be negative!");
                        }
                        cout << "\nIngredient Name: " << ingredientName << "\n";
                        cout << "Quantity: " << quantity << "\n\n";

                        cout << "Choose to which warehouse the ingredient belongs to:\n0 - Bar Warehouse\n1 - Kitchen Warehouse\n";
                        cin >> forKitchen;
                        if (forKitchen != 0 && forKitchen != 1) {
                            throw out_of_range("Invalid warehouse selection!");
                        }
                        /*
                        while (forKitchen != 0 && forKitchen != 1) {
                            cout << "Invalid input. Please enter 0 for Bar Warehouse or 1 for Kitchen Warehouse: ";
                            cin >> forKitchen;
                        }
                        */
                        if (!restaurant->updateIngredientQuantity(ingredientName, quantity, forKitchen))
                            cout << "No ingredient found with following name in the warehouse: " << ingredientName << "\n";

                        break;
                    }
		            case 4: // Add drink to menu
                    {
                        char mealName[MAX_NAME_LENGTH + 1];
                        int price, volume, glassType, numOfIngredients = 0;
                        bool special;
                        Ingredient** ingredientList = new Ingredient * [MAX_NAME_LENGTH];

                        gatherDrinkInfo(mealName, price, volume, glassType, special);
                        gatherDrinkIngredients(ingredientList, numOfIngredients, restaurant);

                        restaurant->addDrinkItemToMenu(mealName, volume, static_cast<DrinkItem::eGlassType>(glassType), price, ingredientList, numOfIngredients, special);
                        break;
                    }
		            case 5: // Add meal food to menu
                    {
                        char mealName[MAX_NAME_LENGTH + 1];
                        int price, numOfIngredients = 0;
                        bool special, kosher;
                        Ingredient** ingredientList = new Ingredient * [MAX_NAME_LENGTH];

                        gatherFoodInfo(mealName, price, special, kosher);
                        gatherFoodIngredients(ingredientList, numOfIngredients, restaurant);

                        restaurant->addFoodItemToMenu(mealName, numOfIngredients, ingredientList, price, FOOD_DEPARTMENT, special, kosher);
                        break;
                    }
		            case 6: // Open new order
                    {
                        int tableNum, menuItemNum, quantity, addMore = 1, addComment=0;
			            std::string comments ;
                        bool validInput = false;
                        while (!validInput) {
                            try {
                                restaurant->presentTables();
                                cout << "Please enter the table's number you want to open a new order in:\n";
                                tableNum = userIntValidation();

                                if (!restaurant->createNewOrderInTable(tableNum))
                                    //cout << "Couldn't find a table with the table number provided or there is already an order opened in table\n";
                                    throw runtime_error("Couldn't find a table with the table number provided or there is already an order opened in table.");
                                validInput = true; // אם הקלט תקין, נסמן שהקלט תקין ונצא מהלולאה
                            }
                            catch (const exception& e) {
                                cout << "Error: " << e.what() << endl;
                                cout << "Please try again.\n";
                            }
                        }
                        while (addMore)
                        {
                            restaurant->presentMenu();
                            cout << "Please enter the menu item's number you want to add to order:\n";
                            cin >> menuItemNum;
                            cout << "How many do you want to add to the order?\n";
                            cin >> quantity;					
					        cout << "Do you want to add comments to the order? press 1 for yes and 0 for no (max 20) \n";
                            cin >> comments;
                            /*
                            if (addComment == 1)
                            {
                                comments = new char[51];
                                comments[0] = '\0';
                                cout << "Enter your comments (max 50 characters):\n";
                                cin.ignore();
                                cin.getline(comments, 51);
                            }
                            */
                            
					        //get the menu item by the number and add it to the order
					        restaurant->createNewOrderInTable(tableNum);
					        restaurant->addItemToOrder(menuItemNum, quantity, tableNum, comments);
                            cout << "Do you want to add more to order? press 1 for yes and 0 for no\n";
                            cin >> addMore;
                        }
                        break;
                    }                    
		            case 7: // Add menu items to order
                    {
                        int tableNum, quantity, menuItemNum, addMore = 1, addComment = 0;;
                        std::string comments = nullptr;
                        bool validInput = false;
                        while (!validInput) {
                            try {
                                restaurant->presentTables();
                                cout << "Please enter the table's number you want to add items to order:\n";
                                tableNum = userIntValidation();
                                validInput = true; // אם הקלט תקין, נסמן שהקלט תקין ונצא מהלולאה
                            }
                            catch (const exception& e) {
                                cout << "Error: " << e.what() << endl;
                                cout << "Please try again.\n";
                            }
                        }               
                        while (addMore)
                        {
                            restaurant->presentMenu();
                            cout << "Please enter the menu item's number you want to add to order:\n";
                            cin >> menuItemNum;
                            cout << "How many do you want to add to the order?\n";
                            cin >> quantity;
                            cout << "Do you want to add comments to the order? press 1 for yes and 0 for no (max 20) \n";
                            cin >> comments;
                            /*
                            if (addComment == 1)
                            {
                                comments = new char[51];
                                comments[0] = '\0';
                                cout << "Enter your comments (max 50 characters):\n";
                                cin.ignore();
                                cin.getline(comments, 51);
                            }
                            */
                            
                            //get the menu item by the number and add it to the order
                            restaurant->addItemToOrder(menuItemNum, quantity, tableNum, comments);
                            cout << "Do you want to add more to order? press 1 for yes and 0 for no\n";
                            cin >> addMore;
                        }
                        break;
                    }
		            case 8: // Order checkout
                    {
                        int tableNum;
                        bool validInput = false;
                        while (!validInput) {
                            try {
                                restaurant->presentTables();
                                cout << "Please enter the table's number you want to close order's bill:\n";
                                tableNum = userIntValidation();

                                if (!restaurant->closeBill(tableNum))
                                    throw runtime_error("No table or order found");
                                    //cout << "No table or order found\n";
                                validInput = true; // אם הקלט תקין, נסמן שהקלט תקין ונצא מהלולאה
                            }
                            catch (const exception& e) {
                                cout << "Error: " << e.what() << endl;
                                cout << "Please try again.\n";
                            }
                        }                        
                        break;
                    }
		            case 9: // Present Restaurant income report
                    {
                        restaurant->presentDailyIncome();
                        break;
                    }
		            case 10: // Show kitchen warehouse
                    {
                        restaurant->showKitchenWarehouse();
                        break;
                    }
		            case 11: // Show bar warehouse
                    {
                        restaurant->showBarWarehouse();
                        break;
                    }
		            case 12: // Show menu
                    {
                        restaurant->showMenuWarehouse();
                        break;
                    }
		            case 13: // Show tables
                    {
                        restaurant->showTablesWarehouse();
                        break;
                    }
                    case 14: //show resturant
                        restaurant->print();
                        break;
		            case 15: // Exit
                    {
                        exit = true;
                        break;
                    }
                    default: 
                    {
                        throw out_of_range("Invalid menu choice, please try again.");
                        //cout << "Invalid choice, please try again.\n";
                        //break;
                    }
                }
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (const runtime_error& e) {
                cout << "Error: " << e.what() << endl;
            }
        }
        cout << "Exiting program.\n";
        return 0;

    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
}
