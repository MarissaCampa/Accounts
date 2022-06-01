#include "Account.h"

// Constructor
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

