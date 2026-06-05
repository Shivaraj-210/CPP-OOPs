#include <iostream>
#include <string>
using namespace std;


class Car
{
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
    double price;


    // setter for assigning the values for private data members
    void setCarDetails(string model, string engine)
    {
        model_no = model;
        engine_type = engine;
    }


    // getter for accessing private data members
    void getCarInfo(){
        cout << "Internal Details of the Car are as follows: \n";
        cout << "Model No.: " << model_no << "\nEngine Type: " << engine_type << endl;
    }


    // setter for public members to add car basic details
    void addCarInfo(string brand, string model_name, string typeOfCar, double carFare){
        car_brand = brand;
        car_model = model_name;
        car_type = typeOfCar;
        price = carFare;
    }


    // setter for public members to add fuel details
    void addFuelInfo(string fuel, float capacity){
        fuel_type = fuel;
        fuel_capacity = capacity;
    }


    void startCar(){
        cout << engine_type << " Engine started!\n";
        cout << car_brand << "'s " << car_model << " model Car Started!\n";
    }


    void accelerate(){
        float speed;
        speed += 10;
        cout << "Speed increased to " << speed << "km/h" << endl;
        fuel_capacity--;
    }
   
    void applyBrake(){
        float speed;
        if(speed >= 10){
            speed -= 5;
        }
        cout << "Speed decreased to " << speed << "km/h" << endl;
    }
   
    void fuelInfo(){
        if(fuel_type == "EV"){
            cout << "Current Fuel Level: " << fuel_capacity << "% Battery Left!";
        } else {
            cout << "Current Fuel Level: " << fuel_capacity << "L Fuel Left!" << endl;
        }
    }
   
    void calculateMileage(float distance_travelled, float fuel_used){
        mileage = distance_travelled / fuel_used;
        cout << "Estimated Mileage: " << mileage << "km/" << (fuel_type == "EV" ? "kWh" : "L") << endl;
       
        float estimated_distance;
        estimated_distance = mileage * fuel_capacity;
        cout << "Estimated Distance covered with fuel: " << estimated_distance << " km";
    }
   
    void parkCar() {
        cout << car_model << " Car Parked Successfully\n";
    }
   
    void showCarInfo(){
        cout << "Car Details are as follows:\n";
        cout << "Car Brand: " << car_brand << "\nCar Model: " << car_model << "\nCar Type: " << car_type << "\nFuel Type: " << fuel_type << "\nFuel Capacity: " << fuel_capacity << "L \nPrice: Rs." << price << "L /- \n";
        getCarInfo();
    }
};


int main(){
    // First Car/Object
    Car car1;
    car1.addCarInfo("Tata", "Curvv", "SUV", 19.1);
    car1.setCarDetails("CUR123", "1199 cc 120PS 5500rpm");
    car1.addFuelInfo("Petrol", 25.3);
    car1.showCarInfo();
    car1.startCar();
   
    // Alternatively accelerate and apply brake
    for(int i=0; i<5; i++){
        if(i % 2 == 0){
            car1.accelerate();
            car1.accelerate();
            car1.fuelInfo();
        } else {
            car1.applyBrake();
        }
    }
   
    car1.parkCar();
    car1.calculateMileage(100, 5);


    cout << endl << endl;
    // Second Car/Object
    Car car2;
    car2.addCarInfo("Tata", "Curvv EV", "SUV", 22.2);
    car2.setCarDetails("CUREV125", "1250 cc 120PS 5500rpm");
    car2.addFuelInfo("EV", 85.2);
    car2.showCarInfo();
    car2.startCar();
   
    // Alternatively accelerate and apply brake
    for(int i=0; i<5; i++){
        if(i % 2 == 0){
            car2.accelerate();
            car2.accelerate();
            car2.accelerate();
            car2.fuelInfo();
        } else {
            car2.applyBrake();
        }
    }


    car2.parkCar();
    car2.calculateMileage(155.25, 6.25);
}


