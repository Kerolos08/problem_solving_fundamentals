#include <iostream>
using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

bool Is_Leap(short Year)
{
    // return (Year % 400 == 0 ? true : Year % 100 == 0 ? false : Year % 4 == 0 ? true : false);
    return (Year % 100 != 0 && Year % 4 == 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Year, short Month)
{
    if (Month < 1 || Month > 12)
    {
        return 0;
    }

    short arrDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (Month == 2 ? Is_Leap(Year) ? 29 : 28 : arrDays[Month]);
}

int ReadNumber(string msg)
{
    int number;
    cout << msg;
    cin >> number;
    return number;
}

stDate ReadDate()
{
    stDate Date;
    Date.Day = ReadNumber("Please Enter a Day? ");
    Date.Month = ReadNumber("\nPlease Enter a Month? ");
    Date.Year = ReadNumber("\nPlease Enter a Year? ");
    return Date;
}

bool IsValidDate(stDate Date)
{
    if (Date.Month < 1 || Date.Month > 12)
        return false;

    if (Date.Day < 1 || Date.Day > 31)
        return false;

    short DaysInMonth = NumberOfDaysInMonth(Date.Year, Date.Month);
    if (Date.Day > DaysInMonth)
        return false;

    return true;
}

int main()
{
    stDate Date = ReadDate();
    if (IsValidDate(Date))
    {
        cout << "\n\nYes, Date is a Valid Date\n";
    }
    else
    {
        cout << "\n\nNo, Date is not a Valid Date\n";
    }

    return 0;
}