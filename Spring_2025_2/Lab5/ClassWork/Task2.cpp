#include <iostream>
using namespace std;

class Car {
    public:
    string name;
    int model;
};

class Garage {
    private:
    Car* cars[3];
    public:
    void parkCar(Car* car, int index) {
        cars[index] = car;
    }
    void listCars() {
        for (int i = 0; i < 3; i++) {
            cout << cars[i]->name << " " << cars[i]->model << endl;
        }
    }
};

int main() {
    Car car1;
    car1.name = "Toyota";
    car1.model = 2021;
    Car car2;
    car2.name = "Honda";
    car2.model = 2022;
    Car car3;
    car3.name = "Suzuki";
    car3.model = 2023;
    Garage g;
    g.parkCar(&car1, 0);
    g.parkCar(&car2, 1);
    g.parkCar(&car3, 2);
    g.listCars();
}