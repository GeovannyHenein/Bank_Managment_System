#pragma once
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string>
#include <vector>
#include <windows.h>
#include <ctime>
#include <conio.h>

using namespace std;

// Global variables
int accountNum, increaments; // Variables for account number and increments
long double balance = 0; // Variable for balance
long double available; // Variable for available balance
long double borrow = 0; // Variable for borrowed amount

// Structure to represent account data
struct accounts {
	string name; // Account holder's name
	string password; // Account password
	double balance; // Account balance
	double borrowed; // Amount borrowed from the bank
};

// Function declarations
void CheckBalance();
void Borrow();
void Deposit();
void Return();
void Menu(accounts oldData[]);
void MainMenu();
void outData(accounts oldData[]);
void inputNewData(accounts data);
void inputUpgradeData(accounts data[]);

// Function definitions
void Menu(accounts oldData[]) {
	// Menu function to display options to the user
	char num = '1';
	while (num != '0') // Loop until user enters '0' to exit
	{
		system("CLS"); // Clear the console screen
		cout << "\n          1.Deposit" << endl; // Option to deposit money
		cout << "\n          2.Borrow money from bank" << endl; // Option to borrow money
		cout << "\n          3.Return money to bank" << endl << endl; // Option to return borrowed money
		cout << "\n          If you want to quit from this section please press 0" << endl << endl; // Option to quit
		num = _getch(); // Get user input
		switch (num) {
		case 49: // If user enters '1', deposit money
			system("CLS");
			Deposit(); // Call Deposit function
			oldData[accountNum].balance = ::balance; // Update balance in the account data
			inputUpgradeData(oldData); // Update account data in the file
			break;
		case 50: // If user enters '2', borrow money
			system("CLS");
			Borrow(); // Call Borrow function
			oldData[accountNum].balance = ::balance; // Update balance in the account data
			oldData[accountNum].borrowed = ::borrow; // Update borrowed amount in the account data
			inputUpgradeData(oldData); // Update account data in the file
			break;
		case 51: // If user enters '3', return borrowed money
			system("CLS");
			Return(); // Call Return function
			oldData[accountNum].balance = ::balance; // Update balance in the account data
			oldData[accountNum].borrowed = ::borrow; // Update borrowed amount in the account data
			inputUpgradeData(oldData); // Update account data in the file
			break;
		}
	}
	cout << "\n          ";
}

// Function to display account balance
void CheckBalance() {
	system("CLS"); // Clear the console screen
	cout << "\n          You balance: " << ::balance << "$" << endl << endl; // Display balance
	cout << "\n          ";
	system("pause"); // Pause the system
}

// Function to deposit money into the account
void Deposit()
{
	double money;
	cout << "\n          Please enter amount of money - ";
	cin >> money; // Get input from user
	if (money == 0) // If user enters 0, redirect to menu
	{
		cout << "\n          You entered 0 value so now you are redirected to the menu" << endl;
		Sleep(2000);
	}
	else if (money > 0) // If user enters positive amount, deposit money
	{
		::balance = ::balance + money; // Update balance
		cout << "\n          Please wait for a while, while we are transfering money to your account" << endl; // Display message
		Sleep(2000); // Wait for 2 seconds
		cout << "\n          ";
		cout << money << "$ amount of money was added to your balance" << endl << endl; // Display deposited amount
	}
	else // If user enters invalid amount
	{
		cout << "\n          Error!" << endl;
		cout << "\n          Please enter valid amount of money!" << endl << endl;
	}
	cout << "\n          ";
	system("pause"); // Pause the system
}

