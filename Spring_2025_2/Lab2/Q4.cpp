#include <iostream>
using namespace std;

struct Employee {
    int employee_id;
    string name;
    float salary;
};

struct Organization {
    string org_name;
    int org_number;
    Employee* emp;
};

int main() {
    Organization org;
    org.emp = new Employee;
    org.org_name = "XYZ Limited";
    org.org_number = 45000;
    org.emp->employee_id = 1345;
    org.emp->name = "Zaid";
    org.emp->salary = 50000;
    cout << "Organization Name: " << org.org_name << endl;
    cout << "Organization Number: " << org.org_number << endl;
    cout << "Employee ID: " << org.emp->employee_id << endl;
    cout << "Employee Name: " << org.emp->name << endl;
    cout << "Employee Salary: " << org.emp->salary << endl;
    delete org.emp;
}