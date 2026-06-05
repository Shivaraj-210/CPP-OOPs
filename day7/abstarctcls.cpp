#include <iostream>
#include <string>
using namespace std;


// Abstract class is a class that contains 1 or more pure virtual functions


// Pure Virtual functions is used to initiate the Base Class function to 0, so that we can forcefully implement the specific functionality in Derived Class function


// Base Class
class EmployeeSalary
{
    // Access Modifier - Protected
protected:
    float hoursWorked;
    int salary;


public:
    void enquireWorkingHours()
    {
        cout << "Enter the no. of working hours: ";
        cin >> hoursWorked;
    }


    // Pure Virtual Function
    virtual void calculateSalary() = 0;
};


class HRSalary : public EmployeeSalary
{
public:
    void calculateSalary() override
    {
        salary = 1500 * hoursWorked;
        cout << "HR Salary for " << hoursWorked << " hours of work is Rs." << salary << "/-\n";
    }
};


class DevSalary : public EmployeeSalary
{
public:
    void calculateSalary() override
    {
        salary = 1250 * hoursWorked;
        cout << "Developer Salary for " << hoursWorked << " hours of work is Rs." << salary << "/-\n";
    }
};


class QASalary : public EmployeeSalary
{
public:
    void calculateSalary() override
    {
        salary = 1000 * hoursWorked;
        cout << "Quality Analyst Salary for " << hoursWorked << " hours of work is Rs." << salary << "/-\n";
    }
};


int main(){
    // Object if Abstract class is not allowed
    // EmployeeSalary e;


    // Objects of Derived Classes
    HRSalary hr;
    DevSalary dev;
    QASalary qa;


    hr.enquireWorkingHours();
    hr.calculateSalary();
    dev.enquireWorkingHours();
    dev.calculateSalary();
    qa.enquireWorkingHours();
    qa.calculateSalary();
}

