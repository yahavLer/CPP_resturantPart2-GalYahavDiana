#include <iostream>
#include "restaurant.h"
#include <limits>
const int MAX_NAME_LENGTH = 20;
const int MAX_ADDRESS_LENGTH = 20;

int userIntValidation() {
	int temp;
	while (!(std::cin >> temp)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input. Please enter an integer: ";
	}
	return temp;
}
void displayMenu() {
	std::cout << "Menu:\n";
	std::cout << "1. Open new restaurant\n";
	std::cout << "2. Add ingredient shipment to warehouse\n";
	std::cout << "3. Open new order\n";
	std::cout << "4. Add menu items to order\n";
	std::cout << "5. Order checkout\n";
	std::cout << "6. Add new ingredient to warehouse\n";
	std::cout << "7. Add tables to restaurant\n";
	std::cout << "8. Present Restaurant income report\n";
	std::cout << "9. Show kitchen warehouse\n";
	std::cout << "10. Show bar warehouse\n";
	std::cout << "11. Show menu\n";
	std::cout << "12. Show tables\n";
	std::cout << "13. Exit\n";
}

int main() {
	int choice;
	bool exit = false;
	Restaurant restaurant;

	while (!exit) {
		displayMenu();
		std::cout << "Enter your choice: ";
		std::cin >> choice;

		switch (choice) {
		case 1:
		{
			char name[MAX_NAME_LENGTH + 1];
			char address[MAX_ADDRESS_LENGTH + 1];


			std::cout << "Enter the name of the restaurant (20 characters max): ";
			std::cin.ignore();
			std::cin.getline(name, MAX_NAME_LENGTH + 1);


			std::cout << "Enter the address of the restaurant (20 characters max): ";
			std::cin.ignore();
			std::cin.getline(address, MAX_ADDRESS_LENGTH + 1);


			std::cout << "Restaurant Name: " << name << "\n";
			std::cout << "Restaurant Address: " << address << "\n";

			restaurant.setName(name);
			restaurant.setAdress(address);

			break;
		}
		case 2:
		{
			char ingredientName[MAX_NAME_LENGTH + 1];
			int quantity, forKitchen;


			std::cout << "Enter the name of the ingredient (20 characters max): ";
			std::cin.ignore();
			std::cin.getline(ingredientName, MAX_NAME_LENGTH + 1);

			std::cout << "Enter the quantity of the ingredient: ";
			quantity = userIntValidation();

			std::cout << "Ingredient Name: " << ingredientName << "\n";
			std::cout << "Quantity: " << quantity << "\n";

			std::cout << "Choose to which warehouse the ingredient belongs to:\n0 - Bar Warehouse\n1 - Kitchen Warehouse\n";
			std::cin >> forKitchen;
			if (!restaurant.updateIngredientQuantity(ingredientName, quantity, forKitchen))
				std::cout << "No ingredient found with following name in the warehouse: " << ingredientName << "\n";

			break;
		}
		case 3:
		{
			int tableNum, menuItemNum, quantity, addMore=1;
			restaurant.presentTables();
			std::cout << "Please enter the table's number you want to open a new order in:\n";
			tableNum = userIntValidation();

			if (!restaurant.createNewOrderInTable(tableNum))
				std::cout << "Couldnt find a table with the table number provided or there is already an order opened in table\n";
			else
			{
				while (addMore)
				{
					std::cout << "Please enter the menu item's number you want to add to order:\n";
					restaurant.presentMenu();
					std::cin >> menuItemNum;
					std::cout << "How many do you want to add to the order?\n";
					std::cin >> quantity;
					restaurant.AddItemToOrder(menuItemNum, quantity);
					std::cout << "Do you want to add more to order? pressw 1 for yes and 0 for no\n";
					std::cin >> addMore;
				}
			}
			break;
		}
		case 4:
		{
			int tableNum, quantity, addMore = 1;;
			char menuItemName[MAX_NAME_LENGTH + 1];

			std::cout << "Please enter the table's number you want to add items to order:\n";
			restaurant.presentTables();
			tableNum = userIntValidation();
		
			while (addMore)
			{
				std::cout << "Please enter the menu item's name you want to add to order:\n";
				restaurant.presentMenu();
				std::cin.getline(menuItemName, MAX_NAME_LENGTH + 1);
				std::cout << "How many do you want to add to the order?\n";
				std::cin >> quantity;
				std::cout << "Do you want to add more to order>? pressw 1 for yes and 0 for no\n";
				std::cin >> addMore;
			}
			break;
		}
		case 5:
		{
			int tableNum;
			std::cout << "Please enter the table's number you want to close order's bill:\n";
			restaurant.presentTables();
			tableNum =userIntValidation();
			
			if (!restaurant.closeBill(tableNum))
				std::cout << "No table or order found\n";
			break;
		}
		case 6:
		{
			char newIngredientName[MAX_NAME_LENGTH + 1];
			int section, forKitchen;
			std::cout << "Enter the name of the ingredient (20 characters max): ";
			std::cin.ignore();
			std::cin.getline(newIngredientName, MAX_NAME_LENGTH + 1);
			std::cout << "Enter the number of the section the ingredient is part of:\n0 - Herbs\n1 - Dairy\n2 - Meat\n3 - Fish\n4 - Vegetables\n";
			section= userIntValidation();
			std::cout << "Choose to which warehouse the ingredient belongs to:\n0 - Bar Warehouse\n1 - Kitchen Warehouse\n";
			forKitchen = userIntValidation();
			restaurant.addIngredientToWarehouse(newIngredientName, section, forKitchen);
			break;
		}
		case 7:
		{
			int numOfTables;
			std::cout << "Enter the desired number of tables you want to add to the restaurant\n";
			numOfTables = userIntValidation();
			restaurant.addTables(numOfTables);
			break;
		}
		case 8:
		{
			restaurant.presentDailyIncome();
			break;
		}
		case 9:
		{
			restaurant.showKitchenWarehouse();
			break;
		}
		case 10:
		{
			restaurant.showBarWarehouse();
			break;
		}
		case 11:
		{
			restaurant.showMenuWarehouse();
			break;
		}
		case 12:
		{
			restaurant.showTablesWarehouse();
			break;
		}
		case 13:
		{
			exit = true;
			break;
		}
		default:
		{
			std::cout << "Invalid choice, please try again.\n";
			break;
		}
		}
	}

	std::cout << "Exiting program.\n";
	return 0;
}