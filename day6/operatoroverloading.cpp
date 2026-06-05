#include <iostream>
#include <string>
using namespace std;


class Marks
{
private:
    int marks;


public:
    // Constructor
    Marks(int score){
        marks = score;
    }


    // Operator Overloading for "+" operator
    Marks operator +(Marks m){
        return Marks(marks + m.marks);
    }
   
    // Operator Overloading for ">" operator
    bool operator >(Marks m){
        return marks > m.marks;
    }
   
    // Operator Overloading for "==" operator
    bool operator ==(Marks m){
        return marks == m.marks;
    }


    int showMarks(){
        return marks;
    }
};


int main(){
    // 2 objects of Marks class
    Marks m1(85);
    Marks m2(85);


    // Adding 2 objects
    Marks total = m1 + m2;
   
    cout << "Total Marks scored by the student: " << total.showMarks() << endl;
   
    // Comparing 2 objects for Equality
    if(m1 == m2) {
        cout << "Student has scored equal marks in both subjects:\n" << m1.showMarks() << endl;
    } else if(m1 > m2) {
        cout << "Student has scored more marks in first subject:\n" << m1.showMarks() << endl;
    } else {
        cout << "Student has scored more marks in second subject:\n" << m2.showMarks() << endl;
    }
}
 


 