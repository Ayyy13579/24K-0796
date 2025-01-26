#include <iostream>
using namespace std;

int sum(int* array);

int main() {
    int array[10];
    for (int i = 0; i < 10; i++) {
        cout << "Enter a number: ";
        cin >> array[i];
    }

    int result = sum(array);
    cout << "The sum of the array is: " << result << endl;
}

int sum(int* array) {
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += array[i];
    }
    return sum;
}