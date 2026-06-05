// polymorphism - Poly +morphism
// Poly means many and morphism means forms. So, polymorphism means many forms.
//Type of Polymorphism:
// 1. Compile-time Polymorphism (Function Overloading)
//  a) Function Overloading
//  b) Operator Overloading
// 2. Runtime Polymorphism (Function Overriding)    
//  a) Function Overriding
//  b) Virtual Functions

#include<iostream>
#include<string>
using namespace std;

class printing{
    public:
    void print(int num){
        cout << "Printing a number : " << num << endl;
    }

    void print(float decimal){
        cout << "Printing a decimal number: " << decimal << endl;
    }

    void print(char c){
        cout << "Printing a character: " << c << endl;
    }

    void print(string name){
        cout << "Printing a string(name): " << name << endl;
    }
    void print(string document,int copies){
        cout << "Printing : " << copies << " of " << document << " document .\n";
    }
};

class salary{
    public:
    int salary;
    void calculate(int basic){
        salary = basic;
        cout << "Basic Salary: " << salary << "/-\n";
}

void calculate(int basic, int bonus){
        salary = basic + bonus;
        cout << "Salary With Bonus: " << salary << "/-\n";}

void calculate(int basic, int bonus, int allowance){
        salary = basic + bonus +allowance;
        cout << "Salary With Bonus and Allowance: " << salary << "/-\n";
    }

    void calculate(int hourlyrate,float hours){
        salary = hourlyrate * hours;
        cout << "Salary based on hourly rate: " << salary << "/-\n";}
};

int main() 
{
    printing p;
    p.print(5);
    p.print(5.5f);
    p.print('A');
    p.print("Shiva");
    p.print("Aadhar", 5);

    salary s;
    s.calculate(50000);
    s.calculate(50000, 10000);
    s.calculate(50000, 10000, 5000);
    s.calculate(100, 82.5f);

}