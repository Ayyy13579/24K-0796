#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

unsigned long hashPassword(const string& password) {
    unsigned long hash = 5381;
    for (char c : password) {
        hash = (hash * 33) + c;
    }
    return hash;
}

enum Permission {
    STUDENT = 1,
    TA = 2,
    PROFESSOR = 4
};

class User {
protected:
    string name;
    string userID;
    string email;
    string hashed_password;
    int permissions;

public:
    User(string n, string id, string em, string password, int perm)
        : name(n), userID(id), email(em), permissions(perm) {
        hashed_password = to_string(hashPassword(password));
    }

    bool authenticate(string password) {
        return hashed_password == to_string(hashPassword(password));
    }

    virtual void display() const {
        cout << "Name: " << name << "\nID: " << userID << "\nEmail: " << email << endl;
    }

    virtual void accessLab() {
        cout << "User has access to the lab." << endl;
    }

    int getPermissions() const {
        return permissions;
    }
};

class Student : public User {
protected:
    vector<int> assignments;

public:
    Student(string n, string id, string em, string password)
        : User(n, id, em, password, STUDENT) {}

    void display() const override {
        User::display();
        cout << "Role: Student" << endl;
    }

    void addAssignment(int assignmentID) {
        assignments.push_back(0);
    }

    void submitAssignment(int assignmentID) {
        if (assignmentID >= 0 && assignmentID < assignments.size()) {
            assignments[assignmentID] = 1;
            cout << "Assignment " << assignmentID << " submitted." << endl;
        } else {
            cout << "Invalid assignment ID." << endl;
        }
    }

    bool isAssignmentSubmitted(int assignmentID) const {
        if (assignmentID >= 0 && assignmentID < assignments.size()) {
            return assignments[assignmentID] == 1;
        }
        return false;
    }
};

class TA : public Student {
private:
    vector<Student*> assignedStudents;
    vector<string> projects;

public:
    TA(string n, string id, string em, string password)
        : Student(n, id, em, password) {
        permissions = TA;
    }

    void display() const override {
        Student::display();
        cout << "Role: Teaching Assistant" << endl;
    }

    void assignStudent(Student* student) {
        if (assignedStudents.size() < 10) {
            assignedStudents.push_back(student);
            cout << "Assigned Student " << student->userID << " to TA." << endl;
        } else {
            cout << "TA can only manage up to 10 students!" << endl;
        }
    }

    void assignProject(string project) {
        if (projects.size() < 2) {
            projects.push_back(project);
            cout << "Assigned project: " << project << endl;
        } else {
            cout << "TA can only work on 2 projects at a time!" << endl;
        }
    }

    void viewProjects() const {
        cout << "Projects TA is working on:" << endl;
        for (const string& project : projects) {
            cout << project << endl;
        }
    }
};

class Professor : public User {
private:
    vector<TA*> assignedTAs;
    vector<string> researchProjects;

public:
    Professor(string n, string id, string em, string password)
        : User(n, id, em, password, PROFESSOR) {}

    void display() const override {
        User::display();
        cout << "Role: Professor" << endl;
    }

    void assignProjectToTA(TA* ta, string project) {
        ta->assignProject(project);
    }

    void collaborateWithTA(TA* ta) {
        cout << "Professor collaborating with TA on projects." << endl;
        ta->viewProjects();
    }
};

void authenticateAndPerformAction(User* user, string action, string password) {
    if (user->authenticate(password)) {
        cout << "Authenticated successfully!" << endl;
        if (action == "submit assignment" && (user->getPermissions() & STUDENT)) {
            Student* student = dynamic_cast<Student*>(user);
            if (student) {
                cout << "Performing assignment submission..." << endl;
                student->submitAssignment(0);
            }
        } else if (action == "assign project" && (user->getPermissions() & PROFESSOR)) {
            Professor* professor = dynamic_cast<Professor*>(user);
            if (professor) {
                cout << "Professor assigning project..." << endl;
                professor->assignProjectToTA(new TA("TA2", "ID2", "ta2@example.com", "password"), "Project 1");
            }
        } else {
            cout << "Action not allowed for this user role!" << endl;
        }
    } else {
        cout << "Authentication failed!" << endl;
    }
}

int main() {
    Student s1("John Doe", "S1", "john@example.com", "password123");
    TA ta1("Jane Smith", "TA1", "jane@example.com", "password123");
    Professor p1("Dr. Brown", "P1", "drbrown@example.com", "profpass");

    s1.display();
    ta1.display();
    p1.display();

    authenticateAndPerformAction(&s1, "submit assignment", "password123");
    authenticateAndPerformAction(&ta1, "assign project", "password123");
    authenticateAndPerformAction(&p1, "assign project", "profpass");

    return 0;
}
