#include <iostream>
#include <string>
#include <random>

using namespace std;

class BankAccount {
private:
    int ac_number;
    float balance;

public:
    string name;
    string email_id;
    long phone;
    string bank;
    string branch;

    // Constructor
    BankAccount() {
        balance = 0;
    }

    void createAccount(string custname, string email, long mobile) {

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(111111, 999999);

        ac_number = dist(gen);

        name = custname;
        email_id = email;
        phone = mobile;

        bank = "SBI";
        branch = "Bangalore";

        cout << "Thank You for creating an account in "
             << bank << " at " << branch << " branch.\n";

        cout << "\nYour Account Details are:\n";

        cout << "Account Number: " << ac_number << endl;
        cout << "Name: " << name << endl;
        cout << "Email ID: " << email_id << endl;
        cout << "Phone: " << phone << endl;
    }

    bool askAccountDetails() {

        int acNum;
        string pass;

        cout << "\nEnter your Account Number: ";
        cin >> acNum;

        cout << "Enter your Password: ";
        cin >> pass;

        if (acNum == ac_number && pass == "password123") {

            cout << "Login successful! Welcome, "
                 << name << ".\n";

            return true;
        }
        else {

            cout << "Invalid Account Number or Password.\n";
            return false;
        }
    }

    void deposit() {

        float amount;

        if (askAccountDetails()) {

            cout << "Enter amount to deposit: ";
            cin >> amount;

            balance += amount;

            cout << "Deposit successful!\n";
            cout << "Current Balance: " << balance << endl;
        }
        else {

            cout << "Deposit failed.\n";
        }
    }

    void withdraw() {

        float amount;

        if (askAccountDetails()) {

            cout << "Enter amount to withdraw: ";
            cin >> amount;

            if (amount > balance) {

                cout << "Insufficient balance.\n";
            }
            else {     

                balance -= amount;

                cout << "Withdrawal successful!\n";
                cout << "Current Balance: "
                     << balance << endl;
            }
        }
        else {

            cout << "Withdrawal failed.\n";
        }
    }       

    void checkBalance() {

        if (askAccountDetails()) {

            cout << "Current Balance: "
                 << balance << endl;
        }
        else {

            cout << "Unable to retrieve balance.\n";
        }
    }
};

int main() {

    BankAccount account1;

    account1.createAccount(
        "Shiva",
        "shiva@example.com",
        1234567890
    );

    account1.deposit();
    account1.withdraw();
    account1.checkBalance();

    return 0;
}