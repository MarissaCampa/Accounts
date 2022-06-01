#include "Trust_Account.h"


Trust_Account::Trust_Account(std::string n, double b, double r) 
    : Savings_Account(n, b, r) {
}

Trust_Account::Trust_Account(const Trust_Account& src) 
    : Savings_Account(src.name, src.balance, src.int_rate) {
}

bool Trust_Account::deposit(double amount) {
    if (total_movements < total_movements_allowed) {
        total_movements++;
        amount += amount >= bonus_min_amount ? bonus : 0; 
        return Savings_Account::deposit(amount);
    }
    std::cout << "Total limit of movements per year has been reached" << std::endl;
    return false;
}

void Trust_Account::print(std::ostream &os) const {
    os << "Trust Account: " << name << ", balance: " << balance << ", total movements: " << total_movements;
}
