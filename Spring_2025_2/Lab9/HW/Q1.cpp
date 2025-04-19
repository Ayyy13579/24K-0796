#include <iostream>

using namespace std;

class Shape {
    public:
    virtual void getArea() = 0;
};

class Rectangle : public Shape {
    private:
    int length, width;
    public:
    Rectangle(int l, int w) : length(l), width(w) {}
    void getArea() {
        cout << "Area of Rectangle: " << length * width << endl;
    }
};

class Triangle : public Shape {
    private:
    int base, height;
    public:
    Triangle(int b, int h) : base(b), height(h) {}
    void getArea() {
        cout << "Area of Triangle: " << 0.5 * base * height << endl;
    }
};

int main() {
    Rectangle rect(5, 10);
    Triangle tri(4, 8);
    rect.getArea();
    tri.getArea();
}