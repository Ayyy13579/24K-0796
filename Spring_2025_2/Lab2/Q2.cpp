#include <iostream>
using namespace std;

void* addfunction(void* arr) {
    int x;
    for (int i=0 ; i<5; i++) {
        cout << "Enter a number to add to element " << i+1 << endl;
        cin >> x;
        arr[i] += x;
    }
    return arr;
    }

int main() {
    int array[5] = {1,2,3,4,5};
    cout << "Array before adding: \n";
    for (int i=0 ; i<5; i++) {
        cout << array[i] << " " << endl;
    }
    addfunction(array);
    cout << "Array after adding: \n";
    for (int i=0 ; i<5; i++) {
        cout << array[i] << " " << endl;
    }
}
