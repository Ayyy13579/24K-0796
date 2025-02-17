#include <iostream>
#include <cmath>
using namespace std;

class Circle {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getArea() const {
        return M_PI * radius * radius;
    }

    double getPerimeter() const {
        return 2 * M_PI * radius;
    }

    void display() const {
        cout << "Circle with radius: " << radius << endl;
        cout << "Area: " << getArea() << endl;
        cout << "Perimeter: " << getPerimeter() << endl;
    }
};

int main() {
    Circle c(5.0);
    c.display();

    return 0;
}
