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

short ReadNumber(string msg)
{
    short number;
    cout << msg;
    cin >> number;
    return number;
}

bool Is_Leap(short Year)
{
    // return (Year % 400 == 0 ? true : Year % 100 == 0 ? false : Year % 4 == 0 ? true : false);
    return (Year % 100 != 0 && Year % 4 == 0) || (Year % 400 == 0);
}

stDate ReadDate()
{
    stDate Date;
    Date.Day = ReadNumber("Please Enter a Day? ");
    Date.Month = ReadNumber("\nPlease Enter a Month? ");
    Date.Year = ReadNumber("\nPlease Enter a Year? ");
    return Date;
}

string GetDayNameBasedOnIndex(short Index)
{
    string arrDays[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return arrDays[Index];
}

short GetDayIndexInWeek(stDate Date)
{
    short a = (14 - Date.Month) / 12;
    short y = Date.Year - a;
    short m = Date.Month + (12 * a) - 2;
    short d = (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    return d;
}

bool IsWeekEnd(stDate Date)
{
    short Index = GetDayIndexInWeek(Date);
    return (Index == 6 || Index == 5);
}

bool IsBusinessDay (stDate Date)
{
    return (!IsWeekEnd(Date));
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date2.Year > Date1.Year ? true : (Date2.Year == Date1.Year ? (Date2.Month > Date1.Month ? true : (Date2.Month == Date1.Month ? (Date2.Day > Date1.Day) : false)) : false));
}

bool IsDate1EqualToDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year ? (Date1.Month == Date2.Month ? (Date1.Day == Date2.Day) : false) : false);
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

bool Is_LastDayInTheMonth(stDate Date)
{
    short MonthDays = NumberOfDaysInMonth(Date.Year, Date.Month);
    return (Date.Day == MonthDays);
}

bool Is_LastMonthInTheYear(stDate Date)
{
    return (Date.Month == 12);
}

stDate AddingOneDayToDate(stDate Date)
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

short GetDiffInTwoDates(stDate Date1, stDate Date2, bool IncludeLastDay = false)
{
    int Days = 0;
    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Date1 = AddingOneDayToDate(Date1);
        Days++;
    }

    return (IncludeLastDay == false ? Days : ++Days);
}

stDate CalculateReturnDateAfterVacation (stDate Date, short VacDays)
{
    while(VacDays != 0)
    {
        if (IsWeekEnd(Date))
        {
            Date = AddingOneDayToDate(Date);
            continue;
        }
        else
        {
            Date = AddingOneDayToDate(Date);
            VacDays--;
        }
    }

    while (IsWeekEnd(Date))
    {
        Date = AddingOneDayToDate(Date);
    }
    return Date;
}


int main()
{
    cout << "\nVacation Starts: \n";
    stDate StartDate = ReadDate();

    short ActualVacationDays = ReadNumber("\nPlease Enter Vacation Days? ");

    
    stDate ReturnDate = CalculateReturnDateAfterVacation(StartDate, ActualVacationDays);
    cout << "\n\nReturn Date : " << GetDayNameBasedOnIndex(GetDayIndexInWeek(ReturnDate)) << " , ";
    cout << ReturnDate.Day << "/" << ReturnDate.Month << "/" << ReturnDate.Year << endl;

    return 0;
}