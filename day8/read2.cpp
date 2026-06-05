#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main()
{
    string studentRecords;


    ifstream file("student-details.txt");


    cout << "The students records in the file are as follows:\n";
    while(file >> studentRecords){
        cout << studentRecords << " ";
    }


    file.close();
}




