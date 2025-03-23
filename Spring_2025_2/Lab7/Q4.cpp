#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person {
protected:
    string fullName;
    string identification;
    string residence;
    int contactNumber;
    string emailAddress;
public:
    Person(string name, string id, string addr, int phone, string email)
        : fullName(name), identification(id), residence(addr), contactNumber(phone), emailAddress(email) {}
    
    string getFullName() {
        return fullName;
    }
    
    virtual void showDetails() {
        cout << "Name: " << fullName << endl;
        cout << "ID: " << identification << endl;
        cout << "Address: " << residence << endl;
        cout << "Phone: " << contactNumber << endl;
        cout << "Email: " << emailAddress << endl;
    }
    
    void modifyDetails(string name, string id, string addr, int phone, string email) {
        fullName = name;
        identification = id;
        residence = addr;
        contactNumber = phone;
        emailAddress = email;
    }
};

class Professor : public Person {
protected:
    string faculty;
    int subjectsTaught;
    float monthlySalary;
public:
    Professor(string dept, int courses, float salary, string name, string id, string addr, int phone, string email)
        : faculty(dept), subjectsTaught(courses), monthlySalary(salary), Person(name, id, addr, phone, email) {}
    
    void showDetails() override {
        Person::showDetails();
        cout << "Department: " << faculty << endl;
        cout << "Courses Taught: " << subjectsTaught << endl;
        cout << "Salary: " << monthlySalary << endl;
    }
};

class Student : public Person {
protected:
    int yearOfEnrollment;
    int totalCourses;
    float gradePointAverage;
public:
    Student(int year, int courses, float gpa, string name, string id, string addr, int phone, string email)
        : yearOfEnrollment(year), totalCourses(courses), gradePointAverage(gpa), Person(name, id, addr, phone, email) {}
    
    void showDetails() override {
        Person::showDetails();
        cout << "Enrollment Year: " << yearOfEnrollment << endl;
        cout << "Courses Enrolled: " << totalCourses << endl;
        cout << "GPA: " << gradePointAverage << endl;
    }
};

class Staff : public Person {
protected:
    string division;
    string jobTitle;
    float earnings;
public:
    Staff(string dept, string pos, float salary, string name, string id, string addr, int phone, string email)
        : division(dept), jobTitle(pos), earnings(salary), Person(name, id, addr, phone, email) {}
    
    void showDetails() override {
        Person::showDetails();
        cout << "Department: " << division << endl;
        cout << "Position: " << jobTitle << endl;
        cout << "Salary: " << earnings << endl;
    }
};

class Course {
protected:
    string courseID;
    int creditHours;
    string lecturer;
    string title;
    string timetable;
    vector<Student> enrolledStudents;
public:
    Course(string id, int credits, string instructor, string courseName, string schedule)
        : courseID(id), creditHours(credits), lecturer(instructor), title(courseName), timetable(schedule) {}
    
    void enrollStudent(Student std) {
        enrolledStudents.push_back(std);
        cout << "Student " << std.getFullName() << " successfully enrolled in " << title << " under " << lecturer << "." << endl;
    }
    
    void calculateGrades() {
        cout << "Computing grades for the course " << title << endl;
    }
    
    void displayCourseDetails() {
        cout << "Course ID: " << courseID << endl;
        cout << "Course Name: " << title << endl;
        cout << "Credit Hours: " << creditHours << endl;
        cout << "Instructor: " << lecturer << endl;
        cout << "Schedule: " << timetable << endl;
        cout << "Total Enrolled Students: " << enrolledStudents.size() << endl;
    }
};

int main() {
    Student student1(2021, 5, 3.8, "Alice", "S1238", "123 Main St", 5591234, "alice@uni.com");
    Professor professor1("Computer Science", 3, 75000, "Dr. Smith", "P456", "456 Elm St", 5555678, "smith@uni.com");
    Staff staff1("Accounts", "Manager", 50000, "David", "ST789", "789 Oak St", 5559101, "xyz@uni.com");
    Course course1("CS101", 3, "Mr. Harry", "Programming Fundamentals", "Mon/Wed/Thur 10:00 AM");
    
    student1.showDetails();
    professor1.showDetails();
    staff1.showDetails();
    
    course1.enrollStudent(student1);
    course1.displayCourseDetails();
    course1.calculateGrades();
    
    return 0;
}
