#include <iostream>
#include <algorithm>
using namespace std;

class DynamicArray {
private:
    int* data;
    int length;

public:
    DynamicArray() : data(nullptr), length(0) {}

    DynamicArray(int n) : length(n) {
        data = new int[length]{};
    }

    DynamicArray(const DynamicArray& other) : length(other.length) {
        data = new int[length];
        for (int i = 0; i < length; ++i) {
            data[i] = other.data[i];
        }
    }

    DynamicArray(DynamicArray&& other) noexcept : data(other.data), length(other.length) {
        other.data = nullptr;
        other.length = 0;
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this == &other) return *this;

        delete[] data;

        length = other.length;
        data = new int[length];
        for (int i = 0; i < length; ++i) {
            data[i] = other.data[i];
        }

        return *this;
    }

    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this == &other) return *this;

        delete[] data;

        data = other.data;
        length = other.length;

        other.data = nullptr;
        other.length = 0;

        return *this;
    }

    ~DynamicArray() {
        delete[] data;
    }

    int size() const {
        return length;
    }

    int& at(int index) {
        if (index < 0 || index >= length) {
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }

    const int& at(int index) const {
        if (index < 0 || index >= length) {
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }

    void resize(int newSize) {
        int* newData = new int[newSize]{};
        int minSize = min(length, newSize);

        for (int i = 0; i < minSize; ++i) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        length = newSize;
    }

    void display() const {
        for (int i = 0; i < length; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray arr1(5);
    cout << "Initial array: ";
    arr1.display();

    for (int i = 0; i < arr1.size(); ++i) {
        arr1.at(i) = i + 1;
    }
    cout << "After setting values: ";
    arr1.display();

    DynamicArray arr2 = arr1;
    cout << "Copied array: ";
    arr2.display();

    DynamicArray arr3 = move(arr1);
    cout << "Moved array: ";
    arr3.display();

    arr2.resize(8);
    cout << "Resized array: ";
    arr2.display();

    return 0;
}
