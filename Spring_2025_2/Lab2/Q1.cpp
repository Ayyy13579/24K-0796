#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    int* arr = new int[5];
    for (int i=0; i<5; i++) {
        cout << "Enter element " << i+1 << endl;
        cin >> arr[i];
    }
    for (int i=0; i<5; i++) {
        sum += arr[i];

    }
    cout << "Sum is " << sum << endl;
}