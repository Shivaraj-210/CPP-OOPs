#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string model_no;
    string engine_type;

public:
    string car_brand;
    string car_model;
    string car_type;
    string fuel_type;
    float mileage;
    float fuel_capacity;
    string colour;
    double price;

    void setcarDetails(string model, string engine) {
        this->model_no = model;
        this->engine_type = engine;
    }

    void getCarInfo() {
        cout << "Internal Details of the car:\n";
        cout << "Car Details: " << endl;
        cout << "Brand: " << car_brand << endl;
        cout << "Model: " << car_model << endl;
        cout << "Type: " << car_type << endl;
        cout << "Fuel Type: " << fuel_type << endl;
        cout << "Mileage: " << mileage << " km/l" << endl;
        cout << "Colour: " << colour << endl;
        cout << "Price: $" << price << endl;
    }

    void addCarInfo(string brand, string model, string type,
                    string fuel, float mileage,
                    float fuel_capacity, string colour,
                    double price) {

        this->car_brand = brand;
        this->car_model = model;
        this->car_type = type;
        this->fuel_type = fuel;
        this->mileage = mileage;
        this->fuel_capacity = fuel_capacity;
        this->colour = colour;
        this->price = price;
    }

    void addFuelInfo(string fuel, float fuel_capacity) {
        this->fuel_type = fuel;
        this->fuel_capacity = fuel_capacity;
    }

    void startCar() {
        cout << "Engine type: " << engine_type << endl;
        cout << car_brand << "'s " << car_model
             << " The car has started." << endl;
    }

    void accelerate() {
        float speed = 0.0;
        speed += 10.0;

        cout << "Accelerating speed: "
             << speed + 10 << " km/h" << endl;

        fuel_capacity -= 0.1;

        fuelinfo();
    }

    void applyBrakes() {
        float speed = 20.0;

        if (speed > 0) {
            speed -= 10.0;
        }

        cout << "Brakes applied. The car is slowing down to "
             << speed << " km/h" << endl;
    }

    void fuelinfo() {
        if (fuel_type == "Petrol") {
            cout << "Fuel Type: Petrol" << endl;
        }
        else if (fuel_type == "Diesel") {
            cout << "Fuel Type: Diesel" << endl;
        }
        else if (fuel_type == "Electric") {
            cout << "Fuel Type: Electric" << endl;
        }

        cout << "Current Fuel Capacity: "
             << fuel_capacity << " liters" << endl;
    }

    void calculateMileage(float distance_travelled,
                           float fuel_used) {

        mileage = distance_travelled / fuel_used;

        cout << "Current Mileage: "
             << mileage << " km/l" << endl;

        float estimated_distance =
            mileage * fuel_capacity;

        cout << "Estimated Distance the car can travel "
             << "with current fuel: "
             << estimated_distance << " km/"
             << (fuel_type == "" ? "N/A" : fuel_type)
             << endl;
    }

    void showCarInfo() {
        cout << "Car Information: " << endl;
        cout << "Brand: " << car_brand << endl;
        cout << "Model: " << car_model << endl;
        cout << "Type: " << car_type << endl;
        cout << "Fuel Type: " << fuel_type << endl;
        cout << "Mileage: " << mileage << " km/l" << endl;
        cout << "Fuel Capacity: " << fuel_capacity << " liters" << endl;
        cout << "Colour: " << colour << endl;
        cout << "Price: $" << price << endl;
    }
};

void parkCar() {
    cout << "The car is parked." << endl;
}

int main() {
    Car car1;
 
    car1.addCarInfo("Toyota", "Camry", "Sedan",
                    "Petrol", 15.0, 50.0,
                    "Red", 30000.0);

    car1.setcarDetails("CAM123", "V6");

    car1.addFuelInfo("Petrol", 15.0);

    car1.startCar();

    car1.showCarInfo();

    for (int i = 0; i < 3; i++) {
        if (i % 2 == 0) {
            car1.accelerate();
        }
        else {
            car1.applyBrakes();
        }
    }

    // Corrected function call
    parkCar();

    car1.calculateMileage(150.0, 10.0);

    return 0;
}