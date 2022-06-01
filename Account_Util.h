#ifndef ACCOUNT_UTIL_H
#define ACCOUNT_UTIL_H

#include "Account.h"
#include <iostream>
#include <memory>
#include <vector>

// void display(const Account &acc) {
//     std::cout << acc << std::endl;
// }

// void display(const std::unique_ptr<Account> &acc) {
//     std::cout << *acc << std::endl;
// }

// void display(const std::vector<std::unique_ptr<Account>> &vec) {
//     for (const auto &v : vec)
//         std::cout << *v << std::endl;
// }

enum class msg { INFO, ERROR, USER };

static void display_msg(msg m, std::string text, bool add_jump = true) {
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





#endif  // _ACCOUNT_UTIL_H_