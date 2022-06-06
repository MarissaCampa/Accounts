/**
 * @file Account_Manager.cpp
 * @author Marissa Campa (marissag.campa@gmail.com)
 * @brief Implementation file for the Account_Manager class
 * @date 2022-06-06
 * @copyright Copyright (c) 2022
 * 
 */

#include "Account_Manager.h"

/**
 * @brief Shows the main menu with the options for the Accounts Manager
 * @return void
 */
void Account_Manager::showMenu() {
    int length = 40;
    std::cout 
        << std::left
        << "\n " << char(218) << std::string(length, char(196)) << char(191) << '\n'
        << ' ' << char(179) << std::setw(length) << "     Welcome to Trusted Bank"     << char(179) << '\n'
        << ' ' << char(195) << std::string(length, char(196)) << char(180) << '\n'
        << ' ' << char(179) << std::setw(length) << " How can I help you?"              << char(179) << '\n'
        << ' ' << char(179) << std::setw(length) << " "                                 << char(179) << '\n'
        << ' ' << char(179) << std::setw(length) << "  (a) Open a new account"          << char(179) << '\n'
        << ' ' << char(179) << std::setw(length) << "  (b) Display all accounts"        << char(179) << '\n'
        << ' ' << char(179) << std::setw(length) << "  (c) Deposit to an account"       << char(179) << '\n'
        << ' ' << char(179) << std::setw(length) << "  (d) Withdraw from an account"    << char(179) << '\n'
        << ' ' << char(179) << std::setw(length) << "  (x) Exit"                        << char(179) << '\n'
        << ' ' << char(179) << std::setw(length) << " "                                 << char(179) << '\n'
        << ' ' << char(192) << std::string(length, char(196)) << char(217) << '\n';
    std::cout << '\n';
    display_msg(Msg::USER, "Select an option: ", false); 
}

/**
 * @brief Shows the type of accounts available to open and prompts 
 *          the user to select an option. 
 * @return true only if the input was a valid option and if the
 *         prompt to open a new account was successful.
 */
bool Account_Manager::openNewAccount() {
    // Show the type of accounts available to open
    std::cout << '\n' 
        << ' ' << char(218) << std::string(50, char(196)) << char(191) << '\n' << std::left
        << ' ' << char(179) << std::setw(50) << " What type of account would you like to open:" << char(179) << '\n'
        << ' ' << char(179) << std::setw(50) << " " << char(179) << '\n'
        << ' ' << char(179) << std::setw(50) << "  1) Regular Account"      << char(179) << '\n'
        << ' ' << char(179) << std::setw(50) << "  2) Checking Account"     << char(179) << '\n'
        << ' ' << char(179) << std::setw(50) << "  3) Savings Account"      << char(179) << '\n'
        << ' ' << char(179) << std::setw(50) << "  4) Trust Account"        << char(179) << '\n'
        << ' ' << char(179) << std::setw(50) << "  0) Go back"                << char(179) << '\n'
        << ' ' << char(179) << std::setw(50) << " " << char(179) << '\n'
        << ' ' << char(192) << std::string(50, char(196)) << char(217) << "\n\n";
    display_msg(Msg::USER, "Select an option: ", false); 

    // Prompt the user to select an option for the account type
    int option {0};
    std::cin >> option;
    std::cin.ignore();
    if (!std::cin.fail() || option == 0) {
        if (option == 1) {
            // Regular account
            return promptToOpenNewAccount(AccountTypes::REGULAR);
        }
        else if (option == 2) {
            // Checking Account
            return promptToOpenNewAccount(AccountTypes::CHECKING);
        }
        else if (option == 3) {
            // Savings Account
            return promptToOpenNewAccount(AccountTypes::SAVINGS);
        }
        else if (option == 4) {
            // Trust Account        
            return promptToOpenNewAccount(AccountTypes::TRUST);
        } 
        else if (option == 0) {
            // Return to main menu without doing anything
            return true;
        }
    }
    display_msg(Msg::ERROR, "Invalid"); 
    // Invalid option selected, go back to main menu returning false
    return false;
}

