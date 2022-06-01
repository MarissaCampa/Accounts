#include "Account.h"
#include "Account_Util.h"
#include "Account_Manager.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include <iostream>

const int BUFFER_SIZE = 50;

int main(int, char**) 
{
    std::string sel = "x";
    Account_Manager mn;

    do 
    {
        mn.showMenu();
        std::getline(std::cin, sel);

        if (sel == "a" || sel == "A") 
        {
            std::cout << "Your seleccion was (a)" << std::endl;
        }
        else if (sel == "b" || sel == "B") 
        {
            std::cout << "Your seleccion was (b)" << std::endl;
        }
        else if (sel == "c" || sel == "C") 
        {
            std::cout << "Your seleccion was (c)" << std::endl;
        }
        else if (sel == "x" || sel == "X") 
        {
            break;
        }
        else 
        {
            std::cout << "Invalid\n";
        }
    } 
    while (sel != "x" && sel != "X");

    std::cout << std::endl;
    return 0;
}
