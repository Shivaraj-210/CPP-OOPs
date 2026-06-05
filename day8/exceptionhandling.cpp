#include <iostream>
#include <stdexcept>
using namespace std;


int main()
{
    int age;


    cout << "Enter your age: ";
    cin >> age;


    try
    {
        if (cin.fail())
        {
            throw runtime_error(
                "Age must be numeric!");
        }


        if (age < 0)
        {
            throw underflow_error(
                "Age cannot be negative!");
        }


        if (age == 0)
        {
            throw invalid_argument(
                "Age cannot be 0 years!");
        }


        if (age > 120)
        {
            throw overflow_error(
                "Age cannot be more than 120 years!");
        }


        if (age < 18)
        {
            throw out_of_range(
                "Voting age cannot be less than 18 years!");
        }


        cout << "Eligible for Voting!" << endl;
    }
    catch (const invalid_argument &e)
    {
        cout << e.what() << endl;
    }


    catch (const out_of_range &e)
    {
        cout << e.what() << endl;
    }


    catch (const underflow_error &e)
    {
        cout << e.what() << endl;
    }


    catch (const overflow_error &e)
    {
        cout << e.what() << endl;
    }


    catch (const runtime_error &e)
    {
        cout << e.what() << endl;
    }
}


