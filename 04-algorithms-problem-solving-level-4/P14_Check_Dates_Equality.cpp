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

bool IsDate1EqualToDate2 (stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year ? (Date1.Month == Date2.Month ? (Date1.Day == Date2.Day) : false) : false);
}

int main ()
{
    stDate Date1 = ReadDate();
    cout << "\n\n";
    stDate Date2 = ReadDate();

    if (IsDate1EqualToDate2(Date1, Date2))
    {
        cout << "\n\nYes, Date1 is Equal to Date2\n";
    }
    else
    {
        cout << "\n\nNo, Date1 is not Equal to Date2\n";
    }
    return 0;
}