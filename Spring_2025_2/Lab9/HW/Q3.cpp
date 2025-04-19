#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int id;
    float salary;
public:
    virtual void getdata() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Salary: ";
        cin >> salary;
    }
    virtual void displaydata() {
        cout << "Name: " << name << ", ID: " << id << ", Salary: $" << salary << endl;
    }
    virtual void bonus() {
        cout << "Base Bonus: $" << (salary * 0.05) << endl;
    }
};

class Admin : virtual public Person {
public:
    void getdata() override {
        Person::getdata();
    }

    void displaydata() override {
        Person::displaydata();
    }

    void bonus() override {
        cout << "Admin Bonus: $" << (salary * 0.10) << endl;
    }
};

class Account : virtual public Person {
public:
    void getdata() override {
        Person::getdata();
    }
    void displaydata() override {
        Person::displaydata();
    }

    void bonus() override {
        cout << "Account Bonus: $" << (salary * 0.08) << endl;
    }
};

class Master : public Admin, public Account {
public:
    void getdata() override {
        Person::getdata();
    }

    void displaydata() override {
        Person::displaydata();
    }

    void bonus() override {
        cout << "Master Bonus: $" << (salary * 0.15) << endl;
    }
};

int main() {
    Person* p;
    Admin a;
    Account ac;
    Master m;

    a.getdata();
    a.displaydata();
    a.bonus();

    ac.getdata();
    ac.displaydata();
    ac.bonus();

    m.getdata();
    m.displaydata();
    m.bonus();
}