#include "Header.h" // Include the header file

int main()
{
	// Seed the random number generator with current time
	srand(time(0));
	// Generate a random available balance between 0 and 200,000
	::available = rand() % 200000;
	// Call the MainMenu function
	MainMenu();

	system("color 9E"); // Set console color
	system("pause"); // Pause the system
	return 0; // Return 0 to indicate successful completion
}

// Function to display the main menu
void MainMenu()
{
	system("color 9E"); // Set console color
	char num;
	char choice;
	do
	{
		bool checked = false;
		string checkName, checkPassword;
		accounts data;
		accounts oldData[50]; // Create an array to store old account data
		// Display menu options
		cout << "\n          Choose what you want:";
		cout << "\n          1.Sign in";
		cout << "\n          2.Registration";
		cout << "\n          3.Exit";
		cout << "\n          ";
		choice = _getch(); // Get user choice
		switch (choice)
		{
		case 49: // If user chooses to sign in
			outData(oldData); // Read old account data from file
			system("CLS");
			cout << "\n          Please enter your name:";
			cout << "\n          ";
			cin >> checkName; // Get user name
			cout << "\n          Please enter your password:";
			cout << "\n          ";
			cin >> checkPassword; // Get user password
			// Check if user credentials are valid
			for (int i = 0; i < ::increaments; i++)
			{
				if (oldData[i].name == checkName && oldData[i].password == checkPassword)
				{
					::accountNum = i;
					::balance = oldData[i].balance;
					::borrow = oldData[i].borrowed;
					checked = true;
				}
			}
			if (checked)
			{
				do
				{
					system("CLS");
					cout << "\n          Hello " << oldData[::accountNum].name << endl;
					cout << "\n          What would you like to do?" << endl;
					cout << "\n          1.Actions with card" << endl;
					cout << "\n          2.Check balance" << endl;
					cout << "\n          0.Exit" << endl;
					num = _getch(); // Get user choice
					switch (num)
					{
					case 48:
						break;
					case 49:
						Menu(oldData); // Call function to perform actions with card
						break;
					case 50:
						CheckBalance(); // Call function to check balance
						break;
					default:
						cout << "\n          Error! Section not found. Please try one more time." << endl << endl;
						system("pause"); // Pause the system
						break;
					}
				} while (num != '0');
			}
			else
				cout << "\n          Wrong name or password\n"; // Display error message if credentials are invalid
			break;
		case 50: // If user chooses registration
			system("CLS");
			cout << "\n          Input your name without space";
			cout << "\n          ";
			cin >> data.name; // Get user name
			cout << "\n          Input your password without space";
			cout << "\n          ";
			cin >> data.password; // Get user password
			data.balance = 0; // Set initial balance to 0
			data.borrowed = 0; // Set initial borrowed amount to 0
			inputNewData(data); // Write new account data to file
			break;
		case 51: // If user chooses exit
			break;
		default: // If user enters invalid choice
			cout << "\n          There is no such section";
			cout << "\n          Please try one more time";
			break;
		}
	} while (choice != 51); // Repeat until user chooses exit

	cout << "\n          ";
}
