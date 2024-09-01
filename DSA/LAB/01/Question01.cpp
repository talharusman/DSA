#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    // Default constructor
    BankAccount() : balance(0.0) {}

    // Parameterized constructor
    BankAccount(double initialBalance) : balance(initialBalance) {}

    // Copy constructor
    BankAccount(const BankAccount &other) : balance(other.balance) {}

    // Function to deduct an amount
    void deduct(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds to deduct $" << amount << endl;
        }
    }

    // Function to get the balance
    double getBalance() const {
        return balance;
    }
};

int main() {
    // a) Default Constructor Usage
    BankAccount account1;
    cout << "Account 1 balance: $" << account1.getBalance() << endl;

    // b) Parameterized Constructor Usage
    BankAccount account2(1000.0);
    cout << "Account 2 balance: $" << account2.getBalance() << endl;

    // c) Copy Constructor Usage
    BankAccount account3(account2);
    account3.deduct(200.0);
    cout << "Account 3 balance after deduction: $" << account3.getBalance() << endl;
    cout << "Account 2 balance remains unchanged: $" << account2.getBalance() << endl;

    return 0;
}
