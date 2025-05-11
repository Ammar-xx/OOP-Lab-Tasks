#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
using namespace std;

class InsufficientFundsException : public exception {
private:
    string message;
public:
    InsufficientFundsException(double deficit) {
        ostringstream oss;
        oss << "InsufficientFundsException - Deficit: $";
        oss.precision(2);
        oss << fixed << deficit;
        message = oss.str();
    }
    const char* what() const noexcept override {
        return message.c_str();
    }
};

template <typename T>
class BankAccount {
private:
    T balance;

public:
    BankAccount(T initialBalance) : balance(initialBalance) {}

    void withdraw(T amount) {
        if (amount > balance) {
            throw InsufficientFundsException(amount - balance);
        }
        balance -= amount;
    }

    T getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount<double> account(500.00);
    
    cout.precision(2);
    cout << "Balance: $" << fixed << account.getBalance() << endl;

    try {
        cout << "Withdraw $600: ";
        account.withdraw(600.00);
        cout << "Success!" << endl;
    } catch (const InsufficientFundsException& e) {
        cout << e.what() << endl;
    }

    try {
        cout << "Withdraw $300: ";
        account.withdraw(300.00);
        cout << "Success! New balance: $" << account.getBalance() << endl;
    } catch (const InsufficientFundsException& e) {
        cout << e.what() << endl;
    }

    return 0;
}