#include<iostream>
#include<string.h>
using namespace std;
  
// Syntax:
// class ClassName{
// Data members;
// int a
// Member functions;
// void fun()
// };

// check the semicolon at the end of the class 
class Student{
    public:
    string name;
    string usn;
    string branch;
    char section;
    int marks1, marks2, marks3, marks4;
    int totalMarks;
    float percentage;

void printStudentInfo() {
        cout << "Student details as follows :\n";
        cout << "Name: " << name << endl;
        cout << "USN: " << usn << endl;
        cout << "Branch: " << branch << endl;
        cout << "Section: " << section << endl;
    }

void printMarksInfo() {
        cout << "Ypu Have Scored: \n";
        cout << "Marks in 4 subjects: " << marks1 << ", " << marks2 << ", " << marks3 << ", " << marks4 << endl;
    }
void printResults() {
        totalMarks  = marks1 + marks2 + marks3 + marks4;
        percentage = (totalMarks / 400.0) * 100; // Assuming each subject is out of 100 marks
        cout << "Your Results are as follows :\n";
        cout << "Total Marks: " << totalMarks << endl;
        cout << "Percentage: " << percentage << "%" << endl;
    }

};

int main() {
    Student s1;
    s1.name = "Shiva";
    s1.usn = "1CE25CS154";
    s1.branch = "Computer Science & Engineering";
    s1.section = 'C';
    s1.marks1 = 85;
    s1.marks2 = 90;
    s1.marks3 = 78;
    s1.marks4 = 92;

    s1.printStudentInfo();
    s1.printMarksInfo();
    s1.printResults();

    return 0;
}