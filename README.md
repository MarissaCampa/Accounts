# Program to Manage Bank Accounts #


## 🗒️ Summary
"Welcome to Trusted Bank! How can I help you?"
This project is a C++ application to manage bank accounts. The program shows the main menu with options to open a new account, display all accounts, deposit and withdraw from an account. There are four types of accounts that can be opened: Regular, Checking, Savings and Trust Account.

This project was developed in C++, and I used CMake to compile the executable.

 06.06.2022_14.50.47_REC.mp4 

## ⭐ Project Features
The application shows the Program Menu:

(a) Open a new account

Prompts the user to choose a type of acount, and then to enter the name and initial balance of the account.
(b) Display all accounts

Prints a table with all the accounts that have been created.
(c) Deposit to an account

Prompts the user to enter an index to select an account, and then to enter an amount to deposit to the account. It shows [Invalid] if the input is not numeric or if it's out of the list range.
(d) Withdraw from an account

Prompts the user to enter an index to select an account, and then to enter an amount to withdraw from the account. It shows [Invalid] if the input is not numeric or if it's out of the list range.
x) Exit. 
    -Ends the program.


## 📝 Details

Main
The main program shows the Main Menu, manages the user selection and validates the input. It makes sure that the input is a character and that is a valid option. If is not a valid option, it shows a message [Invalid], and shows the Main Menu again.

The main program instanciates an object of the Account_Manager class to call methods to open a new account, display all accounts, deposit or withdraw from an account.

Account_Manager Class
The Account_Manager class has a vector of unique pointers to the base class Account, and each pointer gets initialized to the specific account created. The accounts vector of pointers to the base class Account is used to facilitate polymorphic calls to specific account methods from the Account Manager.

It has the following public methods:

showMenu()
depositToAccount()
withdrawFromAccount()
displayAllAccounts()
There are four types of accounts that can be opened:

Regular Account
Checking Account
Savings Account
Trust Account
Account Class
The Account class is the base class where the rest of the accounts inherit from. It has protected class members that can be inherited: m_Name and m_Balance. It has helper members for the default arguments of the constructor, and a private member called m_Type, specific to each class.

The Account class can be instanciated as a regular account. And there are two accounts that inherit from this class, the Checking and the Savings accounts. There is also, a Trust account that inherits from the Savings Account.

It has the following methods:

A two-arg constructor, a copy constructor and a virtual default constructor.
Getter methods declared as virtual for inheritance.
getName(), getBalance() and getType()
Public methods declared as virtual for inheritance.
deposit() and withdraw()
Checking_Account Class
The Checking_Account class inherits from the Account class. It inherits the class member variables m_Name and m_Balance. It has helper members for the default arguments of the constructor, and a private member called m_Type, specific to each class.

It has the following methods:

A two-arg constructor, a copy constructor and a virtual default constructor.
It inherits from class the methods getName(), getBalance()
It overrides the methods getType(), and withdraw()
The Checking_Account class adds functionality to the withdraw() method inherited from Account class. It has a withdraw fee every time there is a withdraw from this type of account.

Savings_Account Class
The Savings_Account class inherits from the Account class. It inherits the class member variables m_Name and m_Balance. It has helper members for the default arguments of the constructor, and a private member called m_Type, specific to each class.

It has the following methods:

A three-arg constructor, a copy constructor and a virtual default constructor.
It inherits from class the methods getName(), getBalance()
It overrides the methods getType(), and deposit()
The Savings_Account class adds functionality to the deposit() method inherited from Account class. This account has an interest rate that gets added to the amount to be deposited each time.

Trust_Account Class
The Trust_Account class inherits from the Savings_Account class. It inherits the class member variables m_Name, m_Balance and m_InterestRate. It has helper members for the default arguments of the constructor, and a private member called m_Type, specific to each class, and m_TotalMovements, specific to the Trust Account.

It has the following methods:

A three-arg constructor, a copy constructor and a virtual default constructor.
It inherits from class the methods getName(), getBalance()
It overrides the methods getType(), deposit() and withdraw()
The Savings_Account class adds functionality to the deposit() and withdraw() methods inherited from Savings_Account class. Since, this account is also a Savings Account, it has an interest rate that gets added to the amount to be deposited each time. And the added functionality to the deposit() and withdraw() methods is that every time these methods are called, it increases the variable m_TotalMovements, and it has a limit of maximum movementes allowed per year (there is no implementation for time periods, only for demonstration).

The Trust Account also has a bonus amount that gets deposited if the amount to deposit is greater than the minimum amount to get the bonus.

## 🗂️ Files & Directories
Accounts - Main application dicrectory
main.cpp - Main applicaton file
Account_Manager.h - Account_Manager class header
Account_Manager.cpp - Account_Manager class implementation
Account.h - Account class header
Account.cpp - Account class implementation
Checking_Account.h - Checking_Account class header
Checking_Account.cpp - Checking_Account class implementation
Savings_Account.h - Savings_Account class header
Savings_Account.cpp - Savings_Account class implementation
Trust_Account.h - Trust_Account class header
Trust_Account.cpp - Trust_Account class implementation
Account_Util.h - Helper file that contains variables and functions useful to the Account_Manager and Account classes, and the main function
💽 Installation
Please refer to the following section for instructions on how to configure and run this project on     image

  Configure and compile a CMake project


## 👋 About Me
My name is Marissa Campa, I'm a Mechatronics Engineer with a Master of Science in Automation.

You can reach me on   Linkedin Badge   or   