#include <iostream>
#include <string>
using namespace std;


// Inheritance is a property of sharing the features of Parent Class (Base Class) to Derived Class (Child Class)
// Base -> Derived
// Types of Inheritance:
// 1) Single - One Base & One Derived Class (Base -> Derived)
// 2) Hierarchical - Multiple Base & One Derived Class
// (Base1 -> Derived <-Base2)
// 3) Multi-level - Derived Class deriving another
// Derived Class (Parent1 -> Derived1 -> Derived2)
// 4) Multiple (Derived1 <- Base -> Derived2)
// 5) Hybrid (Combination of any 2 Inheritance)


// Single Inheritance
// Base Class
class Base
{
public:
    string bName;
    void setBaseName()
    {
        string parent;
        cout << "Enter your parent's name: ";
        cin >> parent;
        bName = parent;
    }


    void getBaseName()
    {
        cout << "Your parent's name is " << bName << endl;
    }
};


// Base -> Derived
class Derived : public Base
{
public:
    string dName;
    void setDerivedName()
    {  
        string child;
        cout << "Enter your name: ";
        cin >> child;
        dName = child;
    }


    void getDerivedName(){
        cout << "Your name is " << dName << endl;
    }
};


int main(){
    // Object of Base Class
    Base b;


    // Object of Derived Class
    Derived d;


    // Can access only Base Class methods
    b.setBaseName();
    b.getBaseName();
   
    // Can access both Base & Derived Class methods
    d.setDerivedName();
    d.setBaseName();
    d.getDerivedName();
    d.getBaseName();
}



