#include <iostream>
#include <vector>
using namespace std;

class Shape {
    protected:
    vector<int> position;
    string color;
    float borderThickness;
    public:
    virtual void draw() {
        cout << "Drawing a shape..." << endl;
    }
    virtual void calcArea() {
        cout << "Default area." << endl;
    }
    virtual void calcPerimeter() {
        cout << "Default perimeter." << endl;
    }
};

class Circle : public Shape {
    public:
    float radius;
    vector <int> centerposition;
    void draw() override {
        cout << "Drawing a circle..." << endl;
    }
    void calcArea() override {
        cout << "Area of circle: " << 3.14 * radius * radius << endl;
    }
    void calcPerimeter() override {
        cout << "Perimeter of circle: " << 2 * 3.14 * radius << endl;
    }
};

class Rectangle : public Shape {
    public:
    int width;
    int height;
    int topleftpos;
    void draw() override {
        cout << "Drawing a rectangle..." << endl;
    }
    void calcArea() override {
        cout << "Area of rectangle: " << width * height << endl;
    }
    void calcPerimeter() override {
        cout << "Perimeter of rectangle: " << 2 * (width + height) << endl;
    }
};

class Triangle : public Shape {
    public:
    int side1;
    int side2;
    int side3;
    void draw() override {
        cout << "Drawing a triangle..." << endl;
    }
    void calcArea() override {
        cout << "Area of triangle: " << 1/2 * side1 * side2 * side3 << endl;
    }
    void calcPerimeter() override {
        cout << "Perimeter of triangle: " << side1 + side2 + side3 << endl;
    }
};

class Polygon : public Shape {
    public:
    int numSides;
    vector<int> sideLengths;
    Polygon(int sides) : numSides(sides), sideLengths(3) {}
    void draw() override {
        cout << "Drawing a polygon..." << endl;
    }
    void calcArea() override {
        cout << "Area of polygon: " << numSides * 3 << endl;
    }
    void calcPerimeter() override {
        cout << "Perimeter of polygon: " << numSides * 2 << endl;
    }
};

int main() {
    Circle c;
    c.draw();
    c.calcArea();
    c.calcPerimeter();
    Rectangle r;
    r.draw();
    r.calcArea();
    r.calcPerimeter();
    Triangle t;
    t.draw();
    t.calcArea();
    t.calcPerimeter();
    Polygon p(5);
    p.draw();
    p.calcArea();
    p.calcPerimeter();
}