#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main()
{
    int numOfStudents;


    cout << "Enter the number of students: ";
    cin >> numOfStudents;


    string* students = new string[numOfStudents];


    for (int i = 0; i < numOfStudents; i++)
    {
        cout << "Enter the name of Student "
             << (i + 1) << ": ";


        cin >> students[i];
    }


    ofstream file("student-details.txt");


    file << "The details of "
         << numOfStudents
         << " students are as follows:\n";


    for (int i = 0; i < numOfStudents; i++)
    {
        file << (i + 1)
             << ". "
             << students[i]
             << endl;
    }


    file.close();
    cout << "Successfully saved the Student Details in the text file.\n";


    delete[] students;


 }