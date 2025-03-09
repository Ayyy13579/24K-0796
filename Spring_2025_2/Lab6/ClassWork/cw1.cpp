#include <iostream>
using namespace std;

class BankAccount {
        private:
        int accountNumber;
        float balance;
        bool isFrozen;
        public:
        void deposit(int amount) {
            if (isFrozen) {
                cout << "Account is frozen." << endl;
                return;
            } else {
            balance += amount;
            }
        }
        void withdraw(int amount) {
            if (isFrozen) {
                cout << "Account is frozen." << endl;
                return;
            } else {
            if (amount < balance) {
                balance -= amount;
            }
            }
        }
        void freeze() {
            isFrozen = true;
        }
        void unfreeze() {
            isFrozen = false;
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


class Customer {
    private:
    string name;
    BankAccount* account;
    public:
    Customer(string n) : name(n) {}
    ~Customer() {
        delete account;
    }
    void deposit(int amount) {
        account->deposit(amount);
    }
    void withdraw(int amount) {
        account->withdraw(amount);
    }
};

class Employee {
    private:
    string name;
    BankAccount* account;
    bool isFrozen;
    public:
    Employee(string n) : name(n), isFrozen(false) {}
    ~Employee() {
        delete account;
    }
};

class Teller : public Employee {
    public:
    Teller(string n) : Employee(n)  {}
    void freezeAccount(BankAccount* account) {
        account->freeze();
    }
    void unfreezeAccount(BankAccount* account) {
        account->unfreeze();
    }
};

class Manager : public Teller {
    public:
    Manager(string n) : Teller(n) {}
    void adjustAccount(BankAccount* account, int amount) {
        account->deposit(amount - account->getBalance());
    }
};