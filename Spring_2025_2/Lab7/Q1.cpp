#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Account {
protected:
    int accountID;
    float funds;
    string holderName;
    string typeOfAccount;
    vector<string> transactionHistory;

public:
    Account(int id, float initialBalance, string name, string accType) : accountID(id), funds(initialBalance), holderName(name), typeOfAccount(accType) {}
    virtual ~Account() {}

    virtual void addFunds(float amount) {
        if (amount > 0) {
            funds += amount;
            transactionHistory.push_back("Added: " + to_string(amount));
            cout << "Deposit successful." << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    virtual void removeFunds(float amount) {
        if (amount > 0 && funds >= amount) {
            funds -= amount;
            transactionHistory.push_back("Removed: " + to_string(amount));
            cout << "Withdrawal successful." << endl;
        } else {
            cout << "Insufficient funds or invalid withdrawal amount." << endl;
        }
    }

    virtual void computeInterest() {
        cout << "Interest calculated for a general account." << endl;
    }

    void displayAccountDetails() const {
        cout << "Account ID: " << accountID << endl;
        cout << "Holder Name: " << holderName << endl;
        cout << "Account Type: " << typeOfAccount << endl;
        cout << "Current Balance: " << funds << endl;
    }

    virtual void showTransactions() const {
        cout << "Transaction Record:" << endl;
        for (const auto& entry : transactionHistory) {
            cout << entry << endl;
        }
    }
};

class SavingsAccount : public Account {
    float interestRate;
    float minBalance;

public:
    SavingsAccount(int id, float initialBalance, string name, float minimumBalance, float rate)
        : Account(id, initialBalance, name, "Savings"), minBalance(minimumBalance), interestRate(rate) {}

    void computeInterest() override {
        funds += funds * interestRate;
        cout << "Interest applied to savings account." << endl;
    }

    void removeFunds(float amount) override {
        if (funds - amount >= minBalance) {
            Account::removeFunds(amount);
        } else {
            cout << "Cannot withdraw. Minimum balance requirement not met." << endl;
        }
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(int id, float initialBalance, string name)
        : Account(id, initialBalance, name, "Checking") {}
};

class FixedDepositAccount : public Account {
    float fixedRate;
    string maturityDate;
    int depositCounter;

public:
    FixedDepositAccount(int id, float initialBalance, string name, string maturity, float rate)
        : Account(id, initialBalance, name, "Fixed Deposit"), maturityDate(maturity), fixedRate(rate), depositCounter(0) {}

    void computeInterest() override {
        funds += funds * fixedRate;
        cout << "Fixed deposit interest applied." << endl;
    }

    void addFunds(float amount) override {
        if (depositCounter < 1) {
            Account::addFunds(amount);
            depositCounter++;
        } else {
            cout << "Deposit not allowed. Fixed deposit accounts accept only one deposit." << endl;
        }
    }

    void removeFunds(float amount) override {
        cout << "Cannot withdraw. Funds are locked until " << maturityDate << endl;
    }
};

int main() {
    SavingsAccount savings(12345, 1000, "John Doe", 500, 0.05);
    savings.displayAccountDetails();
    savings.addFunds(500);
    savings.removeFunds(200);
    savings.computeInterest();
    savings.showTransactions();

    FixedDepositAccount fixedDeposit(67890, 5000, "Jane Doe", "2025-12-31", 0.10);
    fixedDeposit.displayAccountDetails();
    fixedDeposit.addFunds(1000);
    fixedDeposit.addFunds(500);
    fixedDeposit.removeFunds(200);
    fixedDeposit.computeInterest();
    fixedDeposit.showTransactions();

    return 0;
}
