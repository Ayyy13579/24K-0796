#include <iostream>
using namespace std;

void resize(int* array, int newsize, int oldsize) {
    int* newArray = new int[newsize];
    for (int i=0; i<oldsize; i++) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
}

int main() {
    int size = 5;
    int* array = new int[size], count = 0;
    while (true) {
        cout << "Enter item for element " << count+1 << " or enter 99 to exit: " << endl;
        cin >> array[count];
        if (array[count] == 99) {
            resize(array, count, size);
            break;
        }
        if (count == size) {
            resize(array, size*2, size);
        }
        count++;
    }
    for (int i=0; i<10; i++) {
        cout << array[i] << " " << endl;
    }
    delete[] array;
}