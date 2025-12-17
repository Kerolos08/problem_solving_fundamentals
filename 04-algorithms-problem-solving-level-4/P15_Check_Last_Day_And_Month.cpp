#include <iostream>
using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

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

    short arrDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (Month == 2 ? Is_Leap(Year) ? 29 : 28 : arrDays[Month]);
}

stDate ReadDate ()
{
    stDate Date;
    Date.Day = ReadNumber ("Please Enter a Day? ");
    Date.Month = ReadNumber ("\nPlease Enter a Month? ");
    Date.Year = ReadNumber("\nPlease Enter a Year? ");
    return Date;
}

bool Is_LastDayInTheMonth (stDate Date)
{
    short MonthDays = NumberOfDaysInMonth(Date.Year, Date.Month);
    return (Date.Day == MonthDays);
}

bool Is_LastMonthInTheYear (stDate Date)
{
    return (Date.Month == 12);
}

int main ()
{
    stDate Date = ReadDate();

    if (Is_LastDayInTheMonth(Date))
    {
        cout << "\n\nYes, Day Is the Last Day in the Month\n";
    }
    else
    {
        cout << "\n\nNo, Day Is Not the Last Day in the Month\n";
    }

        if (Is_LastMonthInTheYear(Date))
    {
        cout << "\n\nYes, Month is the last month in the year\n";
    }
    else
    {
        cout << "\n\nNo, Month is Not the last month in the year\n";
    }
    return 0;
}