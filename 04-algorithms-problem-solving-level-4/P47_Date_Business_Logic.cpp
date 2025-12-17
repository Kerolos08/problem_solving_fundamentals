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

short GetDayIndexInWeek (short Year, short Month, short Day)
{
    short a = (14 - Month) / 12;
    short y = Year - a;
    short m = Month + (12 * a) - 2;
    short d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m ) / 12) ) % 7;
    return d;
}

short GetDayIndexInWeek (stDate Date)
{
    short a = (14 - Date.Month) / 12;
    short y = Date.Year - a;
    short m = Date.Month + (12 * a) - 2;
    short d = (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m ) / 12) ) % 7;
    return d;
}


short GetDiffInTwoDates (stDate Date1, stDate Date2, bool IncludeLastDay = false)
{
        int Days = 0;
        while (IsDate1BeforeDate2(Date1, Date2))
        {
            Date1 = AddingOneDayToDate(Date1);
            Days++;
        }

        return (IncludeLastDay == false ? Days : ++Days);
}

string GetDayNameBasedOnIndex (short Index)
{
    string arrDays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return arrDays[Index];
}

bool IsEndOfWeek (stDate Date)
{
    return (GetDayIndexInWeek(Date) == 6);
}

bool IsWeekEnd (stDate Date)
{
    short Index = GetDayIndexInWeek(Date);
    return (Index == 6 || Index == 5);
}

bool IsBusinessDay (stDate Date)
{
    return (!IsWeekEnd(Date));
}

short DaysUntilEndOfWeek (stDate Date)
{
    return (6 - GetDayIndexInWeek(Date));
}

short DaysUntilEndOfMonth(stDate Date)
{
    // return (NumberOfDaysInMonth(Date.Year, Date.Month) - Date.Day);
    stDate EndOFMonth;
    EndOFMonth.Day = NumberOfDaysInMonth(Date.Year, Date.Month);
    EndOFMonth.Month = Date.Month;
    EndOFMonth.Year = Date.Year;

    return GetDiffInTwoDates(Date, EndOFMonth, true);
}

short DaysUntilEndOfYear (stDate Date)
{
    stDate EndOFMonth;
    EndOFMonth.Day = 31;
    EndOFMonth.Month = 12;
    EndOFMonth.Year = Date.Year;

    return GetDiffInTwoDates(Date, EndOFMonth, true);
}


int main ()
{;
    stDate Date = GetSystemDate();
    cout << "Today is " << GetDayNameBasedOnIndex(GetDayIndexInWeek(Date));
    cout << " , " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    cout << "\nIs it End of Week?\n";
    if (IsEndOfWeek(Date))
    {
        cout << "Yes, It is the End of the Week.\n";
    }
    else
    {
        cout << "No, It is not the End of the Week.\n";
    }

    cout << "\nIs it Week End?\n";
    if (IsWeekEnd(Date))
    {
        cout << "Yes, It is a Week End.\n";
    }
    else
    {
        cout << "No, Today is " << GetDayNameBasedOnIndex(GetDayIndexInWeek(Date)) << " not a Week End.\n";
    }

    cout << "\nIs it Business Day?\n";
    if (IsBusinessDay(Date))
    {
        cout << "Yes, It is a Business Day.\n";
    }
    else
    {
        cout << "No, It is not a Business Day.\n";
    }

    cout << "\nDays Until the End of Week : " << DaysUntilEndOfWeek (Date) << " Day(s).\n";
    cout << "Days Until the End of the Month : " << DaysUntilEndOfMonth (Date) << " Day(s).\n";
    cout << "Days Until the End of the Year : " << DaysUntilEndOfYear (Date) << " Day(s).\n";
    return 0;
}