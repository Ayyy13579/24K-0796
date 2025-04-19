#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
    string model;
    float price;
public:
    void setModel(string m) {
        model = m;
    }
    string getModel() {
        return model;
    }
    float getPrice() {
        return price;
    }
    virtual void setPrice(float base) = 0;
};

class Color : public Car {
private:
    string color;

public:
    void setColor(string c) {
        color = c;
    }
    string getColor() {
        return color;
    }
    void setPrice(float base) override {
        if (color == "Red") {
            price = base + 2000;
        } else {
            price = base + 1000;
        }
    }
};

class Company : public Car {
private:
    string companyName;
public:
    void setCompany(string name) {
        companyName = name;
    }
    string getCompany() {
        return companyName;
    }
    void setPrice(float base) override {
        if (companyName == "BMW" || companyName == "Mercedes") {
            price = base + 5000;
        } else {
            price = base + 2000;
        }
    }
};

int main() {
    Color car1;
    car1.setModel("Sedan");
    car1.setColor("Red");
    car1.setPrice(15000);
    cout << "Model: " << car1.getModel() << endl;
    cout << "Color: " << car1.getColor() << endl;
    cout << "Price: $" << car1.getPrice() << endl;

    Company car2;
    car2.setModel("SUV");
    car2.setCompany("BMW");
    car2.setPrice(20000);
    cout << "Model: " << car2.getModel() << endl;
    cout << "Company: " << car2.getCompany() << endl;
    cout << "Price: $" << car2.getPrice() << endl;
}