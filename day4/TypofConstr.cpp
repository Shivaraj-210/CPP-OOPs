#include <iostream>
#include <string>
using namespace std;
class Library
{
private:
 // Shared by all members
 static string books[50];
 static int copies[50];
 static int totalBooks;
 static int memberCount;
 // Individual member details
 string member_id;
 string books_borrowed[10];
 int no_of_books_borrowed;
public:
 string name;
 string email;
 string phone;
 string address;
 // Constructor
 Library()
 {
 member_id = "LIB-000";
 name = "N/A";
 email = "N/A";
 phone = "N/A";
 address = "N/A";
 no_of_books_borrowed = 0;
 }
 // Create Membership
 void newMembership(string memberName,
 string memberEmail,
string memberPhone,
string memberAddress)
 {
 memberCount++;
 if (memberCount < 10)
 member_id = "LIB-00" + to_string(memberCount);
 else if (memberCount < 100)
 member_id = "LIB-0" + to_string(memberCount);
 else
 member_id = "LIB-" + to_string(memberCount);
 name = memberName;
 email = memberEmail;
 phone = memberPhone;
 address = memberAddress;
 cout << "\nMembership Created Successfully!\n";
 cout << "-------------------------------\n";
 cout << "Member ID : " << member_id << endl;
 cout << "Name : " << name << endl;
 cout << "Email : " << email << endl;
 cout << "Phone : " << phone << endl;
 cout << "Address : " << address << endl;
 }
 string getMemberId()
 {
 return member_id;
 }
 // Add Book (Shared Library)
 static void addBook(string book, int noOfCopies)
 {
 books[totalBooks] = book;
 copies[totalBooks] = noOfCopies;
 totalBooks++;
 cout << book << " added successfully.\n";
 }
 // List Books
 static void listBooks()
 {
 cout << "\nAvailable Books\n";
 cout << "------------------------\n";
 if (totalBooks == 0)
 {
 cout << "No books available.\n";
 return;
 }
 for (int i = 0; i < totalBooks; i++)
 {
 cout << i + 1 << ". "
 << books[i]
 << " (Copies: "
 << copies[i]
 << ")\n";
 }
 }
 // Borrow Book
 void borrowBook(string book)
 {
 for (int i = 0; i < totalBooks; i++)
 {
 if (books[i] == book)
 {
 if (copies[i] > 0)
 {
 copies[i]--;
 books_borrowed[no_of_books_borrowed++] = book;
 cout << book << " borrowed successfully.\n";
 return;
 }
 else
 {
 cout << "No copies available.\n";
 return;
 }
 }
 }
 cout << "Book not found.\n";
 }
 // Return Book
 void returnBook(string book)
 {
 bool found = false;
 for (int i = 0; i < no_of_books_borrowed; i++)
 {
 if (books_borrowed[i] == book)
 {
 for (int j = i; j < no_of_books_borrowed - 1; j++)
 {
 books_borrowed[j] = books_borrowed[j + 1];
 }
 no_of_books_borrowed--;
 found = true;
 break;
 }
 }
 if (!found)
 {
 cout << "Book not borrowed by this member.\n";
 return;
 }
 for (int i = 0; i < totalBooks; i++)
 {
 if (books[i] == book)
 {
 copies[i]++;
 break;
 }
 }
 cout << book << " returned successfully.\n";
 }
 // Show Borrowed Books
 void showBorrowedBooks()
 {
 cout << "\nBorrowed Books by " << name << endl;
 cout << "------------------------\n";
 if (no_of_books_borrowed == 0)
 {
 cout << "No books borrowed.\n";
 return;
 }
 for (int i = 0; i < no_of_books_borrowed; i++)
 {
 cout << i + 1 << ". " << books_borrowed[i] << endl;
 }
 }
 // Display Member Information
 void displayMemberInfo()
 {
 cout << "\nMember Details\n";
 cout << "------------------------\n";
 cout << "Member ID : " << member_id << endl;
 cout << "Name : " << name << endl;
 cout << "Email : " << email << endl;
 cout << "Phone : " << phone << endl;
 cout << "Address : " << address << endl;
 cout << "Books Borrowed : " << no_of_books_borrowed << endl;
 }
};
// Static Variable Definitions
int Library::memberCount = 0;
string Library::books[50];
int Library::copies[50];
int Library::totalBooks = 0;
int main()
{
 // Add books once to the library
 Library::addBook("C Programming", 5);
 Library::addBook("C++ Programming", 4);
 Library::addBook("Java Programming", 3);
 Library::addBook("Python Programming", 2);
 // Member 1
 Library member1;
 member1.newMembership(
 "Shiva",
 "shivarajuppin61@gmail.com",
 "9110298670",
 "Bengaluru");
 // Member 2
 Library member2;
 member2.newMembership(
 "Shiva",
 "shiva@gmail.com",
 "8956525845",
 "Tumakuru");
 cout << "\nInitial Library Books:";
 Library::listBooks();
 // Borrow Books
 member1.borrowBook("C Programming");
 member1.borrowBook("Java Programming");
 member2.borrowBook("Python Programming");
 member1.showBorrowedBooks();
 member2.showBorrowedBooks();
 cout << "\nAfter Borrowing:";
 Library::listBooks();
 // Return Book
 member1.returnBook("Java Programming");
 cout << "\nAfter Returning:";
 Library::listBooks();
 member1.displayMemberInfo();
 member2.displayMemberInfo();
}