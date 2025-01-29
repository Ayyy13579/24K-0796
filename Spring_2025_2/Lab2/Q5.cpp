#include <iostream>
#include <algorithm>
using namespace std;

struct Entity {
    int id;
    string name;
};

bool compareByID(Entity &a, Entity &b) {
    return a.id < b.id;
}

bool compareByName(Entity &a, Entity &b) {
    return a.name < b.name;
}

int main() {
    int n;
    cout << "Enter the number of entities: ";
    cin >> n;
    Entity* entities = new Entity[n];
    for (int i=0; i<n; i++) {
        cout << "Enter the id of entity " << i+1;
        cin >> entities[i].id;
        cout << "Enter the name of entity " << i+1;
        cin >> entities[i].name;
    }
    sort(entities, entities+n, compareByID);
    cout << "Sorted by ID: " << endl;
    for (int i=0; i<n; i++) {
        cout << entities[i].id << " " << entities[i].name << endl;
    }
    sort(entities, entities+n, compareByName);
    cout << "Sorted by Name: " << endl;
    for (int i=0; i<n; i++) {
        cout << entities[i].id << " " << entities[i].name << endl;
    }
}