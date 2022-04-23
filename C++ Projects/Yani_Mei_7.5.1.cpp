/*
Author: Yani Mei
Teacher: Mr. Noukhovitch
Class: ICS4U1-4A
Program: Exceptions - Tower of Hanoi
Purpose: The following program mimics the Tower of Hanoi game 
while incorporating objects and exceptions.
*/

#include <iostream>
#include <vector>
using namespace std;

class NotInRange : public exception
{
private:
    string msg;

public:
    // print exception for NotInRange
    string getError()
    {
        return this->msg;
    }
    // build constructor for NotInRange
    NotInRange(string msg)
    {
        this->msg = msg;
    }
}; //...end NotInRange

class IncorrectDiskSize : public exception
{
private:
    string msg;

public:
    // print exception for IncorrectDiskSize
    string getError()
    {
        return this->msg;
    }
    // build constructor for IncorrectDiskSize
    IncorrectDiskSize(string msg)
    {
        this->msg = msg;
    }
}; //...end IncorrectDiskSize

class DiskNotFound : public exception
{
private:
    string msg;

public:
    // print exception for DiskNotFound
    string getError()
    {
        return this->msg;
    }
    // build constructor for DiskNotFound
    DiskNotFound(string msg)
    {
        this->msg = msg;
    }
}; //...end DiskNotFound

// class holding values representing TowerOfHanoi
class TowerOfHanoi
{
private:
    int id;
    vector<int> disks;

public:
    // build constructor for TowerOfHanoi
    TowerOfHanoi(int id)
    {
        this->id = id;
    }
    TowerOfHanoi(int id, vector<int> disks)
    {
        this->id = id;
        this->disks = disks;
    }

    // method to move disks
    static void move(TowerOfHanoi &first, TowerOfHanoi &second)
    {
        // throw expection if no disks to move
        if (first.disks.size() <= 0)
            throw DiskNotFound("No disks in source tower.");
        else if (second.disks.size() < 0)
        {
            // throw expection if disk size does not match requirements
            if (first.disks[first.disks.size() - 1] > second.disks[second.disks.size() - 1])
                throw IncorrectDiskSize("Incorrect disk size.");
        }
        else
        {
            // move disks if all requirements are met
            second.disks.push_back(first.disks[first.disks.size() - 1]);
            first.disks.pop_back();
        }
    }

    // method to print tower contents
    void print()
    {
        cout << "tower_" << id << ": ";
        // print empty if no disks found
        if (disks.size() == 0)
            cout << "empty";
        else
        {
            // loop through length of disk to print contents
            for (int j = 0; j < disks.size(); j++)
                cout << disks[j] << " ";
        }

        cout << endl;
    }
}; //...end TowerOfHanoi

int main()
{
    // declare towers & respective attributes
    vector<int> forTower1 = {3, 2, 1};
    TowerOfHanoi tower1(1, forTower1);
    TowerOfHanoi tower2(2);
    TowerOfHanoi tower3(3);

    // store towers by reference
    TowerOfHanoi *towers[3] = {&tower1, &tower2, &tower3};

    // declare counter to limit messages to 7
    int counter = 0;
    string msg;

    try
    {
        // get a total of 7 user inputs
        while (counter < 7)
        {
            cout << "Enter your move: ";
            cin >> msg;

            // extract values from the message
            int actions[2] = {msg[0] - '0', msg[1] - '0'};

            // display exception if inputted digits are not within range
            if ((actions[0] < 1 || actions[0] > 3) || (actions[1] < 1 || actions[1] > 3))
                throw NotInRange("Tower numbers not in range.");
            else
            {
                // move disks according to message & increase counter by 1
                TowerOfHanoi::move(*towers[actions[0] - 1], *towers[actions[1] - 1]);
                counter++;
            }
        } //...end while

        // print contents of each tower
        cout << "\nRESULTS:\n";
        tower1.print();
        tower2.print();
        tower3.print();
    } //...end try

    // catch blocks - print 3 exceptions
    catch (NotInRange &e)
    {
        cout << e.getError();
    }
    catch (IncorrectDiskSize &e)
    {
        cout << e.getError();
    }
    catch (DiskNotFound &e)
    {
        cout << e.getError();
    }

    return 0;
} //...end main()