#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

string uuid(int n) {
    return "uuid" + to_string(n);
}

void writeDummyData() {
    ofstream users("users.txt");
    users << "uuid1 Linus Torvalds California linus@linux.org\n";
    users << "uuid2 Ada Lovelace London ada@math.org\n";
    users.close();

    ofstream products("products.txt");
    products << "prod1 Laptop HighPerformanceLaptop 1500\n";
    products << "prod2 Mouse GamingMouse 60\n";
    products << "prod3 Keyboard MechanicalKeyboard 100\n";
    products.close();

    ofstream orders("orders.txt");
    orders << "ord1 uuid1 prod1 1500\n";
    orders << "ord2 uuid1 prod3 100\n";
    orders << "ord3 uuid2 prod2 60\n";
    orders.close();
}

string getUserIdByName(const string& firstName) {
    ifstream users("users.txt");
    string line, id, fname, lname, address, email;
    while (getline(users, line)) {
        istringstream iss(line);
        iss >> id >> fname >> lname >> address >> email;
        if (fname == firstName) {
            return id;
        }
    }
    return "";
}

void getProductNamesByUser(const string& userFirstName) {
    string userId = getUserIdByName(userFirstName);
    if (userId == "") {
        cout << "User not found.\n";
        return;
    }

    ifstream orders("orders.txt");
    string line, orderId, uid, pid;
    int paid;
    string productIds[100];
    int count = 0;

    while (getline(orders, line)) {
        istringstream iss(line);
        iss >> orderId >> uid >> pid >> paid;
        if (uid == userId) {
            productIds[count++] = pid;
        }
    }
    orders.close();

    ifstream products("products.txt");
    string prodId, name, desc;
    int price;
    cout << "Products ordered by " << userFirstName << ":\n";
    while (getline(products, line)) {
        istringstream iss(line);
        iss >> prodId >> name >> desc >> price;
        for (int i = 0; i < count; i++) {
            if (prodId == productIds[i]) {
                cout << "- " << name << endl;
                break;
            }
        }
    }
    products.close();
}

int main() {
    writeDummyData();
    getProductNamesByUser("Linus");
}