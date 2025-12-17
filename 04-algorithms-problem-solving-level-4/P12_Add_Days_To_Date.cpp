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

stDate Add_Days_To_Date (stDate Date, short AdditionalDays)                 // Dr Mohamed sol. starting to count from the beginning of the year
{
    short RemainingDays = GetTotalDaysFromBeginningOfTheYear(Date.Year, Date.Month, Date.Day) + AdditionalDays;
    short MonthDays = 0;
    Date.Month = 1;
    while(true)
    {
        MonthDays = NumberOfDaysInMonth(Date.Year, Date.Month);
        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;
            if (Date.Month > 12)
            {
                Date.Year++;
                Date.Month = 1;
            }
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;
}

// stDate Add_Days_To_Date (stDate Date, short AdditionalDays)            // my sol. starting to count form the same date
// {
//     short MonthDays = 0;
//     while(true)
//     {
//         MonthDays = NumberOfDaysInMonth(Date.Year, Date.Month);
//         if (AdditionalDays > MonthDays)
//         {
//             AdditionalDays -= MonthDays;
//             Date.Month++;
//             if (Date.Month > 12)
//             {
//                 Date.Year++;
//                 Date.Month = 1;
//             }
//         }
//         else
//         {
//             Date.Day += AdditionalDays;
//             break;
//         }
//     }
//     return Date;
// }


int main ()
{
    stDate Date;
    Date.Day = ReadNumber ("Please Enter a Day? ");
    Date.Month = ReadNumber ("\nPlease Enter a Month? ");
    Date.Year = ReadNumber("\nPlease Enter a Year? ");

    short AdditionalDays = ReadNumber("\nHow Many Days to Add? ");
    Date = Add_Days_To_Date(Date, AdditionalDays);
    
    cout << "Date after adding [" << AdditionalDays << "] is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    return 0;
}