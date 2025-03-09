#include <iostream>
using namespace std;

class Student {
    private:
    string name;
    int age;
    public:
    Student(string n, int a) : name(n), age(a) {}
    ~Student() {}
    string getName() {
        return name;
    }
    int getAge() {
        return age;
    }
};

class Marks : public Student {
    private:
    int courses[5];
    int marks[5];
    public:
    Marks(string n, int a, int c[], int m[]) : Student(n, a) {
        for (int i = 0; i < 5; i++) {
            courses[i] = c[i];
            marks[i] = m[i];
        }
    }
    ~Marks() {}
    void display() {
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        for (int i = 0; i < 5; i++) {
            cout << "Course " << courses[i] << ": " << marks[i] << endl;
        }
    }
};

class Result : public Marks {
    private:
    int total;
    float average;
    public:
    Result(string n, int a, int c[], int m[]) : Marks(n, a, c, m) {
        total = 0;
        for (int i = 0; i < 5; i++) {
            total += m[i];
        }
        average = total / 5;
    }
    ~Result() {}
    void display() {
        Marks::display();
        cout << "Total: " << total << endl;
        cout << "Average: " << average << endl;
    }
};

int main() {
    int courses[5] = {1, 2, 3, 4, 5};
    int marks[5] = {90, 80, 70, 60, 50};
    Result r("John Doe", 20, courses, marks);
    r.display();
}
    