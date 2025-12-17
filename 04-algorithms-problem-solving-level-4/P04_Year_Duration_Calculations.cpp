#include <iostream>
using namespace std;

bool Is_Leap (short Year)
{
    // return (Year % 400 == 0 ? true : Year % 100 == 0 ? false : Year % 4 == 0 ? true : false);
    return (Year % 100 != 0 && Year % 4 == 0) || (Year % 400 == 0);
}

int ReadNumber (string msg)
{
    int number;
    cout << msg;
    cin >> number;
    return number;
}

short NumberOfDays (short Year)
{
    return (Is_Leap(Year)? 366 : 365);
}

short NumberOfHours (short Year)
{
    return NumberOfDays(Year) * 24;
}

int NumberOfMinutes (short Year)
{
    return NumberOfHours(Year) * 60;
}

int NumberOfSeconds (short Year)
{
    return NumberOfMinutes(Year) * 60;
}

int main ()
{
    short Year = ReadNumber("Please Enter a Year To Check? ");

    cout << "\nNumber of Days    in Year [" << Year << "] is " << NumberOfDays(Year);
    cout << "\nNumber of Hours   in Year [" << Year << "] is " << NumberOfHours(Year);
    cout << "\nNumber of Minutes in Year [" << Year << "] is " << NumberOfMinutes(Year);
    cout << "\nNumber of Seconds in Year [" << Year << "] is " << NumberOfSeconds(Year);

    return 0;
}