// Function to borrow money from the bank
void Borrow()
{
	long double borrow;
	cout << "\n          In during time in our bank we have " << ::available << "$" << endl; // Display available balance in the bank
	cout << "\n          How much do you want to borrow?" << endl; // Ask user for amount to borrow
	cout << "\n          ";
	cin >> borrow; // Get input from user
	if (borrow == 0) // If user enters 0, redirect to menu
	{
		cout << "\n          You entered 0 value so now you are redirected to the menu" << endl << endl;
		Sleep(2000);
	}
	else if (borrow <= ::available && borrow > 0) // If user enters valid amount within available balance
	{
		cout << "\n          We can give you such amount of money." << endl; // Display confirmation
		cout << "\n          Please wait for a while, while we are transfering money to your account" << endl; // Display message
		Sleep(3000); // Wait for 3 seconds
		::available = ::available - borrow; // Update available balance in the bank
		::balance = ::balance + borrow; // Update balance in the account
		::borrow = ::borrow + borrow; // Update borrowed amount
		cout << "\n          Money is successfully transfered to your account." << endl << endl; // Display success message
	}
	else // If user enters invalid amount
	{
		cout << "\n          We are sorry but we cant give you such amount of money" << endl << endl; // Display error message
	}
	cout << "\n          ";
	system("pause"); // Pause the system
}

// Function to return borrowed money to the bank
void Return()
{
	char choise;
	long double retr;
	if (::borrow > 0) { // If user has borrowed money
		cout << "\n          You have borrowed - " << ::borrow << "$" << endl; // Display borrowed amount
		cout << "\n          If you want to return some amount of money please press SPACE or press anything to go back to menu." << endl; // Prompt user to return money
		choise = _getch(); // Get input from user
		if (choise == 32) { // If user presses SPACE to return money
			cout << "\n          How much do you want to return?" << endl; // Ask user for amount to return
			cout << "\n          ";
			cin >> retr; // Get input from user
			if (retr == 0) // If user enters 0, redirect to menu
			{
				cout << "\n          You entered 0 value so now you are redirected to the menu" << endl;
				Sleep(2000);
			}
			else if (retr > 0 && retr <= ::borrow) { // If user enters valid amount within borrowed amount
				cout << "\n          Please wait while we are taking from your account money back." << endl; // Display message
				::borrow = ::borrow - retr; // Update borrowed amount
				::balance = ::balance - retr; // Update balance in the account
				::available = ::available + retr; // Update available balance in the bank
				Sleep(3000); // Wait for 3 seconds
				cout << "\n          Money is successfully taken from your account." << endl << endl; // Display success message
			}
			else // If user enters invalid amount
			{
				cout << "\n          Error!" << endl;
				cout << "\n          Please enter valid amount of money!" << endl << endl;
			}
		}
	}
	else { // If user hasn't borrowed any money
		cout << "\n          You haven't borrowed any money from us." << endl << endl; // Display message
	}
	cout << "\n          ";
	system("pause"); // Pause the system
}

// Function to read account data from file
void outData(accounts oldData[]) {
	ifstream file;
	file.open("data.txt"); // Open file
	if (!file.is_open()) { // If file cannot be opened
		cout << "Error\n"; // Display error message
	}
	else {
		string str = "";
		int i = 0, j = 0;
		string strArr[4];
		do {
			getline(file, str, '|'); // Read data from file
			if (j < 4) {
				strArr[j] = str;
				j++;
			}
			else {
				oldData[i].name = strArr[0]; // Assign name
				oldData[i].password = strArr[1]; // Assign password
				oldData[i].balance = stoi(strArr[2]); // Assign balance
				oldData[i].borrowed = stoi(strArr[3]); // Assign borrowed amount
				::increaments++; // Increment counter
				j = 0;
				strArr[j] = str;
				j++;
				i++;
			}
		} while (!file.eof()); // Repeat until end of file
	}
}

// Function to write new account data to file
void inputNewData(accounts data) {
	ofstream file;
	file.open("data.txt", ofstream::app); // Open file in append mode
	file << data.name;
	file << "|";
	file << data.password;
	file << "|";
	file << data.balance;
	file << "|";
	file << data.borrowed;
	file << "|";
	file.close(); // Close file
}

// Function to update account data in file
void inputUpgradeData(accounts data[]) {
	ofstream file;
	file.open("data.txt"); // Open file
	for (int i = 0; i <::increaments; i++) { // Iterate through account data
		file << data[i].name;
		file << "|";
		file << data[i].password;
		file << "|";
		file << data[i].balance;
		file << "|";
		file << data[i].borrowed;
		file << "|";
	}
	file.close(); // Close file
}
