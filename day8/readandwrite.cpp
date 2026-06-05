#include <iostream>
#include <fstream>
#include <string>


using namespace std;


int main()
{
    // Variable to store the fetched details
    string line;


    // Write Mode
    // file => outFile
    ofstream outFile("info.txt");


    if (!outFile)
    {
        cout << "Error creating file!" << endl;
        return 1;
    }


    // "file <<" => "outFile <<"
    outFile << "C++ is a powerful programming language.";


    // close the file
    outFile.close();


    // Read Mode
    // file => inFile
    ifstream inFile("info.txt");


    cout << "Content after writing:\n";


    // while (file >> line) is used for single line
    // while(getline(file, variable)) is used for multi-line
    while (getline(inFile, line))
    {
        cout << line << endl;
    }


    inFile.close();


    // Append Mode
    ofstream appendFile("info.txt", ios::app);


    appendFile << "\nC++ is used for system programming.";
    appendFile << "\nC++ is used in game development.";


    appendFile.close();


    // Read Updated Content
    ifstream finalRead("info.txt");


    cout << "\nUpdated Content:\n";


    while (getline(finalRead, line))
    {
        cout << line << endl;
    }


    finalRead.close();
}



