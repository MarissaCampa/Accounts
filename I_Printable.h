/**
 * @file I_Printable.h
 * @author Marissa Campa (marissag.campa@gmail.com)
 * @brief Header file for the interface class I_Printable
 * @date 2022-06-06
 * @copyright Copyright (c) 2022
 * 
 * This class serves as an interface class, to be able to make
 * inheriting classes printable to the output stream
 * 
 */
#ifndef I_PRINTABLE_H
#define I_PRINTABLE_H

#include <iostream>

class I_Printable 
{
    // Overloaded stream insertion operator
    friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);

public:
    // Pure virtual function to be overriden by inheriting classes
    virtual void print(std::ostream &os) const = 0;  

    // Virtual default destructor
    virtual ~I_Printable() = default;

};

#endif