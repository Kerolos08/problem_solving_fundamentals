#pragma warning(disable : 4996)

#include <ctime>
#include <iostream>
using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

int ReadNumber (string msg)
{
    int number;
    cout << msg;
    cin >> number;
    return number;
}

bool Is_Leap (short Year)
{
    // return (Year % 400 == 0 ? true : Year % 100 == 0 ? false : Year % 4 == 0 ? true : false);
    return (Year % 100 != 0 && Year % 4 == 0) || (Year % 400 == 0);
}

stDate ReadDate ()
{
    stDate Date;
    Date.Day = ReadNumber ("Please Enter a Day? ");
    Date.Month = ReadNumber ("\nPlease Enter a Month? ");
    Date.Year = ReadNumber("\nPlease Enter a Year? ");
    return Date;
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

bool IsDate1BeforeDate2 (stDate Date1, stDate Date2)
{
    return (Date2.Year > Date1.Year ? true : (Date2.Year == Date1.Year ? (Date2.Month > Date1.Month ? true : (Date2.Month == Date1.Month ? (Date2.Day > Date1.Day) : false)) : false ));
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

stDate AddingOneDayToDate (stDate Date)
{
    if (Is_LastDayInTheMonth(Date))
    {
        if (Is_LastMonthInTheYear(Date))
        {
            Date.Day = 1;
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
        Date.Day = 1;
        Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }
    return Date;
}

int GetDiffInTwoDates (stDate Date1, stDate Date2, bool IncludeLastDay = false)
{
        int Days = 0;
        while (IsDate1BeforeDate2(Date1, Date2))
        {
            Date1 = AddingOneDayToDate(Date1);
            Days++;
        }

        return (IncludeLastDay == false ? Days : ++Days);
}

stDate GetSystemDate ()
{
    stDate Date;
    time_t t = time(0);
    tm *Now = localtime(&t);
    Date.Year = Now->tm_year + 1900;
    Date.Month = Now->tm_mon + 1;
    Date.Day = Now->tm_mday;
    return Date;
}

int main ()
{
    stDate Date1 = ReadDate();
    stDate Date2 = GetSystemDate();

    short AgeInDays = GetDiffInTwoDates(Date1, Date2);
    cout << "\nYour Age is : " << AgeInDays << " Day(s)" << endl;
    return 0;
}