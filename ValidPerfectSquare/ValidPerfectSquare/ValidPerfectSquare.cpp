/*****************************************************************************************
 Program:       Valid Perfect Square
 Author:        William A. CLaerk, Crestworld Studios
 Description:   This program will take an integer from the user and display if the integer 
                is a valid perfect square or not.
 *****************************************************************************************/

#include <iostream>

using namespace std;

// function prototype(s)
bool isPerfectSquare(int);

int main()
{
    int number;

    cout << "Enter a Number: ";
    cin >> number;

    if (isPerfectSquare(number))
        cout << "\nOutput: true";
    else
        cout << "\nOutput: false";

    cout << "\n\n";

    return 0;
}

bool isPerfectSquare(int num)
{
    bool complete = false;
    int x = 0;
    int y = 0;

    do
    {
        if ((x > 46340) && (y > 46340))
        {
            complete = true;
            return false;
        }
        else if (x * y == num)
        {
            complete = true;
            return true;
        }
        else if (x * y > num)
        {
            complete = true;
            return false;
        }

        ++x;
        ++y;
    } while (!complete);

    return false;
}