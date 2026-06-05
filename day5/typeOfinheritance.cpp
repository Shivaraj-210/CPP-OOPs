#include<iostream>
#include<string>
using namespace std;


// Single Inheritance
// Base Class
class Animal{
    public:
        string type;
        string habitat;


    void setAnimalDetails(){
        cout << "Enter the type of Animal (Domestic/Wild): ";
        cin >> type;
        cout << "Enter the habitat (Land/Water/Aerial): ";
        cin >> habitat;
    }


    void getAnimalDetails() {
        cout << "This animal is a " << type << " Animal\n";
        cout << "It lives in " << habitat << endl;
    }
};


// Inherited Class
// Animal -> Dog
class Dog : public Animal{
    public:
    string name;
    string breed;


    void setDogDetails(){
        cout << "Enter the name of the dog: ";
        cin >> name;
        cout << "Enter the breed of the dog: ";
        cin >> breed;
    }


    void getDogDetails() {
        cout << "The name of the dog is " << name << endl;
        cout << "It belongs to the " << breed << " breed.\n";
    }
};


// Multiple Inheritance
// Animal -> Tiger
class Tiger : public Animal{
    public:
    string foodType;
    string prey;


    void setTigerDetails(){
        cout << "Enter the type of Food (Herbivorous/Carnivorous/Omnivorous): ";
        cin >> foodType;
        cout << "Enter the prey: ";
        cin >> prey;
    }


    void getTigerDetails(){
        cout << "The Animal is a kind of " << foodType << " Animal.\n";
        cout << "It hunts " << prey << " as a prey for food.\n";
    }
} ;


int main() {
    // Derived Class Dog can access the properties of Base Class Animal, so the object of Dog class can invoke all 4 methods of both classes
    // Single Inheritance
    Dog d;
    d.setAnimalDetails();
    d.setDogDetails();
    d.getDogDetails();
    d.getAnimalDetails();


    // Extended to Multiple Inheritance
    Tiger t;
    t.setAnimalDetails();
    t.setTigerDetails();
    t.getAnimalDetails();
    t.getTigerDetails();
}



