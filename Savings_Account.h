#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_

#include "Account.h"
#include <iostream>
#include <string>

class Savings_Account : public Account 
{
private:
    static constexpr const char *def_name = "Savings Account";
    static constexpr const double def_balance = 0.0;
protected:
    static constexpr const double def_rate = 0.03;
    double int_rate;

public:
    Savings_Account(std::string n = def_name, double b = def_balance, double r = def_rate);
    Savings_Account(const Savings_Account& src);

    virtual bool deposit(double amount) override;

    virtual void print(std::ostream &os) const override;

    virtual ~Savings_Account() = default;
};

#endif