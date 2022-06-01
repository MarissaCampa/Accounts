#include "Savings_Account.h"

Savings_Account::Savings_Account(std::string n, double b, double r) 
    : Account(n, b), int_rate(r) {
}

Savings_Account::Savings_Account(const Savings_Account& src) 
    : Account(src.name, src.balance), int_rate(src.int_rate) {
}

bool Savings_Account::deposit(double amount) {
    amount += (amount * int_rate);
    return Account::deposit(amount);
}

void Savings_Account::print(std::ostream &os) const {
    os << "Savings Account: " << name << ", balance: " << balance;
}
