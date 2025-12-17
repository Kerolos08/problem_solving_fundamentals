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

short GetTotalDaysFromBeginningOfTheYear (short Year, short Month, short Day)
{
    short TotalDays = 0;
    for (short i = 1; i < Month; i++)
    {
        TotalDays += NumberOfDaysInMonth(Year, i);
    }
    TotalDays += Day;
    return TotalDays;
}

// stDate GetTheDateBasedOnDayOrder (short Year, short TotalDays)       // My solution and it works.
// {
//     stDate Date;
//     Date.Year = Year;
//     Date.Month = 1;
//     for (int i = 1; i < 13; i++)
//     {
//         TotalDays -= NumberOfDaysInMonth(Year, i);
//         Date.Month++;
//         if (TotalDays < NumberOfDaysInMonth(Year, i + 1))
//         {
//             break;
//         }
//     };
//     Date.Day = TotalDays;
//     return Date;
// }

stDate GetTheDateBasedOnDayOrder (short Year, short TotalDays)       // Dr Mohamed's solution.
{
    stDate Date;
    short MonthDays = 0;
    short RemainingDays = TotalDays;

    Date.Year = Year;
    Date.Month = 1;
    while(true)
    {
        MonthDays = NumberOfDaysInMonth(Date.Year, Date.Month);
        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;
}

int main ()
{
    short Day = ReadNumber ("Please Enter a Day? ");
    short Month = ReadNumber ("\nPlease Enter a Month? ");
    short Year = ReadNumber("\nPlease Enter a Year? ");

    short TotalDays = GetTotalDaysFromBeginningOfTheYear(Year, Month, Day);
    cout << "\nNumber of Days form the beginning of the year is : " << TotalDays << endl;
    
    stDate Date = GetTheDateBasedOnDayOrder(Year, TotalDays);
    cout << "Date for [" << TotalDays << "] is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    return 0;
}