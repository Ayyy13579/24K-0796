#include <iostream>
using namespace std;

struct Subject {
    string name;
};

struct ID {
    int id;
    Subject* sub;
};

int main() {
    ID student;
    student.sub = new Subject[3];
    student.id = 1234;
    for (int i=0; i<3; i++) {
        cout << "Enter the name of subject " << i+1 << endl;
        cin >> student.sub[i].name;
    }
    cout << "Student ID: " << student.id << endl;
    for (int i=0; i<3; i++) {
        cout << "Subject " << i+1 << ": " << student.sub[i].name << endl;
    }
    delete[] student.sub;
}