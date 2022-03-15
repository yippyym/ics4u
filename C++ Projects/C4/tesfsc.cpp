/*
Name: Jessie Kim
Teacher: Mr. Noukovitch 
Class: ICS4U1-4A
Assignment: Lab 5.3.3: FlightBooking System Part 3
Purpose: create a flightbook system that manages multiple flights with different commands using classes and objects. 
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

class FlightBooking{
//declare public functions in class
public:
    FlightBooking(int id, int capacity, int reserved);
    FlightBooking();
    void printStatus(vector<FlightBooking*> vector);
    int getId(){return this->id;}//end of getId()
    //command functions
     void deleteF(vector<FlightBooking*> &vector, int id);
     void addF(int id, int n, vector<FlightBooking*> &vector);
     void cancelF(int id, int n, vector<FlightBooking*> &vector);

//declare private variables
private:
    int id;
    int capacity;
    int reserved;
};//...end of class FlightBooking

FlightBooking::FlightBooking(){
    //make all variables start with 0
    int id = 0, reserved = 0, capacity = 0;
}//...end of FlightBooking function

//function to store data 
FlightBooking::FlightBooking(int id, int capacity, int reserved){
    this->id = id;
    this->capacity = capacity;
    this->reserved = reserved;
}//...end of FlightBooking function

//function to print results
void FlightBooking::printStatus(vector<FlightBooking*> vector){
    double percent = 0; 
    for(int i = 0; i < vector.size(); i++){
        //calculate percent of reserved/capacity of the flight ID
        percent = 100* ((double)vector[i]->reserved/vector[i]->capacity);
        //print results
        cout<<"Flight"<<vector[i]->id<<": "<<vector[i]->reserved<<"/"<<vector[i]->capacity<<"("<<setprecision(3)<<percent<<"%) seats reserved.\n";
    }//...end of for loop
}//...end of printStatus function

//select which flight ID to use
int select(vector<FlightBooking*> vector, int id){
    //check if inputed ID matches any of the created flight IDs
    for(int i = 0; i < vector.size(); i++){
        if(vector[i]->getId() == id)
            return i;
    }//...end of for loop
    //return -1 if flight ID does not exist
    return -1;
}//...end of select function

//function to remove flight
void FlightBooking::deleteF(vector<FlightBooking*> &vector, int id){
    int index = select(vector,id);
    //if input flight ID exists, delete the flight ID and all information in the ID
    if(index != -1){
        //remind user that flight ID inputed has bee deleted
        cout<<"Flight"<<id<<" has been deleted\n";
        vector.erase(vector.begin()+index);
        for(int i = index; i <vector.size(); ++i){
            vector[i] = vector[i+1];
        i--;
        }//...end of for loop
    }//...end of if loop
    //if flightID does not exist, cannot perform operation
    else
        cout<<"Cannot perform this operation: flight number does not exist. Please try again.\n";
}//...end of deleteF function

//function to add n reservations to a flight ID
void FlightBooking::addF(int id, int n, vector<FlightBooking*> &vector){
    int index = select(vector,id);
    if(index != -1){
        //if inputed flightID exists and percent of already existing reservaions + new reservations/capacity <= 105%, succesfully make n reservations.
        if(((double)(vector[index]->reserved + n)/ vector[index]->capacity)*100 <= 105)
            vector[index]->reserved += n;
        //if percent of already existing reservaions + new reservations/capacity > 105%, cannot perform operation
        else   
            cout<<"Cannot perform this operation: capacity limit exceeded\n";
    }//...end of outer if loop
    //if flight ID does not exist, cannot perform operation
    else
        cout<<"Cannot perform this operation: flight number does not exist. Please try again.\n";
}//...end of add function

//function to cancel n reservations from the flight
void FlightBooking::cancelF(int id, int n, vector<FlightBooking*> &vector){
    int index = select(vector,id);
    if(index != -1){
        //if inputed flightID exists and already reserved - cancelling reserved seats is greater than/equal to 0, successfully cancel n reservations
        if(vector[index]->reserved - n >= 0)
            vector[index]->reserved -= n;
        //if smaller than 0, cannot perform operation
        else    
            cout<<"Cannot perform this operation: there are no reservations to cancel. \n";
    }//...end of outer if loop
    //if flightID does not exist, cannot perform operation
    else    
        cout<<"Cannot perform this operation: flight number does not exist. Please try again. \n";
}//...end of cancel function

int main(){
    //declare variables
    vector<FlightBooking*> flight;
    //limit maximum number of handled flights to ten
    FlightBooking booking[10];
    int arg1,arg2,index;
    int i = 0;
    string command = " ";
    
    //print instructions
    cout <<"To create the flight, input the following command in specific syntax: \n";
    cout<<"A. create[id][capacity] \nB. delete[id] \nC. add[id][# of reservations to add] \nD. cancel[id][# of reservatto cancel] \n"<<endl;
    
    while(command != "quit"){
        //ask user to imput a command
        cout<<"What would you like to do? Enter command: ";
        //get the command
        getline(cin,command);

        //if command is "create[id][capacity]" create new empty flight with ID[id] and capacity [capacity]
        if(command.find("create") != string::npos){
            //get ID number
            arg1 = stoi(command.substr(command.find("[") + 1, command.find_first_of("]") - command.find("[") - 1));
            //get capacity number
            arg2 = stoi(command.substr(command.find_last_of("[")+1, command.find_last_of("]") - command.find_last_of("[") - 1));
            //if ID > 0, capacity > 0, and in the maximum ten flights, go through the functions and print results
            if(i < 10 && arg1 > 0 && arg2 > 0){
                booking[i] = FlightBooking(arg1,arg2,0);
                flight.push_back(&booking[i]);
                //print results
                booking[i].printStatus(flight);
                //increase number of handled flights by one
                i++;
            }//...end of inner if loop

            //if ID number is less than 0 and capacity is less than/equal to 0, cannot perform operation
            else if(arg1 < 0 || arg2 <= 0)
                cout<<"Cannot perform this operation: invalid count \n";
            //else, warn user that the number of flights able to handle has exceeded
            else
                cout<<"Maximum number of handled flights exceeded \n";
        }//...end of outer if loop

        //if command is "delete[id]", remove flight with ID[id]
        else if(command.find("delete") != string::npos){
            //get ID
            arg1 = stoi(command.substr(command.find("[")+1, command.find("]") - command.find("[")-1));
            //delete ID
            booking[i].deleteF(flight,arg1);
            //print results
            booking[i].printStatus(flight);
        }//...end of else if loop

        //if command is "add[id][reserved]" add [reserved] reservations to the flight with ID[id]
        else if(command.find("add") != string::npos){
            //get ID
            arg1 = stoi(command.substr(command.find("[")+1, command.find_first_of("]") - command.find("[")-1));
            //get n reservations to add
            arg2 = stoi(command.substr(command.find_last_of("[")+1, command.find_last_of("]") - command.find_last_of("[") - 1));
            //add reservations
            booking[i].addF(arg1, arg2, flight);
            //print results
            booking[i].printStatus(flight);
        }//...end of else if loop

        //if command is "cancel[id][reserved]" cancel [reserved] reservations from the flight with ID[id]
        else if(command.find("cancel") != string::npos){
            //get ID
            arg1 = stoi(command.substr(command.find("[")+1, command.find_first_of("]") - command.find("[")-1));
            //get n reservations to cancel
            arg2 = stoi(command.substr(command.find_last_of("[")+1, command.find_last_of("]") - command.find_last_of("[") - 1));
            //cancel reservations
            booking[i].cancelF(arg1,arg2,flight);
            //print results
            booking[i].printStatus(flight);
        }//...end of else if loop

        //if command is "quit" stop the execution of the program
        else if(command.find("quit") != string::npos)
            break;
        //else, cannot perform operation since command does not exist
        else
            cout<<"Cannot perform this operation: such command does not exist. Please try again."<<endl;
    }//end of while loop

    return 0;
}//...end of program