/**
 * @brief Prompts the user to enter a name and initial amount for the new account.
 * 
 * It validates the inputs, creates a unique base class Account pointer, pointing
 * to the type of account to be created, and add the pointer to the accounts vector.
 *  
 * @param accountType Type of account to open
 * @return true if the new account was added to the 
 *                accounts vector successfully
 */
bool Account_Manager::promptToOpenNewAccount(AccountTypes accountType) {
    // Display message "Adding a new 'accountType'"
    displayAddingNewAccountMessage(accountType);

    // User input for name
    display_msg(Msg::USER, "Enter a name for the account: ", false);
    std::string name;
    std::getline(std::cin, name);

    // Input validation - The name must not be a digit
    if (Account_Manager::isDigit(name)) {
        display_msg(Msg::ERROR, "Name must not be a digit");
        return false;
    }

    // Input validation - The name needs to be at least 5 characters long
    if (name.size() < 5) {
        display_msg(Msg::ERROR, "Name must at least 5 characters long");
        return false;
    }

    // User input for initial amount
    display_msg(Msg::USER, "Enter initial amount: ", false);
    double amount;
    std::cin >> amount;
    std::cin.ignore();

    // Input validation - The amount needs to be numeric and greater than 0
    if (!std::cin.fail() && amount > 0) {

        // Create a unique base class Account pointer, pointing to the type of Account 
        std::unique_ptr<Account> p;
        if (accountType == AccountTypes::CHECKING) 
            p = std::make_unique<Checking_Account>(name, amount);
        else if (accountType == AccountTypes::SAVINGS)
            p = std::make_unique<Savings_Account>(name, amount);            
        else if (accountType == AccountTypes::TRUST)
            p = std::make_unique<Trust_Account>(name, amount);            
        else
            p = std::make_unique<Account>(name, amount);
        
        // Add unique base class pointer to accounts vector
        accounts.push_back(std::move(p));
        display_msg(Msg::INFO, "Created successfully");
        return true;
    }
    display_msg(Msg::ERROR, "Invalid");
    return false;
}

/**
 * @brief Shows the message "Adding a new 'accountType'", where
 *      accountType is the type of account to open
 * 
 * @param accountType Type of account to open
 */
void Account_Manager::displayAddingNewAccountMessage(AccountTypes accountType) {
    if (accountType == AccountTypes::CHECKING) 
        display_msg(Msg::INFO, "Adding a new checking account");
    else if (accountType == AccountTypes::SAVINGS)
        display_msg(Msg::INFO, "Adding a new savings account");
    else if (accountType == AccountTypes::TRUST)
        display_msg(Msg::INFO, "Adding a new trust account");
    else
        display_msg(Msg::INFO, "Adding a new account");
    std::cout << '\n';
}

/**
 * @brief Deposits an amount entered by the user to an account 
 *        in the accounts vector.
 * It calls the necessary prompts to get the vector index and the 
 * amount, then calls the polymorphic function deposit()
 * for the corresponding unique base class Account pointer in the 
 * accounts vector.
 * 
 * @return true of the deposit was successful
 */
bool Account_Manager::depositToAccount() {
    // Get the vector index from the user
    int index = promptToGetAccountIndex();

    // Validate that the index is in range
    if (index >= 0 && index < accounts.size()) {

        // Show the account details at the selected index
        std::cout.precision(2);
        std::cout << " [INFO] Depositing to account name " << accounts[index]->getName()
            << " with a balance of " << std::fixed << accounts[index]->getBalance() << '\n';

        // Get the amount from the user
        double amount = promptToGetAmountForAccountAction(Action::DEPOSIT);

        // Call the polymorphic function deposit for the selected base class account pointer
        bool succeded = accounts[index]->deposit(amount);
        if (succeded)
            display_msg(Msg::INFO, "Deposit successful");
        else
            display_msg(Msg::ERROR, "Not deposited");
        return succeded;
    }
    return false;
}

/**
 * @brief Displays a message to the user to enter an amount
 * for an action do perform on an account.
 * 
 * The message depends on the type of action to perform on an
 * account. Then it calls the getAmountFromUser() method to return the
 * user-entered amount.
 * 
 * @param action Type of accion to perform in an account (deposit or withdraw)
 * @return The amount entered by the user
 */
