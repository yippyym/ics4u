/*
Author: Yani Mei
Teacher: Mr. Noukhovitch
Class: ICS4U1-4A
Program: Flight Booking System Part 3
Purpose: The following program will--------
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class FlightBooking
{
public:
    FlightBooking(int id, int capacity, int reserved);
    FlightBooking();
    void printStatus(vector<FlightBooking*> vector);
    int getId(){return this->id;}
    // int getCapacity();
    // double getPercent();
    // void createF(string command);
    void deleteF(string command);
    void addF(string command);
    void cancelF(string command);

    // int vectorID[10];
    // int globalCounter = 0;
    string command;

private:
    int id, capacity, reserved;
    double percent;
};

FlightBooking::FlightBooking()
{
    id = 0, capacity = 0, reserved = 0, percent = 0;
} //...end FlightBooking()

// function that returns flight ID
int FlightBooking::getId()
{
    return id;
} //...end getId()

// // function that returns flight capacity
// int FlightBooking::getCapacity()
// {
//     return capacity;
// } //...end getCapacity()

// function that returns the percentage of reserved seats
double FlightBooking::getPercent()
{
    percent = reserved * 1.0 / capacity * 100.0;
    return percent;
} //...end getPercent()

//
void FlightBooking::createF(string command)
{
    // extract the flight ID and capacity
    string flightID = command.substr(command.find("[") + 1, command.find_first_of("]") - command.find("[") - 1);
    string flightCapacity = command.substr(command.find_last_of("[") + 1, command.find_last_of("]") - command.find_last_of("[") - 1);

    // change flight ID and capacity from string to integer
    id = stoi(flightID);
    capacity = stoi(flightCapacity);

    vectorID[globalCounter] = getId();
    globalCounter++;

    printStatus();
} //...end createF

// function that deletes flights
void FlightBooking::deleteF(string command)
{
    cout << "Flight " << id << " has been deleted. \n"
         << endl;
} //...end deleteF

//
void FlightBooking::addF(string command)
{
    // extract the flight ID and number of added seats
    string flightID = command.substr(command.find("[") + 1, command.find_first_of("]") - command.find("[") - 1);
    string addedFlights = command.substr(command.find_last_of("[") + 1, command.find_last_of("]") - command.find_last_of("[") - 1);

    // change ID and number of added seats from string to integer
    int id2 = stoi(flightID);
    int added = stoi(addedFlights);

    //
    int i = 0;
    while (i < 10)
    {
        if (id2 == vectorID[i])
            reserved += added;

        i++;
    }

    // let user know if the flight capacity has been reached
    if (reserved > capacity)
    {
        cout << "Cannot perform this operation: capacity reached" << endl;
        reserved = 0;
        printStatus();
    }
    // let user know if the flight does not exist
    else if (reserved == 0)
        cout << "Cannot perform this operation: flight " << id2 << " not found" << endl
             << endl;
    // print status if seats are available
    else
        printStatus();
} //...end addF

// function that cancels flights
void FlightBooking::cancelF(string command)
{
    // extract the number of canceled flights
    string canceledFlights = command.substr(command.find_last_of("[") + 1, command.find_last_of("]") - command.find_last_of("[") - 1);

    // change ID and number of canceled flights from string to integer
    int id2 = stoi(canceledFlights);
    int subtracted = stoi(canceledFlights);

    // subtract canceled flights from total reserved seats
    reserved -= subtracted;

    // display error message if flight does not exist
    if (id2 == 0)
        cout << "Cannot perform this operation: flight " << id2 << " not found" << endl;

    printStatus();
} //...end cancelF

// function that prints flight status
void FlightBooking::printStatus()
{

    cout << "Flight " << id << " : " << reserved << "/" << capacity << " " << getPercent() << "% seats reserved. \n"
         << endl;
} //...end printStatus

int main()
{
    
    FlightBooking booking[10];
    string command = "", create = "create",
           deleteF = "delete", add = "add", cancel = "cancel", quit = "quit";

    // display commands
    cout << "----------------------------------------------------------\n"
            "Input your flight information with the following syntax: \n"
            "id = flight ID, cap = flight capacity, and n = # of seats\n"
            "\n(1) create[id][cap]\n"
            "(2) delete[id]\n"
            "(3) add[id][n]\n"
            "(4) cancel[id][n]\n"
            "----------------------------------------------------------\n";

    while (command != "quit")
    {
        // ask for user input and include whitespaces
        cout << "Enter a command: ";
        getline(cin, command);
        int space = command.find("[");
        string a = command.substr(0, space);

        // call functions based on user's command
        if (a.compare(create) == 0)
            booking[0].createF(command);
        else if (a.compare(deleteF) == 0)
            booking[0].deleteF(command);

        else if (a.compare(add) == 0)
            booking[0].addF(command);

        else if (a.compare(cancel) == 0)
            booking[0].cancelF(command);

        else if (a.compare(quit) == 0)
            booking[0].printStatus();

        else
            cout << "invalid command \n"
                 << endl;
    }

    return 0;
} //...end main


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class FlightBooking
{
public:
    FlightBooking(int id, int capacity, int reserved);
    FlightBooking();
    void printStatus();
    int getId();
    int getCapacity();
    double getPercent();
    
    int vectorID[10];
    int globalCounter = 0;

    void createF(string command);
    void deleteF(string command);
    void addSeats(string command);
    void cancelF(string command);

    string command;
    // quit cancel and add
private:
    int id, capacity, reserved;
    double percent;
};

FlightBooking::FlightBooking()
{
    id = 0, capacity = 0, reserved = 0, percent = 0;
}

int FlightBooking::getId()
{
    return id;
}

int FlightBooking::getCapacity()
{
    return capacity;
}

double FlightBooking::getPercent()
{
    percent = reserved * 1.0 / capacity * 100.0;
    return percent;
}

void FlightBooking::createF(string commancommand)
{
    string the_id = command.substr(command.find(" ") + 1, command.find_first_of(" "));
    string the_cap = command.substr(command.find_last_of(" ") + 1, command.find_last_of(" "));

    id = stoi(the_id);
    capacity = stoi(the_cap);

    vectorID[globalCounter] = getId();
    globalCounter++;
    cout << vectorID[globalCounter] << endl
         << globalCounter << endl;

    printStatus();
}

void FlightBooking::deleteF(string command)
{
    cout << "Flight " << id << " has been deleted. \n"
         << endl;
}

void FlightBooking::addSeats(string command)
{
    string the_id = command.substr(command.find(" ") + 1, command.find_first_of(" "));
    string the_add = command.substr(command.find_last_of(" ") + 1, command.find_last_of(" "));

    int id2 = stoi(the_id);
    int add = stoi(the_add);

    int i = 0;
    while (i < 10)
    {
        if (id2 == vectorID[i])
            reserved += add;

        i++;
    }

    if (reserved > capacity)
    {
        cout << "Cannot perform this operation: capacity reached" << endl;
        reserved = 0;
    }

    printStatus();
}

void FlightBooking::cancelF(string command)
{
    string the_deduction = command.substr(command.find_last_of(" ") + 1, command.find_last_of(" "));
    // string the_deduction = command.substr(command.find_last_of(" ") + 1, command.find_last_of(" ") - command.find_last_of(" ") - 1);

    int subtract = stoi(the_deduction);
    reserved -= subtract;

    printStatus();
}

void FlightBooking::printStatus()
{

    cout << "Flight " << id << " : " << reserved << "/" << capacity << " " << getPercent() << "% seats reserved. \n"
         << endl;
}

int main()
{
    FlightBooking booking[10];
    string command = "", create = "create", deleteF = "delete", add = "add", cancel = "cancel", quit = "quit";

    cout << "--------------------------------------------------------------------\n"
            "Please input your flight information using the following syntax: \n"
            "id = flight ID, capcitiy = flight capacity, and n = number of seats\n"
            "\n(1) create id capacity\n"
            "(2) delete id\n"
            "(3) add id n\n"
            "(4) cancel id n\n"
            "--------------------------------------------------------------------\n";

    while (command != "quit")
    {
        cout << "Enter a command: ";
        getline(cin, command);
        int space = command.find(" ");

        string a = command.substr(0, space);
        if (a.compare(create) == 0)
            booking[0].createF(command);

        else if (a.compare(deleteF) == 0)
            booking[0].deleteF(command);

        else if (a.compare(add) == 0)
            booking[0].addSeats(command);

        else if (a.compare(cancel) == 0)
            booking[0].cancelF(command);

        else if (a.compare(quit) == 0)
            booking[0].printStatus();

        else
            cout << "invalid command" << endl
                 << endl;
    }

    return 0;
}