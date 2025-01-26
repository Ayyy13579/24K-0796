#include <iostream>
using namespace std;

int secondHighest(float* array);

int main() {
    float array[20];
    for (int i = 0; i < 20; i++) {
        cout << "Enter a number: ";
        cin >> array[i];
    }

    int result = secondHighest(array);
    cout << "The second highest number is: " << result << endl;
}

int secondHighest(float* array) {
    float highest = 0;
    float secondHighest = 0;
    for (int i = 0; i < 20; i++) {
        if (array[i] > highest) {
            secondHighest = highest;
            highest = array[i];
        }
        else if (array[i] > secondHighest) {
            secondHighest = array[i];
        }
    }
    return secondHighest;
}