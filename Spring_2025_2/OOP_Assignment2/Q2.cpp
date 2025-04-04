#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Ghost {
public:
    string name;
    int scareLevel;

    Ghost(string n, int scare) : name(n), scareLevel(scare) {}

    virtual void performHaunting() const = 0;

    virtual ~Ghost() {}

    friend ostream& operator<<(ostream& os, const Ghost& g) {
        os << g.name << " (Scare Level: " << g.scareLevel << ")";
        return os;
    }

    Ghost operator+(const Ghost& g) const {
        int combinedScareLevel = this->scareLevel + g.scareLevel;
        return Ghost(this->name + " & " + g.name, combinedScareLevel);
    }
};

class Poltergeist : public Ghost {
public:
    Poltergeist(string n, int scare) : Ghost(n, scare) {}

    void performHaunting() const override {
        cout << name << " is moving objects around! Watch out!" << endl;
    }
};

class Banshee : public Ghost {
public:
    Banshee(string n, int scare) : Ghost(n, scare) {}

    void performHaunting() const override {
        cout << name << " lets out a terrifying scream!" << endl;
    }
};

class ShadowGhost : public Ghost {
public:
    ShadowGhost(string n, int scare) : Ghost(n, scare) {}

    void performHaunting() const override {
        cout << name << " is whispering creepily in the dark..." << endl;
    }
};

class ShadowPoltergeist : public Poltergeist, public ShadowGhost {
public:
    ShadowPoltergeist(string n, int scare) 
        : Ghost(n, scare), Poltergeist(n, scare), ShadowGhost(n, scare) {}

    void performHaunting() const override {
        Poltergeist::performHaunting();
        ShadowGhost::performHaunting();
    }
};

class Visitor {
public:
    string name;
    int bravery;

    Visitor(string n, int b) : name(n), bravery(b) {}

    void reactToHaunting(int scareLevel) const {
        if (scareLevel < bravery - 2) {
            cout << name << " laughs at the ghost!" << endl;
        } else if (scareLevel > bravery + 2) {
            cout << name << " screams and runs away!" << endl;
        } else {
            cout << name << " has a shaky voice, but stands their ground!" << endl;
        }
    }
};

class HauntedHouse {
public:
    string houseName;
    vector<Ghost*> ghosts;

    HauntedHouse(string name) : houseName(name) {}

    void addGhost(Ghost* ghost) {
        ghosts.push_back(ghost);
    }

    void runSimulation(const vector<Visitor>& visitors) const {
        cout << "Welcome to the haunted house: " << houseName << "!" << endl;

        for (const auto& ghost : ghosts) {
            cout << "\n" << *ghost << " is haunting...\n";
            ghost->performHaunting();

            for (const auto& visitor : visitors) {
                visitor.reactToHaunting(ghost->scareLevel);
            }
        }
    }
};

void visit(const vector<Visitor>& visitors, HauntedHouse& house) {
    house.runSimulation(visitors);
}

int main() {
    srand(time(0));

    HauntedHouse house1("Spooky Mansion");
    house1.addGhost(new Poltergeist("Ghost1", rand() % 10 + 1));
    house1.addGhost(new Banshee("Ghost2", rand() % 10 + 1));
    house1.addGhost(new ShadowGhost("Ghost3", rand() % 10 + 1));

    HauntedHouse house2("Haunted Castle");
    house2.addGhost(new Poltergeist("Ghost4", rand() % 10 + 1));
    house2.addGhost(new ShadowPoltergeist("Ghost5", rand() % 10 + 1));

    vector<Visitor> visitors = {
        Visitor("Alice", 3), 
        Visitor("Bob", 6),    
        Visitor("Charlie", 9)
    };

    cout << "\nVisiting Haunted House 1:\n";
    visit(visitors, house1);

    cout << "\nVisiting Haunted House 2:\n";
    visit(visitors, house2);

    return 0;
}
