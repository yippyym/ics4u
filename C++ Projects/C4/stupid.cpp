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
	TowerOfHanoi(int id)
	{
		this->id = id;
	}
	TowerOfHanoi(int id, vector<int> disks)
	{
		this->id = id;
		this->disks = disks;
	}
	static void move(TowerOfHanoi &first, TowerOfHanoi &second)
	{
		// display expection if no disks to move
		if (first.disks.size() <= 0)
			throw DiskNotFound("No disks in source tower.");
		else if (second.disks.size() < 0)
		{
			// display expection if disk size does not match requirements
			if (first.disks[first.disks.size() - 1] > second.disks[second.disks.size() - 1])
				throw IncorrectDiskSize("Incorrect disk size.");
		}
		// move disks if all requirements are met
		else
		{
			second.disks.push_back(first.disks[first.disks.size() - 1]);
			first.disks.pop_back();
		}
	}

	// method to print tower contents
	void print()
	{
		cout << "tower_" << id << ": ";

		// loop through all three towers & print contents
		if (disks.size() == 0)
			cout << "empty";
		else
			for (int j = 0; j < disks.size(); j++)
				cout << disks[j] << " ";
		cout << endl;
	}
}; //...end TowerOfHanoi

int main()
{
	// tower 1 has three disks
	vector<int> forTower1 = {3, 2, 1};
	TowerOfHanoi tower1(1, forTower1);
	TowerOfHanoi tower2(2);
	TowerOfHanoi tower3(3);
	TowerOfHanoi *towers[3] = {&tower1, &tower2, &tower3};

	// declare counter to keep track of input and input to store input
	int counter = 0;
	string input;

	try
	{
		// get a total of 7 user inputs
		while (counter < 7)
		{
			cout << "Enter a move: ";
			cin >> input;

			// extract values from the input
			int actions[2] = {input[0] - '0', input[1] - '0'};

			// display exception if inputted digits are not within range
			if ((actions[0] < 1 || actions[0] > 3) || (actions[1] < 1 || actions[1] > 3))
				throw NotInRange("Tower numbers not in range.");
			// move disks according to input
			else
			{
				TowerOfHanoi::move(*towers[actions[0] - 1], *towers[actions[1] - 1]);
				counter++;
				tower1.print();
				tower2.print();
				tower3.print();
			}
		} //...end while
	}

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