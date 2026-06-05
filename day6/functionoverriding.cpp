 #include <iostream>
#include <string>
using namespace std;


// Run-time Polymorphism
// Function Overriding
// Base Class
class Bird
{
public:
    void fly()
    {
        cout << "The bird flies in the sky!\n";
    }
};


// Derived Class
// Bird -> Eagle
class Eagle : public Bird
{
public:
    void fly()
    {
        cout << "The Eagle flies high in the sky at an average speed of 50-80 km per hour!\n";
    }
};


// Example 2
// Base Class
class Animal
{
public:
    void makeSound()
    {
        cout << "Animal makes some sound!\n";
    }
};


// Derived Class
// Animal -> Lion
class Lion : public Animal
{
public:
    void makeSound()
    {
        cout << "Lion roars in the Jungle!\n";
    }
};


int main()
{
    // First Example
    Eagle e;
    Bird* b;
   
    b = &e;
    b->fly();
   
    e.fly();
   
    // Second Example
    Animal* a;
    Lion l;
   
    a = &l;
    a->makeSound();


    l.makeSound();
}


