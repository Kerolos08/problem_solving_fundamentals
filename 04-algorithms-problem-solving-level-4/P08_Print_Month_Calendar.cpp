#include <iostream>
using namespace std;

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

short GetDayIndexInWeek (short Year, short Month, short Day)
{
    short a = (14 - Month) / 12;
    short y = Year - a;
    short m = Month + (12 * a) - 2;
    short d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m ) / 12) ) % 7;
    return d;
}

string GetMonthName (short Month)
{
    string arrDays[13] = {" ", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    return arrDays[Month];
}

void PrintMonthCalendar (short Year, short Month)
{
    printf("\n\n_______________%s_______________", GetMonthName(Month).c_str());
    cout << "\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n";
    short IndexOfFristDay = GetDayIndexInWeek(Year, Month, 1);
    short DaysInMonth = NumberOfDaysInMonth(Year, Month);
    short j = 0;
    for (j = 0; j < IndexOfFristDay; j++)          // ? printing spaces untill we reach the index of frist day
        {
            printf("     ");
        }
    for (short i = 1; i <= DaysInMonth; i++)      // ! printing actual days of the month in their index
    {
        printf("%3d" , i);                        // ? this for putting the day in its space (3 spaces)
        printf("  ");                             // ! 2 spaces between the digits in table
        if (++j == 7)                             // ! this condition makes the program going to the next line when reach last day in week
        {
            printf("\n");
            j = 0;
        }
    }
    printf("\n_________________________________");
}

int main ()
{
    short Year = ReadNumber("Please Enter a Year? ");
    short Month = ReadNumber ("\nPlease Enter a Month? ");
    PrintMonthCalendar(Year, Month);
    return 0;
}