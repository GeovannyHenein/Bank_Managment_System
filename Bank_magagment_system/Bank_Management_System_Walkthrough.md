# Bank Management System Project

## Introduction

The Bank Management System project is designed to provide a user-friendly interface for managing bank accounts and transactions. It allows users to perform various actions such as depositing money, borrowing from the bank, returning borrowed money, and checking their account balance.

## Project Elements

### Header File (Header.h)

The `Header.h` file serves as the central header for the project.

#### Included Libraries:

- `<iostream>`: Standard input-output operations.
- `<fstream>`: File handling operations.
- `<stdlib.h>`: Standard library for general utilities.
- `<string>`: String manipulation functions.
- `<vector>`: Container for dynamic arrays.
- `<windows.h>`: Windows-specific functions for console manipulation.
- `<ctime>`: Functions for date and time operations.
- `<conio.h>`: Functions for console input/output.

#### Global Variables:

- `accountNum`: Stores the current user's account number.
- `increaments`: Tracks the number of accounts.
- `balance`: Stores the current balance of the user's account.
- `available`: Stores the available balance in the bank.
- `borrow`: Stores the amount borrowed by the user.

#### Preprocessor Directives:

- `#pragma once`: Ensures the header file is included only once.

### Main Function (`main.cpp`)

- The main function initializes the random seed and available balance.
- Calls the `MainMenu` function to start the user interaction.

### MainMenu Function

- Displays a menu for users to sign in, register, or exit the system.
- Handles user input and redirects to appropriate actions.
- Utilizes file handling functions to read and write account data.

### Menu Function

- Provides options for account actions such as depositing, borrowing, and returning money.
- Updates account data based on user actions.

### Other Functions

- `CheckBalance`: Displays the current balance of the user's account.
- `Borrow`: Allows users to borrow money from the bank.
- `Deposit`: Allows users to deposit money into their account.
- `Return`: Allows users to return borrowed money to the bank.

### Account Struct

- Defines the structure of an account with attributes such as name, password, balance, and borrowed amount.
- Accounts are stored as structs and manipulated throughout the project.

### File Handling

- `outData`: Reads account data from a file into an array of account structs.
- `inputNewData`: Writes new account data to the file.
- `inputUpgradeData`: Updates account data in the file with new changes.

## Project Structure

- The project directory contains source code files (`main.cpp`, `Header.h`) and any additional files for input/output.
- Source code files are organized based on functionality and interdependencies.

## Conclusion

The Bank Management System project provides an intuitive interface for managing bank accounts and transactions. By leveraging file handling and user-friendly menus, it offers a seamless experience for users to perform various banking operations efficiently.
