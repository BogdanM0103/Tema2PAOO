#include "BankAccount.h"

// Copy constructor
BankAccount::BankAccount(const BankAccount& other)
    : accountHolder(other.accountHolder), accountNumber(other.accountNumber), balance(other.balance) {
    std::cout << "Copy constructor called for account " << accountNumber << "\n";
}

// Copy assignment operator
BankAccount& BankAccount::operator=(const BankAccount& other) {
    if (this != &other) {
        accountHolder = other.accountHolder;
        accountNumber = other.accountNumber;
        balance = other.balance;
        std::cout << "Copy assignment operator called for account " << accountNumber << "\n";
    }
    return *this;
}

// Move constructor
BankAccount::BankAccount(BankAccount&& other) noexcept
    : accountHolder(std::move(other.accountHolder)), accountNumber(other.accountNumber), balance(other.balance) {
    std::cout << "Move constructor called for account " << accountNumber << "\n";
    other.accountNumber = 0;  // Leave the moved object in a valid state
    other.balance = 0;
}

// Move assignment operator
BankAccount& BankAccount::operator=(BankAccount&& other) noexcept {
    if (this != &other) {
        accountHolder = std::move(other.accountHolder);
        accountNumber = other.accountNumber;
        balance = other.balance;
        std::cout << "Move assignment operator called for account " << accountNumber << "\n";
        other.accountNumber = 0;
        other.balance = 0;
    }
    return *this;
}

// Destructor
BankAccount::~BankAccount() {
    std::cout << "BankAccount destructor called for account " << accountNumber << "\n";
}
