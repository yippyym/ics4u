/*
Author: Yani Mei
Teacher: Mr. Noukhovitch
Class: ICS4U1-4A
Program: String Analyzer
Purpose: The following program will return the number of times a character
appears in a string inputted by the user.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    // input stores user input, counted stores # of unique characters counted
    string input;
    int counted = 0;

    // prompt and get user input
    cout << "Enter a string: ";
    getline(cin, input);

    // keep track of unique characters in the input
    char unique[input.length()];

    // run through every character in the string
    for (int i = 0; i < input.length(); i++)
    {
        // check if character at index i has been counted, prevents duplicates
        bool alreadyCounted = false;
        for (int j = 0; j <= counted; j++)
        {
            if (input[i] == unique[j])
                alreadyCounted = true;
        } // ...end inner for

        // go to next iteration of the loop if already counted
        if (alreadyCounted)
            continue;

        // count characters that have not been counted
        int counter = 0;
        for (int j = 0; j < input.length(); j++)
        {
            if (input[i] == input[j])
                counter++;
        } // ...end inner for

        // format in alphabetical order and ignore spaces
        sort(input.begin(), input.end());
        input.erase(remove(input.begin(), input.end(), " "), input.end());

        // output counter
        cout << input[i] << " - " << counter << endl;

        // add character to array of accumulated unique characters
        unique[counted] = input[i];
        counted++;
    } //...end outer for

    return 0;
} // ...end main