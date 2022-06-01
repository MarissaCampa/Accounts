#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_

#include "Savings_Account.h"
#include <iostream>
#include <string>

class Trust_Account : public Savings_Account 
{
private:
    static constexpr const char *def_name = "Trust Account";
    static constexpr const int def_balance = 0.0;
    static constexpr const double bonus_min_amount = 5000;
    static constexpr const double bonus = 50;
    static constexpr const int total_movements_allowed = 3;
protected:
    int total_movements;

public:
    Trust_Account(std::string n = def_name, double b = def_balance, double r = def_rate);
    Trust_Account(const Trust_Account& src);

    virtual bool deposit(double amount) override;

    virtual void print(std::ostream &os) const override;

    virtual ~Trust_Account() = default;
};

#endif