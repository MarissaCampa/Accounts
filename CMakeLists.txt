cmake_minimum_required(VERSION 3.0.0)
project(accounts VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(accounts main.cpp 
    I_Printable.cpp I_Printable.h
    Account.cpp Account.h 
    Account_Util.h
    Account_Manager.h Account_Manager.cpp
    Savings_Account.cpp Savings_Account.h 
    Checking_Account.cpp Checking_Account.h 
    Trust_Account.cpp Trust_Account.h 
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
