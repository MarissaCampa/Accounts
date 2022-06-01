#include "Account.h"


Account::Account(std::string n, int a) 
    : name(n), balance(a) {
}

// Copy Constructor
Account::Account(const Account& src)
    : Account(src.name, src.balance) {
}

bool Account::deposit(double amount) {
    balance += amount;
    return true;
}

bool Account::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        return true;
    }
    display_msg(msg::INFO, "Insufficient funds");
    return false;
}

void Account::print(std::ostream &os) const {
    os << "Account: " << name << ", " << balance;
}

void Account::display_msg(msg m, std::string text, bool add_jump) {
    if (m == msg::INFO)
        std::cout << "[INFO] ";
    else if (m == msg::ERROR)
        std::cout << "[ERROR] ";
    else if (m == msg::USER)
        std::cout << "[USER] ";
    std::cout << text;
    if (add_jump)
        std::cout << '\n';
}
