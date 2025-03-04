#include <iostream>
using namespace std;

class BankAccount {
        private:
        int accountNumber;
        float balance;
        public:
        void deposit(int amount) {
            balance += amount;
        }
        void withdraw(int amount) {
            if (amount < balance) {
                balance -= amount;
            }
        }
        float getBalance() {
            return balance;
        }
};

class SavingsAccount : public BankAccount {
    public:
    float applyMonthlyinterest() {
        int amount = getBalance();
        amount *= 1.04;
    }
};

class CheckingAccount : public BankAccount {
    int limit = -500;
    int amount = getBalance();
    void checkOverdraft() {
        if (amount < limit) {
            cout << "Overdraft limit exceeded." << endl;
    }    
    }
};

class BusinessAccount : public BankAccount {
    int amount = getBalance();
    void applyTax() {
        amount *= 0.90; 
    }
};

