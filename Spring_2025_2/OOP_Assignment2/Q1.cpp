#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    string rollno;
    bool feesPaid;

    Person(string n, string id, bool fees) {
        name = n;
        rollno = id;
        feesPaid = fees;
    }

    virtual void registerPerson() = 0;
    virtual void payFees() = 0;
};

class Student : public Person {
public:
    string assignedStop;

    Student(string n, string id, bool fees, string stop)
        : Person(n, id, fees), assignedStop(stop) {}

    void registerPerson() override {
        cout << "Student Registered: " << name << " with Roll No: " << rollno << endl;
    }

    void payFees() override {
        if (feesPaid) {
            cout << "Student " << name << " has already paid the fees for this semester!" << endl;
        } else {
            cout << "Student " << name << " pays semester fees." << endl;
            feesPaid = true;
        }
    }
};

class Teacher : public Person {
public:
    Teacher(string n, string id, bool fees)
        : Person(n, id, fees) {}

    void registerPerson() override {
        cout << "Teacher Registered: " << name << " with ID: " << rollno << endl;
    }

    void payFees() override {
        if (feesPaid) {
            cout << "Teacher " << name << " has already paid monthly fees!" << endl;
        } else {
            cout << "Teacher " << name << " pays monthly fees." << endl;
            feesPaid = true;
        }
    }
};

class Staff : public Person {
public:
    Staff(string n, string id, bool fees)
        : Person(n, id, fees) {}

    void registerPerson() override {
        cout << "Staff Registered: " << name << " with ID: " << rollno << endl;
    }

    void payFees() override {
        if (feesPaid) {
            cout << "Staff " << name << " has already paid monthly fees!" << endl;
        } else {
            cout << "Staff " << name << " pays monthly fees." << endl;
            feesPaid = true;
        }
    }
};

class Stop {
public:
    string stopName;
    int studentsAssigned[10];

    Stop() {}

    Stop(string name) {
        stopName = name;
    }

    void assignStudent(int rollno, int index) {
        if (index < 10) {
            studentsAssigned[index] = rollno;
            cout << "Student assigned to stop: " << stopName << endl;
        }
        else {
            cout << "Stop is full!" << endl;
        }
    }

    void removeStudent(int rollno) {
        for (int i = 0; i < 10; i++) {
            if (studentsAssigned[i] == rollno) {
                studentsAssigned[i] = 0;
                cout << "Student removed from stop: " << stopName << endl;
                return;
            }
        }
        cout << "Student not found at this stop!" << endl;
    }
};

class Route {
public:
    string routeName;
    Stop stops[10];

    Route() {}

    Route(string name, Stop stops[10]) {
        routeName = name;
        for (int i = 0; i < 10; i++) {
            this->stops[i] = stops[i];
        }
    }

    void addStop(string stopName, int index) {
        stops[index] = Stop(stopName);
        cout << "Stop " << stopName << " added to route " << routeName << endl;
    }

    void removeStop(int index) {
        stops[index] = Stop("");
        cout << "Stop removed from route!" << endl;
    }

    bool operator==(const Route& other) const {
        for (int i = 0; i < 10; i++) {
            if (this->stops[i].stopName != other.stops[i].stopName) {
                return false;
            }
        }
        return true;
    }
};

class Point {
private:
    int pointNumber;
    int capacity;
    Route assignedRoute;

public:
    Point(int number, int cap, Route r) : pointNumber(number), capacity(cap), assignedRoute(r) {}

    void assignRoute(Route r) {
        assignedRoute = r;
    }

    void boardStudent(Person& p) {
        cout << p.name << " boarded!" << endl;
    }
};

int main() {
    Student s1("Alice", "24K-1111", false, "Gulshan");
    Teacher t1("Mr. Smith", "T-001", false);
    Staff st1("Mrs. Johnson", "S-001", false);

    s1.registerPerson();
    t1.registerPerson();
    st1.registerPerson();

    s1.payFees();
    t1.payFees();
    st1.payFees();

    Stop stop1("Gulshan");
    Stop stop2("Malir");

    stop1.assignStudent(1111, 0);
    stop2.assignStudent(2222, 0);

    Stop stops[] = {stop1, stop2};
    Route r1("University Road", stops);

    Point p1(1, 20, r1);
    p1.boardStudent(s1);

    Route r2("University Road", stops);
    if (r1 == r2) {
        cout << "Routes are the same!" << endl;
    } else {
        cout << "Routes are different!" << endl;
    }

    return 0;
}
