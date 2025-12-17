#include <ctime>
#include <iostream>
using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
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

bool IsDate1EqualToDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year ? (Date1.Month == Date2.Month ? (Date1.Day == Date2.Day) : false) : false);
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

stPeriod ReadDatePeriod()
{
    stPeriod Period;
    cout << "\nEnter Start Date: \n";
    Period.StartDate = ReadDate();
    cout << "\n\nEnter End Date: \n";
    Period.EndDate = ReadDate();
    return Period;
}

int CalculateTimePeriodLength (stPeriod Period, bool IncEndDay = false)
{
    return GetDiffInTwoDates(Period.StartDate, Period.EndDate, IncEndDay);
}

int main()
{
    cout << "\nEnter Period: \n";
    stPeriod Period1 = ReadDatePeriod();

    cout << "\nPeriod Length is: " << CalculateTimePeriodLength(Period1) << endl;
    cout << "Period Length (Including End Day) is: " << CalculateTimePeriodLength(Period1, true) << endl;
    return 0;
}