// Pointers are used to refer the address of another variable


// Syntax:
// datatype* variable


// Ex:
// int* ptr;


// *ptr = &variable
// We will assign or refer the address of another variable which is also called as Referencing a Pointer


// ptr contains the address of variable, whereas *ptr contains the value of variable


// *ptr is called as Dereferncing a Pointer


// Types of Pointers
// 1) Null Pointer
// 2) Void Pointer
// 3) Wild Pointer
// 4) Dangling Pointer


// Wild Pointer: Pointer not pointing to any of the variable


// Null Pointer: Pointer pointing to Null value to avoid the abnormal behavior of Wild Pointer


// Void Pointer: Pointer which can hold the address of any of the data type


// Dangling Pointer: Pointer referring to the address if the varible which is not available or memory has been freed out


#include<iostream>
using namespace std;


int main(){
    // Wild Pointer
    int* wildPtr;


    // Null Pointer
    // We can assign null pointer in 2 ways:
    // float* nPtr = nullptr;
    float* nullPtr = NULL;


    int num = 123;
    float decimal = 3.142;
    char section = 'A';


    // Void Pointer
    void* ptr;
    // Void Pointer pointing to integer variable
    ptr = &num;  // Void Pounter => Integer Pointer
    cout << "Void Pointer pointing to int (address): " << ptr << endl;
    cout << "Value stored at Void Pointer at int variable: " << *(static_cast<int*>(ptr)) << endl;
    // Typecasting should be made before deferencing the void pointer


    // Void Pointer pointing to float variable
    ptr = &decimal; // Void Pounter => Float Pointer
    cout << "Void Pointer pointing to float (address): " << ptr << endl;
    cout << "Value stored at Void Pointer at float variable: " << *(static_cast<float*>(ptr)) << endl;


    // Void Pointer pointing to char variable
    ptr = &section; // Void Pounter => Char Pointer
    cout << "Void Pointer pointing to char (address): " << ptr << endl;
    cout << "Value stored at Void Pointer at char variable: " << *(static_cast<char*>(ptr)) << endl;


    // Wild Pointer O/p
    cout << "Address stored at Wild Pointer(Garbage Value): " << wildPtr << endl;
    cout << "Value stored at Wild Pointer:" << *wildPtr << endl;
    cout << "Address stored at Null Pointer: " << nullPtr << endl;
    // Null Pointer does not contain any value so it won't show any output
    if (nullPtr == nullptr){
        cout << "No Value can be found at Null Pointer:" << endl;
    }


    // Dangling Pointer
    int* danglingPtr = new int(100);


    cout << "Before Dangling: Address stored at Dangling Pointer: " << danglingPtr << endl;
    cout << "Before Dangling: Value stored at the pointing address of Dangling Pointer: " << *danglingPtr << endl;


    // Memory has been cleared using delete keyword
    delete danglingPtr;


    cout << "After Dangling: Address stored at Dangling Pointer: " << danglingPtr << endl;
    cout << "After Dangling: Value stored at the pointing address of Dangling Pointer: " << *danglingPtr << endl;
}




