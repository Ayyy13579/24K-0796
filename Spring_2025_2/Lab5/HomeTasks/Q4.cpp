#include <iostream>
using namespace std;

class Student {
private:
    const int roll_no;

public:
    Student() : roll_no(0) {}    

    void setRollNumber(int roll) {
        *(const_cast<int*>(&this->roll_no)) = roll;
    }

    void display() const {
        cout << "Student Roll Number: " << roll_no << endl;
    }
};

int main() {
    int roll;
    cout << "Enter student roll number: ";
    cin >> roll;
    
    Student s;
    s.setRollNumber(roll);
    s.display();
    
    return 0;
}
