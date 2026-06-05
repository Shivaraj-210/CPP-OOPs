#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Passenger
{
public:
    string name;
    int age;

    Passenger(string n = "", int a = 0)
    {
        name = n;
        age = a;
    }
};

class Train
{
public:
    int totalSeats;
    int bookedSeats;
    double fare;

    Train(int seats = 5, double f = 500)
    {
        totalSeats = seats;
        bookedSeats = 0;
        fare = f;
    }

    bool seatAvailable()
    {
        return bookedSeats < totalSeats;
    }

    int bookSeat()
    {
        bookedSeats++;
        return bookedSeats;
    }

    void cancelSeat()
    {
        if(bookedSeats > 0)
            bookedSeats--;
    }
};

class Ticket
{
public:
    int pnr;
    Passenger passenger;
    int seatNo;
    string status;
    double fare;

    Ticket(int p, Passenger pass, int s,
           string st, double f)
    {
        pnr = p;
        passenger = pass;
        seatNo = s;
        status = st;
        fare = f;
    }

    void display()
    {
        cout << "\nPNR Number : " << pnr;
        cout << "\nPassenger : " << passenger.name;
        cout << "\nAge : " << passenger.age;

        if(seatNo == -1)
            cout << "\nSeat : Waiting List";
        else
            cout << "\nSeat No : " << seatNo;

        cout << "\nFare : Rs." << fare;
        cout << "\nStatus : " << status << endl;
    }
};

class ReservationSystem
{
private:
    Train train;
    vector<Ticket> tickets;
    int pnrCounter;

public:
    ReservationSystem()
    {
        train = Train(3, 500);
        pnrCounter = 1000;
    }

    void bookTicket()
    {
        string name;
        int age;

        cout << "\nEnter Name : ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Age : ";
        cin >> age;

        Passenger p(name, age);

        int seat = -1;
        string status;

        if(train.seatAvailable())
        {
            seat = train.bookSeat();
            status = "Confirmed";
        }
        else
        {
            status = "Waiting";
        }

        Ticket t(++pnrCounter, p,
                 seat, status,
                 train.fare);

        tickets.push_back(t);

        cout << "\nTicket Booked Successfully\n";
        t.display();
    }

    void cancelTicket()
    {
        int pnr;
        cout << "\nEnter PNR : ";
        cin >> pnr;

        for(int i=0;i<tickets.size();i++)
        {
            if(tickets[i].pnr == pnr)
            {
                if(tickets[i].status=="Confirmed")
                    train.cancelSeat();

                tickets.erase(tickets.begin()+i);

                cout << "Ticket Cancelled\n";
                return;
            }
        }

        cout << "PNR Not Found\n";
    }

    void displayTickets()
    {
        if(tickets.empty())
        {
            cout << "\nNo Reservations\n";
            return;
        }

        for(auto t : tickets)
            t.display();
    }

    void menu()
    {
        int choice;

        do
        {
            cout << "\n===== Railway Reservation System =====";
            cout << "\n1. Book Ticket";
            cout << "\n2. Cancel Ticket";
            cout << "\n3. View Tickets";
            cout << "\n4. Exit";
            cout << "\nEnter Choice : ";
            cin >> choice;

            switch(choice)
            {
                case 1:
                    bookTicket();
                    break;

                case 2:
                    cancelTicket();
                    break;

                case 3:
                    displayTickets();
                    break;

                case 4:
                    cout << "Thank You\n";
                    break;

                default:
                    cout << "Invalid Choice\n";
            }

        } while(choice != 4);
    }
};

int main()
{
    ReservationSystem rs;
    rs.menu();

    return 0;
}          