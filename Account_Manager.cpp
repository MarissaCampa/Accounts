#include "Account_Manager.h"

void Account_Manager::showMenu() {
    std::cout << "\nWelcome to TrustedBank\n";
    std::cout << "How can I help you?\n";
    std::cout << "  (a) Open a new account\n";
    std::cout << "  (b) Display all accounts\n";
    std::cout << "  (c) Deposit to all accounts\n";
    std::cout << "  (d) Withdraw to all accounts\n";
    std::cout << "  (x) Exit\n";
    std::cout << "Select an option: ";
}

bool Account_Manager::openNewAccount() {
    std::cout << "\nWhat type of account would you like to open:\n";
    std::cout << "  (a) Regular Account\n";
    std::cout << "  (b) Checking Account\n";
    std::cout << "  (c) Savings Account\n";
    std::cout << "  (d) Trust Account\n";
    std::cout << "Select an option: ";
    std::string sel;
    std::getline(std::cin, sel);

    if (sel == "a") {
        // Regular account
        std::string name;
        std::cout << "Enter name for the account: ";
        std::getline(std::cin, name);
        std::cout << "Enter initial amount: ";
        double amount;
        std::cin >> amount;
        std::cin.ignore();
        std::unique_ptr<Account> p = std::make_unique<Account>(name, amount);
        accounts.push_back(std::move(p));
        return true;
    }
    else if (sel == "b") {
        // Checking Account
        std::string name;
        std::cout << "Enter name for the account: ";
        std::getline(std::cin, name);
        std::cout << "Enter initial amount: ";
        double amount;
        std::cin >> amount;
        std::cin.ignore();
        std::unique_ptr<Account> p = std::make_unique<Checking_Account>(name, amount);
        accounts.push_back(std::move(p));
        return true;
    }
    else if (sel == "c") {
        std::string name;
        std::cout << "Enter name for the account: ";
        std::getline(std::cin, name);
        std::cout << "Enter initial amount: ";
        double amount;
        std::cin >> amount;
        std::cin.ignore();
        std::unique_ptr<Account> p = std::make_unique<Savings_Account>(name, amount);
        accounts.push_back(std::move(p));
        return true;        
    }
    else if (sel == "d") {
        // Trust Account        
        std::string name;
        std::cout << "Enter name for the account: ";
        std::getline(std::cin, name);
        std::cout << "Enter initial amount: ";
        double amount;
        std::cin >> amount;
        std::cin.ignore();
        std::unique_ptr<Account> p = std::make_unique<Trust_Account>(name, amount);
        accounts.push_back(std::move(p));
        return true;
    }
    return false;
}

void Account_Manager::depositToAll(double amount) {
    for (const auto &v : accounts)
        v->deposit(amount);
}

void Account_Manager::withdrawFromAll(double amount) {
    for (const auto &v : accounts)
        v->withdraw(amount);
}

double Account_Manager::getAmountFromUser() {
    double amount;
    std::cin >> amount;
    std::cin.ignore();
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        display_msg(msg::ERROR, "Invalid");
        return -1;
    }
    return amount;
}

void Account_Manager::displayAllAccounts() {
    std::cout << "\n=======================================\n";
    for (const auto &v : accounts)
        std::cout << *v << std::endl;
    std::cout << "\n=======================================\n";
}

