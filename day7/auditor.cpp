// Friend Function Example 2
#include<iostream>
#include<string>
#include <iomanip>
using namespace std;




class BankAccount{
private:
    string name;
    double balance;
    int taxSlab = 0;
    double taxAmount = 0.0;
public:
    // Parameterized Constructor
    BankAccount(string Name, double Balance){
        name = Name;
        balance = Balance;
    }




    // Friend Function
    friend void checkAccountDetails(BankAccount&);
    friend void findTaxSlab(BankAccount&);
    friend double calculateTax(BankAccount&);
    friend void totalTaxCollected(BankAccount&, BankAccount&, BankAccount&);
};




void checkAccountDetails(BankAccount& b){
    cout << "The A/C Details are as follows: \n";
    cout << "A/C Holder Name: " << b.name << endl;
    cout << "Bank Balance: Rs." << b.balance << endl;
}




double calculateTax(BankAccount& b){
    cout << "--------------------------------------------\n";
    b.taxAmount = (b.balance * b.taxSlab)/100.0;
    cout << "Customer's Tax Slab: " << b.taxSlab << "%" << endl;
    cout << "Tax Amount to be paid: Rs." << b.taxAmount << "/-\n";
    cout << "--------------------------------------------\n";
    return b.taxAmount;
}




void findTaxSlab(BankAccount& b){
    if(b.balance >= 400001 && b.balance <= 800000){
        b.taxSlab = 5;      
    } else if(b.balance >= 800001 && b.balance <= 1200000){
        b.taxSlab = 10;
    } else if(b.balance >= 1200001 && b.balance <= 1600000){
        b.taxSlab = 15;
    } else {
        b.taxSlab = 0;
    }
}




void totalTaxCollected(BankAccount& b1, BankAccount& b2, BankAccount& b3){
    double totalAmountAudited;
    double totalTaxAudited;
    totalAmountAudited = b1.balance + b2.balance + b3.balance;
    totalTaxAudited = b1.taxAmount + b2.taxAmount + b3.taxAmount;
    cout << "Total Amount Audited: Rs." << totalAmountAudited << "/-\n";
    cout << "Total Tax Amount Calculated: Rs." << totalTaxAudited << "/-\n";
}




int main(){
    cout << fixed << setprecision(2);
    BankAccount cust1("Akshay Rao", 435123);
    BankAccount cust2("Ajay Rao", 863478);
    BankAccount cust3("Abhay Rao", 1387123);




    // Auditing the Customer 1 A/C
    checkAccountDetails(cust1);
    findTaxSlab(cust1);
    calculateTax(cust1);
    // Auditing the Customer 2 A/C
    checkAccountDetails(cust2);
    findTaxSlab(cust2);
    calculateTax(cust2);
    // Auditing the Customer 3 A/C
    checkAccountDetails(cust3);
    findTaxSlab(cust3);
    calculateTax(cust3);




    // Final Auditing Report
    totalTaxCollected(cust1, cust2, cust3);
}
