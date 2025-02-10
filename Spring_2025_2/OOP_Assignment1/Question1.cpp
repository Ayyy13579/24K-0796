#include <iostream>
using namespace std;

class Mentor;
class Skill;
class Sport;

class Student {
    public:
    int studentID;
    string name;
    int age;
    string sportsInterests[3];
    string mentorAssigned;
    void registerForMentorship(Mentor& m);
    void viewMentorDetails() {
        cout << "Mentor Name: " << mentorAssigned << endl;
    }
    void updateSportsInterest(Sport& s, int index);
};

class Mentor {
    public:
    int mentorID;
    string name;
    string sportsExpertise[5];
    int maxLearners;
    string assignedLearners[3];
    void assignLearner(Student& s, int index) {
        if (index >= 3) {
            cout << "No more available space for learners." << endl;
        } else {
            assignedLearners[index] = s.name;
            index +=1;
        }
    }
    void removeLearner(Student& s, int index) {
        index -=1;
        if (index < 0) {
            cout << "No available learners to remove." << endl;
        } else {
            assignedLearners[index] = " ";
        }
    }
    void viewLearners() {
        for (int i = 0; i < maxLearners; i++) {
            cout << assignedLearners[i] << endl;
        }
    }
    void provideGuidance() {
        cout << "Guidance provided" << endl;
    }
};

void Student::registerForMentorship(Mentor &m) {
    mentorAssigned = m.name;
}

class Sport {
    public:
    int sportID;
    string name;
    string description;
    string requiredSkills[5];
    void addSkill(Skill& s, int index);
    void removeSkill(Skill&  s, int index);
};

void Student::updateSportsInterest(Sport& s, int index) {
    sportsInterests[index] = s.name;
}

class Skill {
    public:
    int skillID;
    string skillName;
    string description;
    void showSkillDetails() {
        cout << "Skill Name: " << skillName << endl;
        cout << "Description: " << description << endl;
    }
    void updateSkillDescription(string newDesc) {
        description = newDesc;
    }
};

void Sport::addSkill(Skill& s, int index) {
    requiredSkills[index] = s.skillName;
}
void Sport::removeSkill(Skill&  s, int index) {
    s.skillName = "";
}

int main() {
    Mentor m1;
    Student s1;
    int index = 0;
    m1.name = "Ali";
    m1.sportsExpertise[index] = "Tennis";
    s1.name = "Saad";
    s1.sportsInterests[index] = "Tennis";
    if (index < 3) {
        s1.registerForMentorship(m1);
        m1.assignLearner(s1, index);
    } else {
        cout << "No more available space for mentor." << endl;
    }
    s1.viewMentorDetails();
    m1.removeLearner(s1, index);
    s1.viewMentorDetails();
}