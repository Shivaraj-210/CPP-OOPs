#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main(){
    
    string sentence;
    ifstream file ("demo.txt");
    getline(file, sentence);
    cout << "File contains: "<< sentence << endl;

}