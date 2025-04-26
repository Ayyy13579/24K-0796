#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

const int MAX_EMPLOYEES = 100;

struct Employee {
    int id;
    string name;
    string designation;
    int years_of_service;
};

int readFromFile(const string& filename, Employee employees[]) {
    ifstream file(filename);
    string line;
    int count = 0;
    while (getline(file, line)) {
        istringstream iss(line);
        if (iss >> employees[count].id >> employees[count].name >> employees[count].designation >> employees[count].years_of_service) {
            count++;
        }
    }
    file.close();
    return count;
}

void writeToFile(const string& filename, Employee employees[], int count) {
    ofstream file(filename);
    for (int i = 0; i < count; i++) {
        file << employees[i].id << " " << employees[i].name << " " << employees[i].designation << " " << employees[i].years_of_service << endl;
    }
    file.close();
}

int filterManagers(Employee input[], Employee output[], int count) {
    int outCount = 0;
    for (int i = 0; i < count; i++) {
        if (input[i].designation == "manager" && input[i].years_of_service >= 2) {
            output[outCount++] = input[i];
        }
    }
    return outCount;
}

void incrementIdsAndYears(Employee employees[], int count) {
    for (int i = 0; i < count; i++) {
        employees[i].id += 100;
        employees[i].years_of_service += 1;
    }
}

void writeDummyData(const string& filename) {
    ofstream file(filename);
    file << "1 Alice manager 3\n";
    file << "2 Bob engineer 1\n";
    file << "3 Carol manager 1\n";
    file << "4 Dave technician 4\n";
    file << "5 Eve manager 5\n";
    file.close();
}

int main() {
    string filename = "employees.txt";
    writeDummyData(filename);

    Employee allEmployees[MAX_EMPLOYEES];
    int totalEmployees = readFromFile(filename, allEmployees);

    Employee filteredEmployees[MAX_EMPLOYEES];
    int filteredCount = filterManagers(allEmployees, filteredEmployees, totalEmployees);

    writeToFile(filename, filteredEmployees, filteredCount);

    incrementIdsAndYears(filteredEmployees, filteredCount);
    writeToFile(filename, filteredEmployees, filteredCount);

    cout << "Operations completed. Final data written to file.\n";
    return 0;
}
