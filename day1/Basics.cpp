# include <iostream>
#include <string.h>

using namespace std;

int main(){
    string name;
    int age;
    string branch;
    int sem;
    char section;
    cout<<"Enter your name: ";
    cin>>name;
    cout<<"Enter your age: ";
    cin>>age;
    cout<<"Enter your academic details: \n";
    cout<<" Enter your Branch,sem and section: ";
    cin>>branch>>sem>>section;
    cout<<" Enter Your details as follows  \n";
    cout<<"\n Name: "<<name
        <<"\n Age: "<<age
        <<"\n Branch: "<<branch
        <<"\n Semester: "<<sem
        <<"\n Section: "<<section;
    
}