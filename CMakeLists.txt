cmake_minimum_required(VERSION 3.29)
project(Tema2PAOO)

set(CMAKE_CXX_STANDARD 26)

include_directories(include)

add_executable(Tema2PAOO main.cpp
        BankAccount.cpp
        BankAccount.h)
