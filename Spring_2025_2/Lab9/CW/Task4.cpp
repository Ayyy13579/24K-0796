#include <iostream>

using namespace std;

class Flight {
    private:
    int flightNo;
    string departure;
    string arrival;
    int capacity;
    bool booked;
    public:
    void bookSeat() {
        if (capacity > 0) {
            capacity--;
            cout << "Seat booked successfully." << endl;
            booked = true;
        } else {
            cout << "No seats available." << endl;
        }
    }
    void cancelSeat() {
        if (booked == true) {
            capacity++;
            cout << "Seat cancelled successfully." << endl;
        }
    }
    void upgradeSeat() {
        if (booked == true) {
            cout << "Seat upgraded successfully." << endl;
        }
    }
};

class Passenger {
    private:
    int id;
    string name;
    public:
    void requestBooking(Flight& flight) {
        flight.bookSeat();
    }
    void requestCancellation(Flight& flight) {
        flight.cancelSeat();
    }
    void requestUpgrade(Flight& flight) {
        flight.upgradeSeat();
    }
};

int main() {
    Flight flight1;
    Flight flight2;
    Passenger passenger1;
    Passenger passenger2;
    passenger1.requestBooking(flight1);
    passenger1.requestCancellation(flight1);
    passenger1.requestUpgrade(flight1);
    passenger2.requestBooking(flight2);
}