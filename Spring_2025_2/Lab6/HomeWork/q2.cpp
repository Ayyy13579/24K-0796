#include <iostream>
using namespace std;

class Vehicles {
    private:
    float price;
    public:
    Vehicles(float p) : price(p) {}
    ~Vehicles() {}
    float getPrice() {
        return price;
    }
};

class Car : public Vehicles {
    private:
    int seats;
    int numdoors;
    string fueltype;
    public:
    Car(int s, int d, string f, float p) : seats(s), numdoors(d), fueltype(f), Vehicles(p) {}
    ~Car() {}
    int getSeats() {
        return seats;
    }
    int getDoors() {
        return numdoors;
    }
    string getFuelType() {
        return fueltype;
    }
};

class Motorcycle : public Vehicles {
    private:
    int numcylinders;
    int numgears;
    int numwheels;
    public:
    Motorcycle(int c, int g, int w, float p) : numcylinders(c), numgears(g), numwheels(w), Vehicles(p) {}
    ~Motorcycle() {}
    int getCylinders() {
        return numcylinders;
    }
    int getGears() {
        return numgears;
    }
    int getWheels() {
        return numwheels;
    }
};

class Audi : public Car {
    private:
    string model;
    public:
    Audi(string m, int s, int d, string f, float p) : model(m), Car(s, d, f, p) {}
    ~Audi() {}
    void display() {
        cout << "Model: " << model << endl;
        cout << "Seats: " << getSeats() << endl;
        cout << "Doors: " << getDoors() << endl;
        cout << "Fuel Type: " << getFuelType() << endl;
        cout << "Price: " << getPrice() << endl;
    }
};

class Yamaha : public Motorcycle {
    private:
    string model;
    public:
    Yamaha(string m, int c, int g, int w, float p) : model(m), Motorcycle(c, g, w, p) {}
    ~Yamaha() {}
    void display() {
        cout << "Model: " << model << endl;
        cout << "Cylinders: " << getCylinders() << endl;
        cout << "Gears: " << getGears() << endl;
        cout << "Wheels: " << getWheels() << endl;
        cout << "Price: " << getPrice() << endl;
    }
};

int main() {
    Audi a("A4", 5, 4, "Petrol", 5000000);
    Yamaha y("FZ", 1, 5, 2, 200000);
    a.display();
    y.display();
}