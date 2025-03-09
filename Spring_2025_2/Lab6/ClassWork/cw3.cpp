#include <iostream>
using namespace std;

class Employee {
    private:
        string name;
        int id;
    public:
    Employee(string n, int i) : name(n), id(i) {}
    virtual void IOrderTaker() {
        cout << "Order taken.." << endl;
    }
    virtual void IOrderPreparer() {
        cout << "Order prepared.." << endl;
    }
    virtual void IBiller() {
        cout << "Bill prepared.." << endl;
    }
};

class Waiter : virtual public Employee {
    public:
    Waiter(string n, int i) : Employee(n, i) {}
    void IOrderTaker() override {
        cout << "Order taken by waiter.." << endl;
    }
};

class Chef : virtual public Employee {
    public:
    Chef(string n, int i) : Employee(n, i) {}
    void IOrderPreparer() override {
        cout << "Order prepared by chef.." << endl;
    }
};

class Cashier : virtual public Employee {
    public:
    Cashier(string n, int i) : Employee(n, i) {}
    void IBiller() override {
        cout << "Bill prepared by cashier.." << endl;
    }
};

class Manager : public Waiter, public Chef, public Cashier {
    public:
    void IOrderTaker() override {
        cout << "Order taken by manager.." << endl;
    }
    void IBiller() override {
        cout << "Bill prepared by manager.." << endl;
    }
};

class Menu {
    private:
    string items[10];
    public:
    void displayMenu() {
        for (int i = 0; i < 10; i++) {
            cout << items[i] << endl;
        }
    }
};

class FoodMenu : public Menu {
    private:
    bool isCombo;
    int price;
    public:
    void displayMenu() {
        cout << "Food Menu" << endl;
        Menu::displayMenu();
    }
    void discount() {
        if (isCombo) {
            price *= 0.9;
        }
    }
};

class BeverageMenu : public Menu {
    private:
    float tax = 1.1;
    public:
    void displayMenu() {
        cout << "Beverage Menu" << endl;
        Menu::displayMenu();
    }
    void applyTax(string item) {
        cout << item << " price after tax: " << tax << endl;
    }
};