double Account_Manager::promptToGetAmountForAccountAction(Action action) {
    std::string message = "Enter amount to ";
    if (action == Action::DEPOSIT)
        message += "deposit: ";
    else if (action == Action::WITHDRAW)
        message += "withdraw: ";
    display_msg(Msg::USER, message, false);
    return getAmountFromUser();
}

/**
 * @brief Withdraws an amount entered by the user from an account 
 *        in the accounts vector.
 * It calls the necessary prompts to get the vector index and the 
 * amount, then calls the polymorphic function withdraw()
 * for the corresponding unique base class Account pointer in the 
 * accounts vector.
 * 
 * @return true of the withdraw was successful
 */
bool Account_Manager::withdrawFromAccount() {
    // Get the vector index from the user
    int index = promptToGetAccountIndex();

    // Validate that the index is in range
    if (index >= 0 && index < accounts.size()) {

        // Show the account details at the selected index
        std::cout.precision(2);
        std::cout << " [INFO] Withdrawing from account name " << accounts[index]->getName()
            << " with a balance of " << std::fixed << accounts[index]->getBalance() << '\n';

        // Get the amount from the user
        double amount = promptToGetAmountForAccountAction(Action::WITHDRAW);

        // Call the polymorphic function withdraw for the selected base class account pointer
        bool succeded = accounts[index]->withdraw(amount);
        if (succeded)
            display_msg(Msg::INFO, "Withdraw successful");
        else
            display_msg(Msg::INFO, "Not withdrawn");
        return succeded;
    }
    return false;
}


/**
 * @brief Prompts the user to enter a 1-based index 
 *        within the accounts vector range
 * 
 * It displays a message to enter a 1-based index withint he vector's 
 * range, then calls the function getIndexFromUser() and stores
 * the converted 0-based index, then it validates that the index is
 * within the range of the accounts vector. 
 * 
 * @return The 0-based index of the accounts vector only
 *          if is within range, otherwise return -1. Also return -1 
 *          if the accounts vector is empty
 */
int Account_Manager::promptToGetAccountIndex() {
    if (accounts.empty()) return -1;
    if (accounts.size() == 1)
        display_msg(Msg::USER, "Enter 1 to confirm only account: ", false);
    else 
        display_msg(Msg::USER, "Enter an index between 1 and " + std::to_string(accounts.size()) + ": ", false);
    
    int index = getIndexFromUser();
    if (index >= 0 && index < accounts.size())
        return index;
    else 
        return -1;
}

/**
 * @brief Prints a table with all the accounts
 * 
 * It calls the necessary functions to print the
 * accounts table title, each member, and the table bottom.
 * The fields printed are Index, Account Name, Balance and 
 * Account Type
 * 
 * @return void
 */
void Account_Manager::displayAllAccounts() {
    // Check if accounts vector is not empty
    if (!accounts.empty()) {
        display_msg(Msg::INFO, "Showing all accounts: ");
        // Print the accounts table title including 
        // the fields Index, Account Name, Balance and Account Type
        printAccountsTableTitle();

        // Iterate through the accounts vector and 
        // print each member
        for (int i = 0; i < accounts.size(); i++) {
            printAccountsTableMembers(i);    
            
            if (i < accounts.size() - 1) {
                // After it prints the member, 
                // print a row separation line
                printAccountsTableDivider(false); 
            }
            else {
                // If it printed the last member, 
                // print the table bottom
                printAccountsTableDivider(true);        
            }
        }
    } else {
        display_msg(Msg::INFO, "List is empty");
    }
}

/**
 * @brief Prints the accounts table title
 * 
 * The fields printed are Index, Account Name, 
 * Balance and Account Type.
 * It uses characters from the extended ASCII code list
 * 
 * @return void
 */
