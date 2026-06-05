#include <iostream>
#include <string>
using namespace std;
// Function based approach
void intSum(int a, int b)
{
    int sum = a + b;
    cout << "Sum of " << a << " and " << b << ": " << sum << endl;
}
void floatSum(float a, float b)
{
    float sum = a + b;
    cout << "Sum of " << a << " and " << b << ": " << sum << endl;
}


// Templates are used for reusability of the code for making generic functions suitable for all kind of data.
// Syntax:
// template <typename template_name>
template <typename T>
T add(T a, T b)
{
    T sum;
    sum = a + b;
    cout << "Sum of " << a << " and " << b << ": " << sum << endl;
}


template <typename T>
T compare(T a, T b)
{
    // Nested Ternary Operator
    (a == b)
    ? cout << "Both the values are equal: " << a << endl
    : (a > b)
    ? cout << a << " is max.\n"                      
    : cout << b << " is max.\n";
}


int main()
{
    intSum(25, 35);
    floatSum(23.45f, 26.55f);
    // Integer
    add(65, 35);
    // Float
    add(33.65f, 65.35f);
    // Double
    add(125.3456, 521.1234);
    // Long Int
    add(12345678L, 87654321L);


    // Comparision of Integers
    compare(30, 40);
    // Comparision of Float
    compare(30.23f, 30.23f);
    // Comparision of Double
    compare(40.235, 30.234);
}




