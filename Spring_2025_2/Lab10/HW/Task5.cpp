#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void addTask() {
    string task;
    ofstream tasks("tasks.txt", ios::app);
    if (!tasks) {
        cerr << "Error: Could not open tasks file." << endl;
        return;
    }
    cout << "Enter a task: " << endl;
    getline(cin, task);
    tasks << task << endl;
    tasks.close();
}

void viewTasks() {
    string task;
    ifstream tasks("tasks.txt");
    if (!tasks) {
        cerr << "Error: Could not open tasks file." << endl;
        return;
    }
    cout << "Tasks:" << endl;
    while (getline(tasks, task)) {
        cout << task << endl;
    }
    tasks.close();
}

void markDone() {
    string tasktodel, task;
    bool found = false;
    cout << "Enter the task to mark as done: " << endl;
    getline(cin, tasktodel);
    
    ifstream mytasks("tasks.txt");
    if (!mytasks) {
        cerr << "Error: Could not open tasks file." << endl;
        return;
    }
    ofstream temp("temp.txt");
    if (!temp) {
        cerr << "Error: Could not open temporary file." << endl;
        return;
    }
    while (getline(mytasks, task)) {
        if (task == tasktodel) {
            found = true;
            cout << "Task marked as done: " << task << endl;
        } else {
            temp << task << endl;
        }
    }
    mytasks.close();
    temp.close();
    remove("tasks.txt");
    if (rename("temp.txt", "tasks.txt") != 0) {
        perror("Error renaming file");
    }
}


int main() {
    int choice;
    do {
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Done" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markDone();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
}