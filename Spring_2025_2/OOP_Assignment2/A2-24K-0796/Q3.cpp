#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Vehicle {
public:
    static int activeDeliveries;
    string vehicleID;
    double speed;
    double capacity;
    double energyEfficiency;

    Vehicle(string id, double spd, double cap, double eff) 
        : vehicleID(id), speed(spd), capacity(cap), energyEfficiency(eff) {
        activeDeliveries++;
    }

    virtual ~Vehicle() {
        activeDeliveries--;
    }

    virtual void move() const = 0;
    virtual void command(const string& cmd) const {
        cout << "Command: " << cmd << " received by " << vehicleID << endl;
    }

    static int getActiveDeliveries() {
        return activeDeliveries;
    }

    bool operator==(const Vehicle& other) const {
        return (this->speed == other.speed) && (this->capacity == other.capacity) && 
               (this->energyEfficiency == other.energyEfficiency);
    }

    virtual void calculateRoute() const {
        cout << "Calculating optimal route for " << vehicleID << "..." << endl;
    }

    virtual double estimateDeliveryTime(double distance) const {
        return distance / speed;
    }
};

int Vehicle::activeDeliveries = 0;


class RamzanDrone : public Vehicle {
public:
    RamzanDrone(string id) : Vehicle(id, 100, 10, 15) {}

    void move() const override {
        cout << vehicleID << " is flying at high speed to deliver Iftar!" << endl;
    }

    void command(const string& cmd) const override {
        if (cmd == "Deliver") {
            cout << vehicleID << " is delivering food for Iftar!" << endl;
        } else if (cmd == "DeliverUrgent") {
            cout << vehicleID << " is delivering an urgent Iftar package at high speed!" << endl;
        }
    }
};

class RamzanTimeShip : public Vehicle {
public:
    RamzanTimeShip(string id) : Vehicle(id, 30, 500, 10) {}

    void move() const override {
        cout << vehicleID << " is traveling through time to ensure historical accuracy!" << endl;
    }

    void command(const string& cmd) const override {
        if (cmd == "Deliver") {
            cout << vehicleID << " is delivering food but ensuring historical consistency!" << endl;
        } else if (cmd == "DeliverUrgent") {
            cout << vehicleID << " is prioritizing urgent historical delivery!" << endl;
        }
    }
};

class RamzanHyperPod : public Vehicle {
public:
    RamzanHyperPod(string id) : Vehicle(id, 200, 1000, 20) {}

    void move() const override {
        cout << vehicleID << " is racing underground to deliver bulk supplies!" << endl;
    }

    void command(const string& cmd) const override {
        if (cmd == "Deliver") {
            cout << vehicleID << " is delivering bulk supplies!" << endl;
        } else if (cmd == "DeliverUrgent") {
            cout << vehicleID << " is delivering bulk supplies with urgency!" << endl;
        }
    }
};

class ConflictResolutionSystem {
public:
    static Vehicle* resolveConflict(Vehicle& v1, Vehicle& v2, double distance) {
        double time1 = v1.estimateDeliveryTime(distance);
        double time2 = v2.estimateDeliveryTime(distance);

        if (time1 < time2) {
            return &v1;
        } else {
            return &v2;
        }
    }
};


int main() {
    RamzanDrone drone1("Drone1");
    RamzanTimeShip timeShip1("TimeShip1");
    RamzanHyperPod hyperPod1("HyperPod1");

    drone1.command("Deliver");
    timeShip1.command("DeliverUrgent");
    hyperPod1.command("Deliver");

    double deliveryDistance = 100;
    Vehicle* bestVehicle = ConflictResolutionSystem::resolveConflict(drone1, hyperPod1, deliveryDistance);

    cout << "\nThe best vehicle for this delivery is: " << bestVehicle->vehicleID << endl;

    cout << "Active deliveries in the system: " << Vehicle::getActiveDeliveries() << endl;

    return 0;
}
