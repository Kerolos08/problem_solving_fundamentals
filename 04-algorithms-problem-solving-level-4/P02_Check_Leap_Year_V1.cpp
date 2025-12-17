#include <iostream>
using namespace std;

int ReadNumber (string msg)
{
    int number;
    cout << msg;
    cin >> number;
    return number;
}

bool Is_leap (short Year)
{
    if (Year % 400 == 0)
    {
        return true;
    }

    else if (Year % 100 == 0)
    {
        return false;
    }

    else if (Year % 4 == 0)
    {
        return true;
    }

    else
    {
        return false;
    }
}

int main ()
{
    short Year = ReadNumber("Please Enter a Year? ");
    if (Is_leap(Year))
    {
        cout << "\nYear " << Year << " Is a Leap Year\n";
    }
    else
    {
        cout << "\nYear " << Year << " Is Not a Leap Year\n";
    }
    return 0;
}