void Account_Manager::printAccountsTableTitle() {
    std::cout 
        << '\n' << char(218) 
        << std::string(10, char(196))  << char(194)
        << std::string(24, char(196)) << char(194)
        << std::string(14, char(196)) << char(194)
        << std::string(14, char(196)) << char(191) << '\n'
        << char(179) << std::setw(10) << " Index"
        << char(179) << std::setw(24) << " Account Name"
        << char(179) << std::setw(14) << " Balance"
        << char(179) << std::setw(14) << " Account Type" << char(179) << '\n'
        << char(195) 
        << std::string(10, char(196)) << char(197)
        << std::string(24, char(196)) << char(197)
        << std::string(14, char(196)) << char(197)
        << std::string(14, char(196)) << char(180) << '\n';
}

/**
 * @brief Prints the accounts table members
 * 
 * It prints the account details from the accounts vector
 * at the selected index. 
 * The fields printed are Index, Account Name, 
 * Balance and Account Type.
 * It uses characters from the extended ASCII code list
 * 
 * @return void
 */
void Account_Manager::printAccountsTableMembers(int index) {
    // Get the type of account from accounts vector at the
    // selected index. getType() is a polymorphic function
    // that each account inherited and implemented from the base
    // class Account
    AccountTypes type = accounts[index]->getType();
    
    // Convert the type of account to string 
    std::string type_str;
    if (type == AccountTypes::REGULAR)
        type_str = "Regular";
    else if (type == AccountTypes::CHECKING)
        type_str = "Checking";
    else if (type == AccountTypes::SAVINGS)
        type_str = "Savings";
    else if (type == AccountTypes::TRUST)
        type_str = "Trust";

    // Print the account details from the accounts vector at the selected index,
    // using the polymorphic functions getName() and getBalance()
    std::cout << std::left
        << char(179) << " " << std::setw(8) << index + 1 << " " 
        << char(179) << " " << std::setw(22) << accounts[index]->getName() << " " 
        << char(179) << " " << std::setw(12) << accounts[index]->getBalance() << " "
        << char(179) << " " << std::setw(12) << type_str << " " 
        << char(179) << '\n';    
}

/**
 * @brief Prints the accounts table middle divider or bottom
 * 
 * It the input parameter is false, it prints a separation line between 
 * the table rows. If the input parameter is true, it prints the
 * table bottom.
 * 
 * @return void
 */
void Account_Manager::printAccountsTableDivider(bool bottom) {
    if (!bottom) {
        // Print a separation line between two rows
        std::cout << char(195) 
            << std::string(10, char(196)) << char(197)
            << std::string(24, char(196)) << char(197)
            << std::string(14, char(196)) << char(197)
            << std::string(14, char(196)) << char(180) << '\n';        
    } else {
        // Print the bottom of the table
        std::cout << char(192) 
            << std::string(10, char(196)) << char(193)
            << std::string(24, char(196)) << char(193)
            << std::string(14, char(196)) << char(193)
            << std::string(14, char(196)) << char(217) << '\n';                
    }    
}


/**
 * @brief Returns true of the string input parameter is a digit
 */
bool Account_Manager::isDigit(const std::string &str) {
    if (str.empty())
        return false;
    // Iterate the characters in the string paramter str
    for (const char &c : str) {
        // Return false if a character is not a digit
        if (isdigit(c) == 0) 
            return false;
    }
    return true;
}

/**
 * @brief Prompts the user for an amount
 * 
 * It clear the istream buffer and prompts for an amount.
 * If the amount is not numeric, or if its empty, display
 * and "Invalid" message and return -1
 * 
 * @return An amount from the user 
 */
double Account_Manager::getAmountFromUser() {
    double amount;
    std::cin.clear();
    std::cin.sync();
    std::cin >> amount;
    std::cin.ignore();
    if (std::cin.fail() || amount == 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        display_msg(Msg::ERROR, "Invalid");
        return -1;
    }
    return amount;
}

/**
 * Prompts the user for a numeric input and returns
 * the number only if is a digit and is not empty, 
 * if not it returns -1.
 *
 * @return The number entered by the user
 */
int Account_Manager::getIndexFromUser() {
    int index;
    std::cin.clear();
    std::cin.sync();
    std::cin >> index;
    std::cin.ignore();
    if (std::cin.fail() || index == 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        display_msg(Msg::ERROR, "Invalid");
        return -1;
    }
    // Convert to 0-based index and return
    return index - 1;
}
