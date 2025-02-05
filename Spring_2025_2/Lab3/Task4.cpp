#include <iostream>
using namespace std;

class Employee {
	public:
		string firstname;
		string lastname;
		double monthlysalary;
		void salary() {
			if (monthlysalary < 0) {
				monthlysalary = 0.0;
			}
		}
};

int main() {
	int yearly1, yearly2;
	Employee e1;
	Employee e2;
	cout << "Enter first name of Employee 1: ";
	cin >> e1.firstname;
	cout << "Enter first name of Employee 2: ";
	cin >> e2.firstname;
	cout << "Enter salary of Employee 1: ";
	cin >> e1.monthlysalary;
	cout << "Enter salary of Employee 2: ";
	cin >> e2.monthlysalary;
	yearly1 = e1.monthlysalary * 12;
	yearly2 = e2.monthlysalary * 12;
	cout << "Yearly salary of " << e1.firstname << " is " << yearly1 << endl;
	cout << "Yearly salary of " << e2.firstname << " is " << yearly2 << endl;
	yearly1 = yearly1 * 1.1;
	yearly2 = yearly2 * 1.1;
	cout << "New Yearly salary of " << e1.firstname << " is " << yearly1 << endl;
	cout << "New Yearly salary of " << e2.firstname << " is " << yearly2 << endl;
}
