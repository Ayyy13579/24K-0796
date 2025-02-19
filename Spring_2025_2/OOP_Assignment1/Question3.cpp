#include <iostream>
using namespace std;

class User {
    public:
    int age;
    char licensetype;
    int contact;
    int userID;

    void Register() {
        cout << "Enter the age of the user: ";
        cin >> age;
        cout << "Enter the license type of the user: ";
        cin >> licensetype;
        cout << "Enter the contact number of the user: ";
        cin >> contact;
        cout << "Enter the user ID: ";
        cin >> userID;
    }
};

class Vehicles {
    public:
    int model;
    float rentalprice;
    char eligibility;

    void AddVehicle() {
        cout << "Enter the model of the vehicle: ";
        cin >> model;
        cout << "Enter the rental price of the vehicle: ";
        cin >> rentalprice;
        cout << "Enter the eligibility of the vehicle: ";
        cin >> eligibility;
    }
};


int main() {
    User u1;
    int numVehicles;
    cout << "Enter the number of vehicles: ";
    cin >> numVehicles;
    Vehicles* vArray = new Vehicles[numVehicles];
    u1.Register();
    for (int i = 0; i < numVehicles; i++) {
        vArray[i].AddVehicle();
    }
    for (int i = 0; i < numVehicles; i++) {
        cout << "Vehicle " << i + 1 << ":" << endl;
        cout << "Model: " << vArray[i].model << endl;
        cout << "Rental Price: " << vArray[i].rentalprice << endl;
        cout << "Eligibility: " << vArray[i].eligibility << endl;
    }
    cout << "Which vehicle would you like to rent? ";
    int choice;
    cin >> choice;
    if (choice > numVehicles) {
        cout << "Invalid choice!" << endl;
    } else {
    if (u1.licensetype == 'F') {
        cout << "Vehicle rented! " << endl;
        cout << "Model: " << vArray[choice - 1].model << endl;
        cout << "Rental Price: " << vArray[choice - 1].rentalprice << endl;
    } else if (u1.licensetype == 'I') {
        if (vArray[choice - 1].eligibility == 'I' || vArray[choice - 1].eligibility == 'L') {
            cout << "Vehicle rented! " << endl;
            cout << "Model: " << vArray[choice - 1].model << endl;
            cout << "Rental Price: " << vArray[choice - 1].rentalprice << endl;
        } else {
            cout << "You cant rent this vehicle!" << endl;
        }
    } else if (u1.licensetype == 'L') {
        if (vArray[choice - 1].eligibility == 'L') {
            cout << "Vehicle rented! " << endl;
            cout << "Model: " << vArray[choice - 1].model << endl;
            cout << "Rental Price: " << vArray[choice - 1].rentalprice << endl;
        } else {
            cout << "You cant rent this vehicle!" << endl;
        }
    }
    }

}