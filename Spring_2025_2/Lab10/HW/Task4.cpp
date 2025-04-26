#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <sstream>
using namespace std;

const size_t MAX_SIZE = 1024 * 1024;
const string BASE_LOG = "log.txt";

size_t getFileSize(const string& filename) {
    ifstream file(filename.c_str(), ios::binary | ios::ate);
    return file.is_open() ? static_cast<size_t>(file.tellg()) : 0;
}

void rotateLog() {
    int index = 1;
    string newName;
    do {
        newName = "log" + to_string(index++) + ".txt";
    } while (ifstream(newName.c_str()).good());

    if (rename(BASE_LOG.c_str(), newName.c_str()) != 0) {
        cerr << "Error: Could not rename log file." << endl;
    } else {
        cout << "Log rotated: " << newName << endl;
    }
}

int main() {
    for (int i = 1; i <= 100000; ++i) {
        size_t fileSize = getFileSize(BASE_LOG);
        
        if (fileSize >= MAX_SIZE) {
            rotateLog();
        }

        ofstream logFile(BASE_LOG.c_str(), ios::app);
        if (!logFile) {
            cerr << "Error: Could not open log file for writing." << endl;
            return 1;
        }

        logFile << "Log entry number " << i << endl;
        logFile.close();

        cout << "Logged entry " << i << endl;
    }

    cout << "Logging complete." << endl;
    return 0;
}