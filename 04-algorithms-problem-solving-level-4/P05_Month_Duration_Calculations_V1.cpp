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

short NumberOfDaysInMonth (short Year, short Month)
{
    if (Month < 1 || Month > 12)
    {
        return 0;
    }

    if (Month == 2)
    {
        return (Is_Leap(Year) ? 29 : 28);
    }


    short arr31Days[] = {1, 3, 5, 7, 8, 10, 12};
    for (short i = 0; i <= 7; i++)
    {
        if (Month == arr31Days[i])
        return 31;
    }

    return 30;
}

short NumberOfHoursInMonth (short Year, short Month)
{
    return NumberOfDaysInMonth(Year, Month) * 24;
}

int NumberOfMinutesInMonth (short Year, short Month)
{
    return NumberOfHoursInMonth(Year, Month) * 60;
}

int NumberOfSecondsInMonth (short Year, short Month)
{
    return NumberOfMinutesInMonth(Year, Month) * 60;
}


int main ()
{
    short Year = ReadNumber("Please Enter a Year To Check? ");
    short Month = ReadNumber ("\nPlease Enter a Month To Check? ");

    cout << "\nNumber of Days    in Month [" << Month << "] is " << NumberOfDaysInMonth(Year, Month);
    cout << "\nNumber of Hours   in Month [" << Month << "] is " << NumberOfHoursInMonth(Year, Month);
    cout << "\nNumber of Minutes in Month [" << Month << "] is " << NumberOfMinutesInMonth(Year, Month);
    cout << "\nNumber of Seconds in Month [" << Month << "] is " << NumberOfSecondsInMonth(Year, Month);

    return 0;
}