#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string n, double b) 
    : Account(n, b) {
}

Checking_Account::Checking_Account(const Checking_Account& src) 
    : Account(src.name, src.balance) {
}

bool Checking_Account::withdraw(double amount) {
    return Account::withdraw(amount + withdraw_fee);
}

void Checking_Account::print(std::ostream &os) const {
    os << "Checking Account: " << name << ", balance: " << balance;
}

