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

int main ()
{
    short Year = ReadNumber("Please Enter a Year? ");
    if (Is_Leap(Year))
    {
        cout << "\nYear " << Year << " Is a Leap Year\n";
    }
    else
    {
        cout << "\nYear " << Year << " Is Not a Leap Year\n";
    }
    return 0;
}