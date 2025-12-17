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

short GetDayIndexInWeek (short Year, short Month, short Day)
{
    short a = (14 - Month) / 12;
    short y = Year - a;
    short m = Month + (12 * a) - 2;
    short d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m ) / 12) ) % 7;
    return d;
}

string GetDayNameBasedOnIndex (short Index)
{
    string arrDays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return arrDays[Index];
}

int main ()
{
    short Year = ReadNumber("Please Enter a Year? ");
    short Month = ReadNumber ("\nPlease Enter a Month? ");
    short Day = ReadNumber ("\nPlease Enter a Day? ");

    cout << "\nDate      : " << Day << "/" << Month << "/" << Year;
    cout << "\nDay Order : " << GetDayIndexInWeek(Year, Month, Day);
    cout << "\nDay Name  : " << GetDayNameBasedOnIndex(GetDayIndexInWeek(Year, Month, Day));
    
    return 0;
}