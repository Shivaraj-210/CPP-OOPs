#include <iostream>
#include <string>
using namespace std;

class Computer
{
private:
    string ip_address;
    string license = "ABCD-1234-EFGH-5678";
    bool isActive = false;

public:
    string processor;
    int ram;
    int storage;
    string os;

    // Constructor
    Computer()
    {
        ip_address = "N/A";
        processor = "N/A";
        ram = 0;
        storage = 0;
        os = "N/A";
        cout << endl;
    }

    void activateLicense()
    {
        string license_number;
        int attempts = 3;
        while (attempts > 0 && !isActive)
        {
            cout << "Enter the Windows License Key to activate:";
            cin >> license_number;
            if (license == license_number)
            {
                cout << "Windows License Activated!" << endl;
                isActive = true;
            }
            else
            {
                attempts--;
                if (attempts > 0)
                {
                    cout << "Invalid Credentials! " << attempts << " attempts remaining." << endl;
                }
                else
                {
                    cout << "Invalid Credentials!" << endl;
                }
            }
        }
    }

    void setComputeDetails(string chipset, int RAM, int space, string OS)
    {
        processor = chipset;
        ram = RAM;
        storage = space;
        os = OS;
    }

    void turnOn()
    {
        cout << "Windows is Turning On...!" << endl;
        cout << "Welcome to " << os << endl;
    } 

    void getSystemSpecs()
    {
        cout << "System Specifications are as follows: " << endl;
        cout << "Processor: " << processor << endl;
        cout << "RAM: " << ram << "gb RAM" << endl;
        cout << "Storage: " << storage << "gb SSD" << endl;
        cout << "OS: " << os << endl;
        cout << "Is License Key Activated? " << (isActive ? "True" : "False") << endl;
    }

    void turnOff();

    // Destructor
    ~Computer()
    {
        cout << "Destructor has been called!" << endl;
        cout << "Allocated Memory has been cleared!" << endl;
    }
};

// Scope Resolution Operator (::)
void Computer::turnOff()
{
    cout << "Windows is Shutting Down...!" << endl;
    cout << "Thank You! Have a Good Day." << endl;
}

int main()
{
    // comp1 - 1st Object of Computer class
    Computer comp1;

    comp1.turnOn();
    comp1.getSystemSpecs();
    comp1.turnOff();

    // comp2 - 2nd Object of Computer class
    Computer comp2;

    comp2.setComputeDetails("i5 10th Gen", 8, 512, "Windows 10 Pro");
    comp2.turnOn();
    comp2.activateLicense();
    comp2.getSystemSpecs();
    comp2.turnOff();
}
