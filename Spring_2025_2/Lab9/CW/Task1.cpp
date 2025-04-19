#include <iostream>
#include <string>
using namespace std;

class Wallet {
    private:
    float balance;
    float dailydeposit;
    float dailywithdrawal;
    const int limit = 100000;
    public:
    Wallet() : balance(0), dailydeposit(0), dailywithdrawal(0) {}
    void deposit(float amount) {
        if (dailydeposit + amount < limit) {
            dailydeposit += amount;
            balance += amount;
        } else {
            cout << "Deposit amount exceeds the daily limit." << endl;
        } 
    }
    void withdrawal(float amount) {
        if (dailywithdrawal + amount < limit) {
            dailywithdrawal += amount;
            balance -= amount;
        } else {
            cout << "Withdrawal amount exceeds the daily limit." << endl;
        }
    }
    float getBalance() {
        cout << "Current balance: " << balance << endl;
        return balance;
    }
};

class User {
    private:
    int userID;
    string name;
    Wallet wallet;
    public:
    User() : userID(0), name("") {}
    User(int id, string n) : userID(id), name(n) {}
    void deposit(float amount) {
        wallet.deposit(amount);
    }
    void withdrawal(float amount) {
        wallet.withdrawal(amount);
    }
    float getBalance() {
        cout << "Name: " << name << endl;
        return wallet.getBalance();
    }
};

int main() {
    User user1(1, "John Doe");
    User user2(2, "Jane Smith");
    user1.deposit(50000);
    user1.withdrawal(20000);
    user1.getBalance();
    user1.deposit(500000);
    user1.getBalance();
    user2.deposit(200000);
    user2.getBalance();
}