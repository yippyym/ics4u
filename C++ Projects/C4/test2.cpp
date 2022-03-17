/*
Author: Yani Mei
Teacher: Mr. Noukhovitch
Class: ICS4U1-4A
Program: Gym Membership Management System
Purpose: The following program -------------
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
};

Gym::Gym()
{
    int id = 0, valid = 0;
    string name = " ";
}

Gym::Gym(int id, string name, int valid)
{
    this->id = id;
    this->name = name;
    this->valid = valid;
}

void Gym::printStatus(vector<Gym *> gym)
{
    for (int i = 0; i < gym.size(); i++)
        cout << "Member " << gym[i]->id << " : " << gym[i]->name << ", subscription valid for " << gym[i]->valid << " months\n";
}

int choose(vector<Gym *> gym, int id)
{
    for (int i = 0; i < gym.size(); i++)
    {
        if (gym[i]->getId() == id)
            return i;
    }
    return -1;
}

void Gym::extend(int id, int n, vector<Gym *> &gym)
{
    int index = choose(gym, id);
    if (index != -1)
        gym[index]->valid += n;
    else
        cout << "Cannot perform this operation: member " << id << " not found\n";
}

void Gym::cancel(int id, int n, vector<Gym *> &gym)
{
    int index = choose(gym, id);
    if (index != -1)
        gym[index]->valid = 0;
    else
        cout << "Cannot perform this operation: member " << id << " not found\n";
}

void Gym::deleteM(vector<Gym *> &gym, int id)
{
    int index = choose(gym, id);
    if (index != -1)
    {
        cout << "Member " << id << " delete from the system\n";  
        gym.erase(gym.begin() + index);
        for (int i = index; i < gym.size(); ++i)
        {
            gym[i] = gym[i + 1];
            i--;
        }
    }

    else
        cout << "Cannot perform this operation: member " << id << " not found\n";
}

int main()
{
    Gym member[10];
    vector<Gym *> gym;

    int a, b, index, i = 0;
    string name, command = " ";

    cout << "------------------------------------------------------------\n"
            "Input your membership information with the following syntax \n"
            "where id = member ID, name = your name, and n = # of months:\n"
            "\n(1) create[id][name]\n(2) delete[id]\n(3) extend[id][n]\n(4) cancel[id]\n"
            "------------------------------------------------------------\n";

    while (command != "quit")
    {
        cout << endl
             << "Please enter a command: ";
        getline(cin, command);

        if (command.find("create") != string::npos)
        {
            a = stoi(command.substr(command.find("[") + 1, command.find_first_of("]") - command.find("[") - 1));
            b = stoi(command.substr(command.find_last_of("[") + 1, command.find_last_of("]") - command.find_last_of("[") - 1));

            if (i < 10 && a > 0 && b > 0)
            {
                member[i] = Gym(a, name, b);
                gym.push_back(&member[i]);
                member[i].printStatus(gym);

                i++;
            }
            else
                cout << "Cannot perform this operation: maximum members reached" << endl;
        }

        else if (command.find("extend") != string::npos)
        {
            a = stoi(command.substr(command.find("[") + 1, command.find_first_of("]") - command.find("[") - 1));
            b = stoi(command.substr(command.find_last_of("[") + 1, command.find_last_of("]") - command.find_last_of("[") - 1));
            member[i].extend(a, b, gym);
            member[i].printStatus(gym);
        }

        else if (command.find("cancel") != string::npos)
        {
            a = stoi(command.substr(command.find("[") + 1, command.find_first_of("]") - command.find("[") - 1));
            b = stoi(command.substr(command.find_last_of("[") + 1, command.find_last_of("]") - command.find_last_of("[") - 1));
            member[i].cancel(a, b, gym);
            member[i].printStatus(gym);
        }

        else if (command.find("delete") != string::npos)
        {
            a = stoi(command.substr(command.find("[") + 1, command.find("]") - command.find("[") - 1));
            member[i].deleteM(gym, a);
            member[i].printStatus(gym);
        }

        else if (command.find("quit") != string::npos)
        {
            cout << "Thank you for using the gym membership system\n";
            break;
        }

        else
            cout << "Cannot perform this operation: invalid command\n";
    }
}