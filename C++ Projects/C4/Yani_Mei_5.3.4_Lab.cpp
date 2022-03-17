/*
Author: Yani Mei
Teacher: Mr. Noukhovitch
Class: ICS4U1-4A
Program: Gym Membership Management System
Purpose: The following program manages up to 10 gym member subcriptions 
through classes and objects in C++. 
*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Gym
{
public:
    Gym(int id, string name, int valid);
    Gym();
    void printStatus(vector<Gym *> gym);
    int getId() { return this->id; }
    void extend(int id, int n, vector<Gym *> &gym);
    void cancel(int id, int n, vector<Gym *> &gym);
    void deleteM(vector<Gym *> &gym, int id);

private:
    int id, valid;
    string name;
}; //...end Gym class

Gym::Gym()
{
    int id = 0, valid = 0;
    string name = " ";
} //...end Gym()

Gym::Gym(int id, string name, int valid)
{
    // store the instance
    this->id = id;
    this->name = name;
    this->valid = valid;
} //...end Gym

// function that prints all memberships
void Gym::printStatus(vector<Gym *> gym)
{
    for (int i = 0; i < gym.size(); i++)
        cout << "Member " << gym[i]->id << " : " << gym[i]->name << ", subscription valid for " << gym[i]->valid << " months\n";
} //...end printStatus

// function that choose the correct member
int choose(vector<Gym *> gym, int id)
{
    // verify ID exists
    for (int i = 0; i < gym.size(); i++)
    {
        if (gym[i]->getId() == id)
            return i;
    }

    // return -1 if ID does not exist
    return -1;
} //...end choose

// function that extends membership by n months
void Gym::extend(int id, int n, vector<Gym *> &gym)
{
    // extend membership if ID exists, display error if ID does not exist
    int index = choose(gym, id);
    if (index != -1)
        gym[index]->valid += n;
    else
        cout << "Cannot perform this operation: member " << id << " not found\n";
} //...end extend

// function that cancels the membership
void Gym::cancel(int id, int n, vector<Gym *> &gym)
{
    // set valid = 0 if ID exists, display error if ID does not exist
    int index = choose(gym, id);
    if (index != -1)
        gym[index]->valid = 0;
    else
        cout << "Cannot perform this operation: member " << id << " not found\n";
} //...end cancel

// function that deletes members from the system
void Gym::deleteM(vector<Gym *> &gym, int id)
{
    // delete member if ID exists, display error if ID does not exist
    int index = choose(gym, id);
    if (index != -1)
    {
        cout << "Member " << id << " deleted from the system\n";
        // erase the vector
        gym.erase(gym.begin() + index);
        for (int i = index; i < gym.size(); ++i)
        {
            gym[i] = gym[i + 1];
            i--;
        }
    }
    else
        cout << "Cannot perform this operation: member " << id << " not found\n";
} //...end deleteM

int main()
{
    // set limit to 10 members
    Gym member[10];
    vector<Gym *> gym;

    // declare variables for function arguments
    int a, b, index, i = 0;
    string name, command = " ";

    // display commands
    cout << "------------------------------------------------------------\n"
            "Input your membership information with the following syntax \n"
            "where id = member ID, name = your name, and n = # of months:\n"
            "\n(1) create[id][name]\n(2) delete[id]\n(3) extend[id][n]\n(4) cancel[id]\n"
            "------------------------------------------------------------\n"
            "No members in the system\n";

    while (command != "quit")
    {
        // take user input with spaces
        cout << endl
             << "Please enter a command: ";
        getline(cin, command);

        // if command includes "create", create new member
        if (command.find("create") != string::npos)
        {
            // convert a (ID) from string to integer
            a = stoi(command.substr(command.find("[") + 1, command.find_first_of("]") - command.find("[") - 1));
            name = command.substr(command.find_last_of("[") + 1, command.find_last_of("]") - command.find_last_of("[") - 1);

            // create new member if there are >10 members and if ID > 0
            if (i < 10 && a > 0)
            {
                member[i] = Gym(a, name, 0);
                gym.push_back(&member[i]);
                member[i].printStatus(gym);

                i++;
            }
            else
                cout << "Cannot perform this operation: maximum members reached" << endl;
        } //...end if

        // if command includes "extend", extend membership
        else if (command.find("extend") != string::npos)
        {
            // convert a (ID) and b (months) from string to integer
            a = stoi(command.substr(command.find("[") + 1, command.find_first_of("]") - command.find("[") - 1));
            b = stoi(command.substr(command.find_last_of("[") + 1, command.find_last_of("]") - command.find_last_of("[") - 1));

            // call extend and printStatus
            member[i].extend(a, b, gym);
            member[i].printStatus(gym);
        } //...end else if

        // if command includes "cancel", cancel membership
        else if (command.find("cancel") != string::npos)
        {
            // convert a (ID) and b (months) from string to integer
            a = stoi(command.substr(command.find("[") + 1, command.find_first_of("]") - command.find("[") - 1));
            b = stoi(command.substr(command.find_last_of("[") + 1, command.find_last_of("]") - command.find_last_of("[") - 1));

            // call cancel and printStatus
            member[i].cancel(a, b, gym);
            member[i].printStatus(gym);
        } //...end else if

        // if command includes "delete", delete membership
        else if (command.find("delete") != string::npos)
        {
            // convert a (ID) from string to integer and call delete and printStatus
            a = stoi(command.substr(command.find("[") + 1, command.find("]") - command.find("[") - 1));
            member[i].deleteM(gym, a);
            member[i].printStatus(gym);
        } //...end else if

        // if command includes "quit", exit the program
        else if (command.find("quit") != string::npos)
        {
            cout << "Thank you for using the gym membership system\n";
            break;
        } //...end else if

        // if command does not exist, display error message
        else
            cout << "Cannot perform this operation: invalid command\n";
    }
}