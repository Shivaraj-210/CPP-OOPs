// Abstract Class Example for Payment Modes
#include <iostream>
#include <string>
using namespace std;


// Base Class / Abstract Class
class PaymentMode
{
protected:
    double amount;
    string mode;


public:
    void enquireAmount()
    {
        cout << "Enter the amount to be paid: ";
        cin >> amount;
    }


    // Pure Virtual Function
    virtual void pay() = 0;
};


class UPI : public PaymentMode
{
public:
    void pay() override
    {
        int pin;
        mode = "UPI";
        enquireAmount();
        cout << "Enter the 4 digit UPI Pin:";
        cin >> pin;
        if (pin == 1234)
        {
            cout << "Successfully Paid Rs." << amount << "/- via " << mode << " mode.\n";
        }
        else
        {
            cout << "Something went wrong! Please try again later.\n";
        }
    }
};


class NetBanking : public PaymentMode
{
public:
    void pay() override
    {
        int user_id;
        string password;
        mode = "Net Banking";
        enquireAmount();
        cout << "Enter your User ID:";
        cin >> user_id;
        cout << "Enter your Password:";
        cin >> password;
        if (user_id == 1234 && password == "pass1234")
        {
            cout << "Account Verified Successfully!\n";
            cout << "Successfully Paid Rs." << amount << "/- via " << mode << " mode.\n";
        }
        else
        {
            cout << "Something went wrong! Please try again later.\n";
        }
    }
};


class CardPayment : public PaymentMode
{


public:
    void pay() override
    {
        int cvv;
        string expiryDate;
        int transactionPin;
        mode = "Card Payment";
        enquireAmount();
        cout << "Enter your 3 digits CVV number:";
        cin >> cvv;
        cout << "Enter your Card Expiry Date:";
        cin >> expiryDate;
        if (cvv == 123 && expiryDate == "31-12-2026")
        {
            cout << "Card Added Successfully!\n";
            cout << "Enter 4 digit Transaction Pin: ";
            cin >> transactionPin;
            if (transactionPin == 1234)
            {
                cout << "Pin Verified Successfully\n";
                cout << "Successfully Paid Rs." << amount << "/- via " << mode << " mode.\n";
            }
            else
            {
                cout << "Wrong Pin! Please try again later.\n";
            }
        }
        else
        {
            cout << "Something went wrong! Please try again later.\n";
        }
    }
};


int main()
{
    UPI qr;
    NetBanking digital;
    CardPayment card;


    qr.pay();
    digital.pay();
    card.pay();
}



// payment use case