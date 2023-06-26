//include header files
#include <iostream>
#include <string>

using namespace std;

//Declaring constants
const int MAX_FOOD_ITEMS = 50;
const int MAX_USERS = 100;

//Declaring structs
struct FoodInfo
{
	string foodName;
	double foodPrice;
	int foodCalories;
	int foodInventory;
};

struct UserInfo
{
	string username;
	string password;
	string fullName;
	string address;
	int userID;
	int balance;
};

//Global variables
FoodInfo Food[MAX_FOOD_ITEMS];
UserInfo User[MAX_USERS];
int nFoodItems = 0;
int nUsers = 0;

//Functions
void createFoodItem(){
	// code to create food
	string foodName;
	double foodPrice;
	int foodCalories;
	int foodInventory;
	
	if(nFoodItems > MAX_FOOD_ITEMS){
		cout << "Cannot create more food items" << endl;
		return;
	}

	cout << "Enter food name: ";
	cin >> foodName;
	cout << "Enter food price: ";
	cin >> foodPrice;
	cout << "Enter food calories: ";
	cin >> foodCalories;
	cout << "Enter food inventory: ";
	cin >> foodInventory;

	Food[nFoodItems].foodName = foodName;
	Food[nFoodItems].foodPrice = foodPrice;
	Food[nFoodItems].foodCalories = foodCalories;
	Food[nFoodItems].foodInventory = foodInventory;

	nFoodItems++;

}

void createUser(){
	// code to create user
	string username;
	string password;
	string fullName;
	string address;
	int userID;
	int balance;

	if(nUsers > MAX_USERS){
		cout << "Cannot create more users" << endl;
		return;
	}

	cout << "Enter username: ";
	cin >> username;
	cout << "Enter password: ";
	cin >> password;
	cout << "Enter full name: ";
	cin >> fullName;
	cout << "Enter address: ";
	cin >> address;
	cout << "Enter user id: ";
	cin >> userID;
	cout << "Enter balance: ";
	cin >> balance;

	User[nUsers].username = username;
	User[nUsers].password = password;
	User[nUsers].fullName = fullName;
	User[nUsers].address = address;
	User[nUsers].userID = userID;
	User[nUsers].balance = balance;

	nUsers++;

}

void viewFoodItems(){
	// code to show all food items
	for (int i = 0; i < nFoodItems; i++) {
		cout << "Food Name: " << Food[i].foodName << endl;
		cout << "Food Price: " << Food[i].foodPrice << endl;
		cout << "Food Calories: " << Food[i].foodCalories << endl;
		cout << "Food Inventory: " << Food[i].foodInventory << endl;
		cout << "-------" << endl;
	}
}

void viewUsers(){
	// code to show all users
	for (int i = 0; i < nUsers; i++) {
		cout << "Username: " << User[i].username << endl;
		cout << "Password: " << User[i].password << endl;
		cout << "Full Name: " << User[i].fullName << endl;
		cout << "Address: " << User[i].address << endl;
		cout << "User ID: " << User[i].userID << endl;
		cout << "Balance: " << User[i].balance << endl;
		cout << "-------" << endl;
	}
}

void searchFoodItem(){
	// code to search for food item
	string foodName;
	cout << "Enter food name to search: ";
	cin >> foodName;

	for (int i = 0; i < nFoodItems; i++){
		if (Food[i].foodName == foodName){
			cout << "Found food item" << endl;
			cout << "Food Name: " << Food[i].foodName << endl;
			cout << "Food Price: " << Food[i].foodPrice << endl;
			cout << "Food Calories: " << Food[i].foodCalories << endl;
			cout << "Food Inventory: " << Food[i].foodInventory << endl;
			return;
		}
	}

	cout << "Food item not found" << endl;

}

void searchUser(){
	// code to search for user
	string userName;
	cout << "Enter user name to search: ";
	cin >> userName;

	for (int i = 0; i < nUsers; i++){
		if (User[i].username == userName){
			cout << "Found user" << endl;
			cout << "Username: " << User[i].username << endl;
			cout << "Password: " << User[i].password << endl;
			cout << "Full Name: " << User[i].fullName << endl;
			cout << "Address: " << User[i].address << endl;
			cout << "User ID: " << User[i].userID << endl;
			cout << "Balance: " << User[i].balance << endl;
			return;
		}
	}

	cout << "User not found" << endl;
}

void purchaseFood(){
	// code to purchase food item
	string username;
	int userIndex;
	int foodIndex;

	cout << "Enter username to purchase food: ";
	cin >> username;

	for (int i = 0; i < nUsers; i++) {
		if (User[i].username == username) {
			userIndex = i;
			break;
		}
		if (i == nUsers) {
			cout << "User not found" << endl;
			return;
		}
	}

	string foodName;
	cout << "Enter food name to purchase: ";
	cin >> foodName;

	for (int i = 0; i < nFoodItems; i++) {
		if (Food[i].foodName == foodName) {
			foodIndex = i;
			break;
		}
		if (i == nFoodItems) {
			cout << "Food item not found" << endl;
			return;
		}
	}

	int quantity;
	cout << "Enter quantity to purchase: ";
	cin >> quantity;

	if (User[userIndex].balance < (quantity * Food[foodIndex].foodPrice)) {
		cout << "Not enough balance" << endl;
		return;
	}
	if (Food[foodIndex].foodInventory < quantity) {
		cout << "Not enough inventory" << endl;
		return;
	}

	User[userIndex].balance -= (quantity * Food[foodIndex].foodPrice);
	Food[foodIndex].foodInventory -= quantity;

	cout << "Purchase successful" << endl;
	cout << "Remaining Balance: " << User[userIndex].balance << endl;
	cout << "Remaining Inventory: " << Food[foodIndex].foodInventory << endl;

}


int main(){
	int choice;
	while(1) {
		cout << "1. Create Food Item" << endl;
		cout << "2. Create User" << endl;
		cout << "3. View Food Items" << endl;
		cout << "4. View Users" << endl;
		cout << "5. Search Food Item" << endl;
		cout << "6. Search User" << endl;
		cout << "7. Purchase Food" << endl;
		cout << "Enter choice: ";
		cin >> choice;
		switch(choice){
			case 1:
				createFoodItem();
				break;
			case 2:
				createUser();
				break;
			case 3:
				viewFoodItems();
				break;
			case 4:
				viewUsers();
				break;
			case 5:
				searchFoodItem();
				break;
			case 6:
				searchUser();
				break;
			case 7:
				purchaseFood();
				break;
			default:
				cout << "Invalid choice" << endl;
				break;
		}
	}

	return 0;
}