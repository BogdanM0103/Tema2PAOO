#include "BankAccount.h"

int main() {
    try {
        // Demonstrating Item 4: Proper initialization
        BankAccount acc1("Alice", 1001, 500.0);
        acc1.deposit(200);
        acc1.withdraw(100);

        // Demonstrating Item 5: Explicitly defined special member functions
        BankAccount acc2 = acc1;  // Copy constructor
        acc2.withdraw(50);

        BankAccount acc3("Bob", 1002, 300.0);
        acc3 = acc1;  // Copy assignment
        acc3.deposit(100);

        BankAccount acc4 = std::move(acc3);  // Move constructor
        acc4.deposit(50);

        BankAccount acc5("Charlie", 1003, 700.0);
        acc5 = std::move(acc4);  // Move assignment
        acc5.withdraw(200);

        // Demonstrating Item 6: Disallowed default constructor
        // BankAccount acc6; // Uncommenting this line will result in a compile-time error

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
