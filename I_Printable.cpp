/**
 * @file I_Printable.cpp
 * @author Marissa Campa (marissag.campa@gmail.com)
 * @brief Implementation file for the interface class I_Printable
 * @date 2022-06-06
 * @copyright Copyright (c) 2022
 * 
 */
#include "I_Printable.h"

/**
 * @brief Overloaded stream insertion operator
 * 
 * This method is declared as friend of the I_Printable class. 
 * It calls the pure virtual function print(), that must be overriden 
 * by any class derived from I_Printable  
 * 
 * @param os Output stream object by reference
 * @param obj An object of the I_Printable class
 * @return std::ostream& The output stream object with the result from
 *          the print() function
 */
std::ostream &operator<<(std::ostream &os, const I_Printable &obj)  {
    obj.print(os);
    return os;
}

