#include<iostream>
#include<string>
using namespace std;


// Base Class - Level 1
class Device{
    public:
    string type;


    void deviceType(string type){
       this->type = type;
       cout << "This is an " << type << " Device.\n";
    }
};


// Derived Class - Level 2 (Base Class for Level 3)
class Telephone : public Device{
    public:
        string purpose;


    void toCommunicate(string purpose){
        this->purpose = purpose;
        cout << "It is used for " << purpose << " with others.\n";
    }
};


// Derived Class - Level 3
class Smartphone : public Telephone{
    public:
    string applications[5];


    void toUtilize(){
        cout << "Enter any 5 features of Smartphone: \n";
        for(int i = 0; i < 5 ; i++){
            cout << "Enter Feature " << (i + 1) << ":";
            cin >> applications[i];
        }
        cout << "Smartphone is used for multiple applications such as:\n";
        for(int i = 0; i < 5; i++){
            cout << "Feature " << (i + 1) << ": " << applications[i] << endl;
        }
    }
};


int main(){
    // s is an object of Smartphone class which is derived from Telephone class and that was derived from Device class, so it can access the methods of all 3 classes
    Smartphone s;
    s.deviceType("Electronic");
    s.toCommunicate("Communicating");
    s.toUtilize();
}
 