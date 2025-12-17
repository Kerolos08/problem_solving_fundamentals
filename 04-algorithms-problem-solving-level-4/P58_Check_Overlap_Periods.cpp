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

int ReadNumber(string msg)
{
    int number;
    cout << msg;
    cin >> number;
    return number;
}


bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date2.Year > Date1.Year ? true : (Date2.Year == Date1.Year ? (Date2.Month > Date1.Month ? true : (Date2.Month == Date1.Month ? (Date2.Day > Date1.Day) : false)) : false));
}

bool IsDate1EqualToDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year ? (Date1.Month == Date2.Month ? (Date1.Day == Date2.Day) : false) : false);
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
    // return (Date1.Year > Date2.Year ? true : (Date1.Year == Date2.Year ? (Date1.Month > Date2.Month ? true : (Date1.Month == Date2.Month ? (Date1.Day > Date2.Day) : false)) : false));
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualToDate2(Date1, Date2));
}

stDate ReadDate()
{
    stDate Date;
    Date.Day = ReadNumber("Please Enter a Day? ");
    Date.Month = ReadNumber("\nPlease Enter a Month? ");
    Date.Year = ReadNumber("\nPlease Enter a Year? ");
    return Date;
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

enum enDateCompare
{
    Before = -1,
    Equal = 0,
    After = 1
};

enDateCompare CompareDates(stDate Date1, stDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enDateCompare ::Before;

    if (IsDate1EqualToDate2(Date1, Date2))
        return enDateCompare::Equal;

    return enDateCompare::After;
}

bool IsOverLap(stPeriod Period1, stPeriod Period2)
{
    if (CompareDates(Period2.EndDate, Period1.StartDate) == enDateCompare::Before || CompareDates(Period2.StartDate, Period1.EndDate) == enDateCompare::After)
        return false;
    else
        return true;
}

int main()
{
    cout << "\nEnter Period 1: \n";
    stPeriod Period1 = ReadDatePeriod();
    cout << "\nEnter Period 2 \n";
    stPeriod Period2 = ReadDatePeriod();

    if (IsOverLap(Period1, Period2))
    {
        cout << "Yes, Periods Overlaping\n";
    }
    else
    {
        cout << "No, Periods Not OverLaping\n";
    }
    return 0;
}