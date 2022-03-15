/*
Author: Yani Mei
Teacher: Mr. Noukhovitch
Class: ICS4U1-4A
Program: Final Mark Calculator
Purpose: The following program will return the student's course average and final
average based on the number of courses and assignments inputed by the user.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    int course, assignment;
    double grade, overallAvg;

    // ask user to input number of courses and assignments
    cout << "Enter the number of course you are taking: ";
    cin >> course;
    cout << "Enter the number of assignment per course: ";
    cin >> assignment;
    cout << endl;

    // allocate and initialize the array
    double **arr = new double *[course];

    for (int i = 0; i < course; i++)
    {
        arr[i] = new double[assignment];

        // create a header for each course
        cout << "Course " << i + 1 << endl;

        // input grades for each assignment
        for (int j = 0; j < assignment; j++)
        {
            cout << "Enter assignment " << j + 1 << " grade: ";
            cin >> arr[i][j];
        } //... end inner for

        cout << endl;

    } //... end outer for

    // display a line between input and output
    cout << "-----------------------------------------------" << endl;

    for (int i = 0; i < course; i++)
    {
        double courseAvg = 0;
        string str = " Grades: ";
        cout << "Course " << i + 1 << ": ";

        // update grades for each assignment
        for (int j = 0; j < assignment; j++)
        {
            courseAvg += arr[i][j];
            string tmp = to_string(arr[i][j]);

            // format grades
            tmp.erase(tmp.find_last_not_of('0') + 1, string::npos);
            tmp.erase(tmp.find_last_not_of('.') + 1, string::npos);

            // append and store grades
            str.append(tmp).append(" ");
        } //... end inner for

        // calculate and output course average with 4 sig figs
        courseAvg /= assignment;
        cout << "Final = " << fixed << setprecision(2) << courseAvg << str << endl;
        overallAvg += courseAvg;
    } //... end outer for

    // calculate and output overall average with 4 sig figs
    overallAvg /= course;
    cout << "Overall average = " << fixed << setprecision(2) << overallAvg << endl;

    // free the array
    for (int i = 0; i < course; i++)
        delete[] arr[i];

    delete[] arr;

    return 0;
} //... end main