#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_

#include "Account.h"
#include <iostream>
#include <memory>
#include <vector>

void display(const Account &acc) {
    std::cout << acc << std::endl;
}

void display(const std::unique_ptr<Account> &acc) {
    std::cout << *acc << std::endl;
}

void display(const std::vector<std::unique_ptr<Account>> &vec) {
    for (const auto &v : vec)
        std::cout << *v << std::endl;
}

#endif