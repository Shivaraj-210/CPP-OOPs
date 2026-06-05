#include <iostream>
#include <vector>
using namespace std;

class Vehicle {
private:
    int vehicleID;
    string vehicleName;
    double rentalRatePerDay;
    bool isAvailable;

public:
    // Constructor
    Vehicle(int id, string name, double rate) {
        vehicleID = id;
        vehicleName = name;
        rentalRatePerDay = rate;
        isAvailable = true;
    }

    // Rent vehicle
    void rentVehicle() {
        if (isAvailable) {
            isAvailable = false;
            cout << vehicleName << " rented successfully.\n";
        } else {
            cout << vehicleName << " is already rented.\n";
        }
    }

    // Return vehicle
    void returnVehicle() {
        if (!isAvailable) {
            isAvailable = true;
            cout << vehicleName << " returned successfully.\n";
        } else {
            cout << vehicleName << " was not rented.\n";
        }
    }

    // Calculate rental cost
    double calculateRentalCost(int days) {
        return rentalRatePerDay * days;
    }

    // Display details
    void displayVehicle() {
        cout << "ID: " << vehicleID
             << "\nName: " << vehicleName
             << "\nRate Per Day: $" << rentalRatePerDay
             << "\nStatus: " << (isAvailable ? "Available" : "Rented")
             << "\n----------------------\n";
    }

    // Check availability
    bool available() {
        return isAvailable;
    }
};

int main() {
    vector<Vehicle> vehicles;

    // Adding vehicles
    vehicles.push_back(Vehicle(101, "Car", 50));
    vehicles.push_back(Vehicle(102, "Bike", 20));
    vehicles.push_back(Vehicle(103, "Scooter", 15));

    cout << "Available Vehicles:\n";
    for (auto &v : vehicles) {
        if (v.available())
            v.displayVehicle();
    }

    // Rent vehicle
    vehicles[0].rentVehicle();

    // Rental cost
    int days = 5;
    cout << "\nRental Cost for 5 days: $"
         << vehicles[0].calculateRentalCost(days)
         << endl;

    // Return vehicle
    vehicles[0].returnVehicle();   
    cout << "\nUpdated Vehicle List:\n";
    for (auto &v : vehicles)
        v.displayVehicle();

    return 0;
}   