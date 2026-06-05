#include <iostream>
#include <string>
using namespace std;

class Consumer
{
private:
    int consumerID;
    string consumerName;
    int unitsConsumed;
    double billAmount;

public:
    // Function to input details
    void getDetails()
    {
        cout << "Enter Consumer ID: ";
        cin >> consumerID;

        cin.ignore();
        cout << "Enter Consumer Name: ";
        getline(cin, consumerName);

        cout << "Enter Units Consumed: ";
        cin >> unitsConsumed;
    }

    // Function to calculate bill
    void calculateBill()
    {
        if (unitsConsumed <= 100)
        {
            billAmount = unitsConsumed * 5;
        }
        else if (unitsConsumed <= 200)
        {
            billAmount = (100 * 5) +
                         ((unitsConsumed - 100) * 7);
        }
        else
        {
            billAmount = (100 * 5) +
                         (100 * 7) +
                         ((unitsConsumed - 200) * 10);
        }
    }

    // Function to display details
    void displayDetails()
    {
        cout << "\n--- Consumer Details ---" << endl;
        cout << "Consumer ID: " << consumerID << endl;
        cout << "Consumer Name: " << consumerName << endl;
        cout << "Units Consumed: " << unitsConsumed << endl;
        cout << "Total Bill Amount: Rs. " << billAmount << endl;
    }
};

int main()
{
    Consumer c;

    c.getDetails();
    c.calculateBill();
    c.displayDetails();

    return 0;
} 