/*
Author: Yani Mei
Teacher: Mr. Noukhovitch
Class: ICS4U1-4A
Program: Flight Booking System Part 3
Purpose: The following program faciliates a flight booking system that  
allows users to input various commands. 
*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class FlightBooking
{
public:
    FlightBooking(int id, int capacity, int reserved);
    FlightBooking();
    void printStatus(vector<FlightBooking *> flight);
    int getId() { return this->id; }
    void addF(int id, int n, vector<FlightBooking *> &fligt);
    void cancelF(int id, int n, vector<FlightBooking *> &flight);
    void deleteF(vector<FlightBooking *> &flight, int id);

private:
    int id, capacity, reserved;
}; //...end FlightBooking class

FlightBooking::FlightBooking()
{
    int id = 0, reserved = 0, capacity = 0;
} //...end FlightBooking()

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
    // store the instance
    this->id = id;
    this->capacity = capacity;
    this->reserved = reserved;
} //...end FlightBooking

// function that prints flight status
void FlightBooking::printStatus(vector<FlightBooking *> flight)
{
    double percent = 0;
    for (int i = 0; i < flight.size(); i++)
    {
        // calculate reservation percentage
        percent = 100 * ((double)flight[i]->reserved / flight[i]->capacity);
        cout << "Flight " << flight[i]->id << " : " << flight[i]->reserved << "/" << flight[i]->capacity << " (" << fixed << setprecision(0) << percent << "%) seats reserved.\n";
    } //...end for
} //...end printStatus

// function that displays status based on flight ID
int chooseF(vector<FlightBooking *> flight, int id)
{
    // verify that ID exists
    for (int i = 0; i < flight.size(); i++)
    {
        if (flight[i]->getId() == id)
            return i;
    } //...end for

    // return -1 if ID does not exist
    return -1;
} //...end showF

// function that adds n reservations
void FlightBooking::addF(int id, int n, vector<FlightBooking *> &flight)
{
    int index = chooseF(flight, id);
    if (index != -1)
    {
        // accept or reject new seats based on current capacity
        if (((double)(flight[index]->reserved + n) / flight[index]->capacity) * 100 <= 105)
            flight[index]->reserved += n;
        else
            cout << "Cannot perform this operation: capacity reached\n";
    }
    // display error message if ID does not exist
    else
        cout << "Cannot perform this operation: flight " << id << " not found" << endl;
} //...end addF

// function that cancels n seats
void FlightBooking::cancelF(int id, int n, vector<FlightBooking *> &flight)
{
    int index = chooseF(flight, id);
    if (index != -1)
    {
        // if current seats > n, cancel n seats
        if (flight[index]->reserved - n >= 0)
            flight[index]->reserved -= n;
    }
    // display error message if ID does not exist
    else
        cout << "Cannot perform this operation: flight " << id << " not found" << endl;
} //...end cancelF

// function that deltes flights from the system
void FlightBooking::deleteF(vector<FlightBooking *> &flight, int id)
{
    int index = chooseF(flight, id);
    // delete flight if ID exists
    if (index != -1)
    {
        cout << "Flight " << id << " has been deleted.\n";
        flight.erase(flight.begin() + index);
        for (int i = index; i < flight.size(); ++i)
        {
            flight[i] = flight[i + 1];
            i--;
        } //...end for
    }
    // display error message if ID does not exist
    else
        cout << "Cannot perform this operation: flight " << id << " not found" << endl;

} //...end deleteF

int main()
{
    // accept up to 10 flights
    FlightBooking booking[10];
    vector<FlightBooking *> flight;

    // declare variables for function arguments
    int a, b, index, i = 0;
    string command = " ";

    // display commands
    cout << "----------------------------------------------------------\n"
            "Input your flight information with the following syntax: \n"
            "id = flight ID, cap = flight capacity, and n = # of seats\n"
            "\n(1) create[id][cap]\n(2) delete[id]\n(3) add[id][n]\n(4) cancel[id][n]\n"
            "----------------------------------------------------------\n";

    while (command != "quit")
    {
        // take user input
        cout << endl
             << "Please enter a command: ";
        getline(cin, command);

        // if command includes "create", create new flight
        if (command.find("create") != string::npos)
        {
            // convert a (ID) and b (capacity) from string to integer
            a = stoi(command.substr(command.find("[") + 1, command.find_first_of("]") - command.find("[") - 1));
            b = stoi(command.substr(command.find_last_of("[") + 1, command.find_last_of("]") - command.find_last_of("[") - 1));

            // create new flight if there are less than 10 flights
            if (i < 10 && a > 0 && b > 0)
            {
                booking[i] = FlightBooking(a, b, 0);
                flight.push_back(&booking[i]);
                booking[i].printStatus(flight);

                // increment number of flights in the system
                i++;
            }
            else
                cout << "Cannot perform this operation: maximum flights reached" << endl;
        } //...end if (command.find("create") != string::npos)

        // if command includes "add", add flight
        else if (command.find("add") != string::npos)
        {
            // convert a (ID) and b (seats) from string to integer and add reservations
            a = stoi(command.substr(command.find("[") + 1, command.find_first_of("]") - command.find("[") - 1));
            b = stoi(command.substr(command.find_last_of("[") + 1, command.find_last_of("]") - command.find_last_of("[") - 1));
            booking[i].addF(a, b, flight);
            booking[i].printStatus(flight);
        } //...end else if (command.find("add") != string::npos)

        // if command includes "cancel", cancel flights
        else if (command.find("cancel") != string::npos)
        {
            // convert a (ID) and b (seats) from string to integer and subtract reservations
            a = stoi(command.substr(command.find("[") + 1, command.find_first_of("]") - command.find("[") - 1));
            b = stoi(command.substr(command.find_last_of("[") + 1, command.find_last_of("]") - command.find_last_of("[") - 1));
            booking[i].cancelF(a, b, flight);
            booking[i].printStatus(flight);
        } //...end else if (command.find("cancel") != string::npos)

        // if command includes "delete", delete flight
        else if (command.find("delete") != string::npos)
        {
            // convert a (ID) from string to integer and delete the ID from the system
            a = stoi(command.substr(command.find("[") + 1, command.find("]") - command.find("[") - 1));
            booking[i].deleteF(flight, a);
            booking[i].printStatus(flight);
        } //...end else if (command.find("delete") != string::npos)

        // if command includes "quit", exit program
        else if (command.find("quit") != string::npos)
        {
            cout << "Thank you for using the flight booking system.\n";
            break;
        }

        // display error message if the command does not exist
        else
            cout << "Cannot perform this operation: invalid command" << endl;
    } // end while

    return 0;
} //...end main()