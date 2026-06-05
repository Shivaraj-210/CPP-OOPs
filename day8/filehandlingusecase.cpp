#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class StudentRecord
{
private:
    string name;
    string usn;
    int sem;
    int marks[5];
    int totalMarks = 0;
    double percentage = 0.0;


public:
    StudentRecord()
    {
        totalMarks = 0;
        percentage = 0.0;
    }
    void setStudentDetails()
    {
        cin.ignore();
        cout << "Enter the name of the student: ";
        getline(cin, name);
        cout << "Enter the USN: ";
        cin >> usn;
        cout << "Enter the Semester: ";
        cin >> sem;
    }


    void setMarksDetails()
    {
        cout << "Enter the marks for 5 subjects:\n";
        for (int i = 0; i < 5; i++)
        {
            cout << "Marks for Sub " << (i + 1) << ":";
            cin >> marks[i];
        }
    }


    void calculateResult()
    {
        for (int i = 0; i < 5; i++)
        {
            totalMarks = totalMarks + marks[i];
        }
        percentage = static_cast<double>(totalMarks) / 5;
    }


    void saveDetails()
    {
        ofstream file("students_report.txt", ios::app);


        file << "Student Report of " << name << " are as follows:\n";
        file << "--------------------------------------------\n";
        file << "Basic Details:\n";
        file << "--------------\n";
        file << "Name: " << name << endl;
        file << "USN: " << usn << endl;
        file << "Semester: " << sem << endl;
        file << "Academic Performance:\n";
        file << "---------------------\n";
        for (int i = 0; i < 5; i++)
        {
            file << "Subject " << (i + 1) << " Marks: " << marks[i] << endl;
        }
        file << "---------------------\n";
        file << "Total Marks Scored:" << totalMarks << endl;
        file << "Total Percentage:" << percentage << endl;
        file << "--------------------------------------------\n";
    }
};


int main()
{
    StudentRecord std1;
    std1.setStudentDetails();
    std1.setMarksDetails();
    std1.calculateResult();
    std1.saveDetails();
    StudentRecord std2;
    std2.setStudentDetails();
    std2.setMarksDetails();
    std2.calculateResult();
    std2.saveDetails();
}


