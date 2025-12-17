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

stDate ReadDate ()
{
    stDate Date;
    Date.Day = ReadNumber ("Please Enter a Day? ");
    Date.Month = ReadNumber ("\nPlease Enter a Month? ");
    Date.Year = ReadNumber("\nPlease Enter a Year? ");
    return Date;
}

bool IsDate1BeforeDate2 (stDate Date1, stDate Date2)
{
    return (Date2.Year > Date1.Year ? true : (Date2.Year == Date1.Year ? (Date2.Month > Date1.Month ? true : (Date2.Month == Date1.Month ? (Date2.Day > Date1.Day) : false)) : false ));
}

bool IsDate1EqualToDate2 (stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year ? (Date1.Month == Date2.Month ? (Date1.Day == Date2.Day) : false) : false);
}

bool IsDate1AfterDate2 (stDate Date1, stDate Date2)
{
    // return (Date1.Year > Date2.Year ? true : (Date1.Year == Date2.Year ? (Date1.Month > Date2.Month ? true : (Date1.Month == Date2.Month ? (Date1.Day > Date2.Day) : false)) : false));
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualToDate2(Date1, Date2));
}

enum enDateCompare {Before = -1, Equal = 0, After = 1};

enDateCompare CompareDates (stDate Date1, stDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
    return enDateCompare :: Before;

    if (IsDate1EqualToDate2(Date1, Date2))
    return enDateCompare::Equal;

    return enDateCompare::After;
}

int main ()
{
    stDate Date1 = ReadDate();
    cout << "\n\n";
    stDate Date2 = ReadDate();

    cout << "\n\nCompare Result = " << CompareDates(Date1, Date2) << endl;
    return 0;
}