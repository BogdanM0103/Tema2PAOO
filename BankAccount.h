#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <iostream>
#include <stdexcept>

// Item 4: Ensure objects are initialized before use
class BankAccount {
private:
    std::string accountHolder;  // Name of the account holder
    int accountNumber;          // Unique account number
    double balance;             // Account balance

public:
    // Constructor initializes all member variables (Item 4)
    BankAccount(const std::string& holder, int accNumber, double initialBalance)
        : accountHolder(holder), accountNumber(accNumber), balance(initialBalance) {
        if (initialBalance < 0) {
            throw std::invalid_argument("Initial balance cannot be negative.");
        }
        std::cout << "BankAccount created for " << accountHolder
                  << " with account number " << accountNumber << "\n";
    }

    // Getter for balance
    double getBalance() const {
        return balance;
    }

    // Deposit method
    void deposit(double amount) {
        if (amount <= 0) {
            throw std::invalid_argument("Deposit amount must be positive.");
        }
        balance += amount;
        std::cout << "Deposited " << amount << " into account " << accountNumber
                  << ". New balance: " << balance << "\n";
    }

    // Withdrawal method
    void withdraw(double amount) {
        if (amount <= 0) {
            throw std::invalid_argument("Withdrawal amount must be positive.");
        }
        if (amount > balance) {
            throw std::runtime_error("Insufficient funds.");
        }
        balance -= amount;
        std::cout << "Withdrew " << amount << " from account " << accountNumber
                  << ". Remaining balance: " << balance << "\n";
    }

    // Item 5: Explicitly define special member functions
    BankAccount(const BankAccount& other);              // Copy constructor
    BankAccount& operator=(const BankAccount& other);   // Copy assignment operator
    BankAccount(BankAccount&& other) noexcept;          // Move constructor
    BankAccount& operator=(BankAccount&& other) noexcept; // Move assignment operator

    ~BankAccount();  // Destructor

    // Item 6: Disallow undesired functions
    BankAccount() = delete;  // Default constructor disallowed
};

#endif // BANKACCOUNT_H
