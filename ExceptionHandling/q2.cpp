/*Implement a BankAccount class with methods to deposit and withdraw money.
Throw an exception if there is an attempt to withdraw more money than the current balance.*/
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class BankAccount {
    double balance;

public:
    BankAccount(double balance) : balance(balance) {}

    void deposit(double deposit) {
        balance += deposit;
    }

    void withdraw(double withdraw) {
        try {
            if (withdraw > balance) {
                throw runtime_error("Insufficient funds.");
            } else {
                balance -= withdraw;
            }
        } catch (const exception& e) {
            cerr << "Caught exception: " << e.what() << endl;
        }
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount b(2345.678);
    b.deposit(23.45);
    b.withdraw(2350.999);
    return 0;
}

