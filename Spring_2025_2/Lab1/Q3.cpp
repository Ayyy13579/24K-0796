#include <iostream>
using namespace std;

int main() {
    string name;
    int customerID, units;
    float bill, surcharge = 0, total;
    cout << "Enter the name of the customer: ";
    cin >> name;
    cout << "Enter the customer ID: ";
    cin >> customerID;
    cout << "Enter the number of units consumed: ";
    cin >> units;
    if (units < 199) {
        bill = units * 16.20;
    } else if (units < 300) {
        bill = units * 20.10;
    } else if (units < 500) {
        bill = units * 27.10;
    } else {
        bill = units * 35.90;
    }
    if (bill > 18000) {
        surcharge = bill * 0.15;
        total = bill + surcharge;
    } else {
        total = bill;
    }
    cout << "Customer ID: " << customerID << endl;
    cout << "Customer Name: " << name << endl;
    cout << "Units Consumed: " << units << endl;
    cout << "Amount Charges: " << bill << endl;
    cout << "Surcharge Amount: " << surcharge << endl;
    cout << "Total Amount Paid By the Customer: " << total << endl;
}