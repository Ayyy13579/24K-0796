#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    string studentname;
    float marks1, marks2, marks3, marks4, marks5, average;
    cout << "Enter the name of the student: ";
    cin >> studentname;
    cout << "Enter the marks of the first test: ";
    cin >> marks1;
    cout << "Enter the marks of the second test: ";
    cin >> marks2;
    cout << "Enter the marks of the third test: ";
    cin >> marks3;
    cout << "Enter the marks of the fourth test: ";
    cin >> marks4;
    cout << "Enter the marks of the fifth test: ";
    cin >> marks5;
    average = (marks1 + marks2 + marks3 + marks4 + marks5) / 5;
    cout << "Student Name: " << studentname << endl;
    cout << "Average: " << average << endl;
}