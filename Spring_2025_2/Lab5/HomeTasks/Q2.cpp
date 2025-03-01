#include <iostream>
using namespace std;

class Car {
public:
    string engine;
    int horsepower;
    int seating_capacity;
    int no_of_speakers;

    Car(string eng, int hp, int seat, int speakers)
        : engine(eng), horsepower(hp), seating_capacity(seat), no_of_speakers(speakers) {}

    void displayCar() const {
        cout << "Engine: " << engine << endl;
        cout << "Horsepower: " << horsepower << endl;
        cout << "Seating Capacity: " << seating_capacity << endl;
        cout << "Number of Speakers: " << no_of_speakers << endl;
    }

    void modifyCar(string eng, int hp, int seat, int speakers) const {
        const_cast<Car*>(this)->engine = eng;
        const_cast<Car*>(this)->horsepower = hp;
        const_cast<Car*>(this)->seating_capacity = seat;
        const_cast<Car*>(this)->no_of_speakers = speakers;
    }
};

int main() {
    Car myCar("V8", 400, 5, 6);
    cout << "Before modification:" << endl;
    myCar.displayCar();

    myCar.modifyCar("V6", 350, 4, 8);
    cout << "\nAfter modification:" << endl;
    myCar.displayCar();
    
    return 0;
}
