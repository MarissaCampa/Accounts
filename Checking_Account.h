#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "Account.h"
#include <iostream>
#include <string>

class Checking_Account : public Account 
{
private:
    static constexpr const char *def_name = "Checking Account";
    static constexpr const int def_balance = 0.0;
    static constexpr const double withdraw_fee = 1.5;
public:
    Checking_Account(std::string n = def_name, double b = def_balance);
    Checking_Account(const Checking_Account& src);

    virtual bool withdraw(double amount) override;

    virtual void print(std::ostream &os) const override;

    virtual ~Checking_Account() = default;
};


#endif // _CHECKING_ACCOUNT_H_