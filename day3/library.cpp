#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    int bookID;
    string bookName;
    string authorName;
    float price;

public:
    // Function to get book details
    void inputBook()
    {
        cout << "Enter Book ID: ";
        cin >> bookID;
        cin.ignore();

        cout << "Enter Book Name: ";
        getline(cin, bookName);

        cout << "Enter Author Name: ";
        getline(cin, authorName);

        cout << "Enter Price: ";
        cin >> price;
    }

    // Function to display book details
    void displayBook()
    {
        cout << "\nBook Details\n";
        cout << "Book ID     : " << bookID << endl;
        cout << "Book Name   : " << bookName << endl;
        cout << "Author Name : " << authorName << endl;
        cout << "Price       : " << price << endl;
    }
};

int main()
{
    Book b;

    b.inputBook();
    b.displayBook();

    return 0;
}