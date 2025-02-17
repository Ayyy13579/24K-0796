#include <iostream>
using namespace std;

class Account {
private:
    double balance;

public:
    Account(double initialBalance) {
        if (initialBalance >= 0) {
            balance = initialBalance;
        } else {
            balance = 0;
            cout << "Initial balance is invalid. Setting balance to 0." << endl;
        }
    }

    void credit(double amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            cout << "Invalid credit amount." << endl;
        }
    }

    void debit(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        } else {
            cout << "Debit amount exceeded account balance." << endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    void display() const {
        cout << "Current balance: " << balance << endl;
    }
};

int main() {
    Account acc(1000.0);
    acc.display();

    acc.credit(500.0);
    cout << "After crediting 500: ";
    acc.display();

    acc.debit(300.0);
    cout << "After debiting 300: ";
    acc.display();

    acc.debit(1500.0);

    return 0;
}
