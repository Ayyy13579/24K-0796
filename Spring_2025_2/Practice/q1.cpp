#include <iostream>
using namespace std;

template<typename T, int size>
class UniqueCart {
    T* items[size];
    int itemCount;
    public:
    void add(const T& newItem) {
        if (itemCount < size) {
            items[itemCount] = new T(newItem);
            itemCount++;
        } else {
            cout << "Cart is full!" << endl;
        }
    }
    void remove(const T& itemToRemove) {
        if (itemCount > 0) {

        }
    }
};

class DuplicateItemException : public exception {
    public:
    const char* what() const noexcept override {
        return "Duplicate item found!";
    }
};

class ItemNotFoundException : public exception {
    public:
    const char* what() const noexcept override {
        return "Item not found!";
    }
};

class OutofBoundsException : public exception {
    public:
    const char* what() const noexcept override {
        return "Index out of bounds!";
    }
};