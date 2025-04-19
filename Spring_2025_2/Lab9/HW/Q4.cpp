#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    string name;
    int id;
public:
    void setName(string n) {
        name = n;
    }
    void setId(int i) {
        id = i;
    }
    string getName() {
        return name;
    }
    int getId() {
        return id;
    }
    virtual float getTuition(string status, int creditHours) = 0;
};

class GraduateStudent : public Student {
private:
    string researchTopic;
public:
    void setResearchTopic(string topic) {
        researchTopic = topic;
    }
    string getResearchTopic() {
        return researchTopic;
    }
    float getTuition(string status, int creditHours) override {
        float rate;
        if (status == "undergraduate") {
            rate = 200;
        } else if (status == "graduate") {
            rate = 300;
        } else if (status == "doctoral") {
            rate = 400;
        } else {
            cout << "Invalid." << endl;
        }
        return creditHours * rate;
    }
};

int main() {
    GraduateStudent gs;
    gs.setName("Alice");
    gs.setId(1001);
    gs.setResearchTopic("Machine Learning in Medicine");
    cout << "Student Name: " << gs.getName() << endl;
    cout << "Student ID: " << gs.getId() << endl;
    cout << "Research Topic: " << gs.getResearchTopic() << endl;
    string status = "graduate";
    int credits = 9;
    float tuition = gs.getTuition(status, credits);
    cout << "Tuition for " << status << " student taking " << credits << " credit hours: $" << tuition << endl;
}
