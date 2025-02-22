#include <iostream>
using namespace std;

class Student {
    public:
    string name;
    string rollno;
    bool feespaid;
    string assignedstop;
    
    Student(string n, string id, bool fees, string stop) {
        name = n;
        rollno = id;
        feespaid = fees;
        assignedstop = stop;
    }

    void registerStudent(string rollno) {
        cout << "Student Registered!" << endl;
    }
    void attendance() {
        cout << "Attendance marked!" << endl;
    }
};

class Stop {
    public:
    string stopName;
    int studentsassigned[10];

    Stop() {}
    
    Stop(string name) {
        stopName = name;
    }

    void assignStudent(int rollno, int index) {
        if (index < 10) {
            studentsassigned[index] = rollno;
            cout << "Student assigned to stop!" << endl;
        }
        else {
            cout << "Stop full!" << endl;
        }
    }
    void removeStudent(int rollno) {
        for (int i = 0; i < 10; i++) {
            if (studentsassigned[i] == rollno) {
                studentsassigned[i] = 0;
                cout << "Student removed from stop!" << endl;
                return;
            }
        }
        cout << "Student not found!" << endl;
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
        cout << "Stop added to route!" << endl;
    }
    void removeStop(int index) {
        stops[index] = Stop("");
        cout << "Stop removed from route!" << endl;
    }
};

class Point {
    int pointNumber;
    int capacity;
    Route assignedRoute;

    Point(int number, int cap, Route r) {
        pointNumber = number;
        capacity = cap;
        assignedRoute = r;
    }

    void assignRoute(Route r) {
        assignedRoute = r;
    }
    void boardStudent(Student s) {
        cout << "Student boarded!" << endl;
    }   
};

int main() {
    Student s1("Default", "24K-1111", true, "Gulshan");
    Student s2("ABC", "24K-2222", true, "Malir");
    s1.registerStudent("24K-1111");
    s2.registerStudent("24K-2222");
    s1.attendance();
    s2.attendance();
    Stop stop1("Gulshan");
    Stop stop2("Malir");
    stop1.assignStudent(1111, 0);
    stop1.assignStudent(2222, 1);
    Stop stops[] = {stop1, stop2};
    Route r1("University Road", stops);
}