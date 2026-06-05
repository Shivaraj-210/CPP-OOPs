// DMA - Dynamic Memory Allocation
// Allocating memory during run-time


// new keyword is used to allocate memory
// delete keyword is used to deallocate or remove the memory
#include <iostream>
#include <string>
using namespace std;


class Student
{
public:
    string firstName;
    string lastName;
    string usn;


    void setData()
    {
        string fName, lName, USN;
        cout << "Enter the first name: ";
        cin >> fName;
        cout << "Enter the last name: ";
        cin >> lName;
        cout << "Enter the USN: ";
        cin >> USN;
        firstName = fName;
        lastName = lName;
        usn = USN;
    }


    void getData() {
        cout << "Student Details are as follows: " << endl;
        cout << "Name: " << firstName << " " << lastName << endl;
        cout << "USN: " << usn << endl;
    }
};


int main()
{
    // DMA Syntax: datatype* pointer = new datatype
    int *salary = new int;


    cout << "Enter the Salary of the Employee: ";
    cin >> *salary;
    cout << "Salary: " << *salary << endl;


    // Clearing or Freeing up the Allocated Memory using delete keyword
    // Syntax: delete pointer
    delete salary;


    // Pointer to Array - DMA
    int noOfStudents;


    cout << "Enter the Number of Students: ";
    cin >> noOfStudents;


    int* marks = new int[noOfStudents];


    cout << "Enter the marks for " << noOfStudents << " Students: " << endl;
    for (int i = 0; i < noOfStudents; i++)
    {
        cout << (i + 1) << ". ";
        cin >> marks[i];
    }


    cout << "The Marks of " << noOfStudents << " Students are as follows: " << endl;
    for (int i = 0; i < noOfStudents; i++)
    {
        cout << "Student " << (i + 1) << " Marks: " << marks[i] << endl;
    }


    delete marks;


    // DMA (Pointer to Objects)
    // class* object = new class;
    Student* std1 = new Student;


    // For normal objects we use Dot(.) operator to access the data members and member functions but for Pointer object we need to use Arrow(->) operator for the same operation
    std1->setData();
    std1->getData();


    delete std1;


    // Pointer to Array  Object
    Student* students = new Student[noOfStudents];


    cout << "Enter the details of " << noOfStudents << " Students: " << endl;


    for(int i = 0; i < noOfStudents; i++){
        students[i].setData();
    }


    cout << "The details of " << noOfStudents << " Students are as follows: " << endl;


    for(int i = 0; i < noOfStudents; i++){
        students[i].getData();
    }


    delete[] students;
}
