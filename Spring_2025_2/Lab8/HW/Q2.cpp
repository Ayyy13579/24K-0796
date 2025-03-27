#include <iostream>

using namespace std;

class Shape {
private:
    float area;

public:
    Shape(float a = 0) : area(a) {}

    float Area() const {
        return area;
    }

    Shape operator+(const Shape& other) const {
        return Shape(area + other.area);
    }

    void display() const {
        cout << "Area: " << area << endl;
    }
};

int main() {
    Shape shape1(20.5);
    Shape shape2(30.5);

    cout << "Shape 1 ";
    shape1.display();

    cout << "Shape 2 ";
    shape2.display();

    Shape totalArea = shape1 + shape2;
    totalArea.display();
}
