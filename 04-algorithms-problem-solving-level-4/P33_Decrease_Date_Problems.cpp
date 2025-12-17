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

stDate ReadDate ()
{
    stDate Date;
    Date.Day = ReadNumber ("Please Enter a Day? ");
    Date.Month = ReadNumber ("\nPlease Enter a Month? ");
    Date.Year = ReadNumber("\nPlease Enter a Year? ");
    return Date;
}

stDate DecreaseDateWithOneDay (stDate Date)
{
    if (Date.Day == 1)
    {
        if (Date.Month == 1)
        {
            Date.Month = 12;
            Date.Year = 31;
        }
        else
        {
            Date.Month--;
            Date.Day = NumberOfDaysInMonth(Date.Year, Date.Month);
        }
    }
    else
    {
        Date.Day--;
    }
    return Date;
}

stDate DecreaseDateByXDays (stDate Date, short Days)
{
    while (Days != 0)
    {
        Date = DecreaseDateWithOneDay(Date);
        Days--;
    }
    return Date;
}

stDate DecreaseDateByOneWeekDays (stDate Date)
{
    short Days = 7;
        while (Days != 0)
    {
        Date = DecreaseDateWithOneDay(Date);
        Days--;
    }
    return Date;
}

stDate DecreaseDateByXWeeks (stDate Date, short Weeks)
{;
    while (Weeks != 0)
    {
        Date = DecreaseDateByOneWeekDays(Date);
        Weeks--;
    }
    return Date;
}

stDate DecreaseDateByOneMonth (stDate Date)
{
    if (Date.Month == 1)
    {
        Date.Month = 1;
        Date.Year--;
    }
    else
    {
        Date.Month--;
    }
    short DaysInMonth = NumberOfDaysInMonth(Date.Year, Date.Month);
    if (Date.Day > DaysInMonth)
    {
        Date.Day = DaysInMonth;
    }
    return Date;
}

stDate DecreaseDateByXMonths (stDate Date, short Months)
{
    while(Months != 0)
    {
        Date = DecreaseDateByOneMonth(Date);
        Months--;
    }
    return Date;
}

stDate DecreaseDateByOneYear (stDate Date)
{
    Date.Year--;
    return Date;
}

stDate DecreaseDateByXYears (stDate Date, short Years)
{
    while (Years != 0)
    {
        Date = DecreaseDateByOneYear(Date);
        Years--;
    }
    return Date;
}

stDate DecreaseDateByXYearsFaster (stDate Date, short Years)
{
    Date.Year -= Years;
    return Date;
}

stDate DecreaseDateByOneDecade (stDate Date)
{
    Date = DecreaseDateByXYears(Date, 10);
    return Date;
}

stDate DecreaseDateByXDecades (stDate Date, short Decades)
{
    while (Decades != 0)
    {
        Date = DecreaseDateByOneDecade(Date);
        Decades--;
    }
    return Date;
}

stDate DecreaseDateByXDecadesFaster (stDate Date, short Decades)
{
    Date.Year -= (Decades * 10);
    return Date;
}

stDate DecreaseDateByOneCentury (stDate Date)
{
    Date.Year -= 100;
    return Date;
}

stDate DecreaseDateByOneMillennium (stDate Date)
{
    Date.Year -= 1000;
    return Date;
}

int main ()
{
    stDate Date = ReadDate();
    cout << "\n\nDate After:\n\n";

    Date = DecreaseDateWithOneDay(Date);
    cout << "01-Subtracting one Day Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    Date = DecreaseDateByXDays(Date, 10);
    cout << "\n02-Subtracting 10 Day Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    Date = DecreaseDateByOneWeekDays (Date);
    cout << "\n03-Subtracting One Week Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    Date = DecreaseDateByXWeeks (Date, 10);
    cout << "\n04-Subtracting 10 Weeks Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    Date = DecreaseDateByOneMonth (Date);
    cout << "\n05-Subtracting One Month Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    Date = DecreaseDateByXMonths(Date, 5);
    cout << "\n06-Subtracting 5 Months Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    Date = DecreaseDateByOneYear (Date);
    cout << "\n07-Subtracting One Year Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    Date = DecreaseDateByXYears (Date, 10);
    cout << "\n08-Subtracting 10 Years Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    Date = DecreaseDateByXYearsFaster (Date, 10);
    cout << "\n09-Subtracting 10 Years Is (Faster) : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    Date = DecreaseDateByOneDecade(Date);
    cout << "\n10-Subtracting Decade Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    Date = DecreaseDateByXDecades (Date, 10);
    cout << "\n11-Subtracting 10 Decades Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    Date = DecreaseDateByXDecadesFaster (Date, 10);
    cout << "\n12-Subtracting 10 Decades Is (Faster) : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    Date = DecreaseDateByOneCentury (Date);
    cout << "\n13-Subtracting One Century Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    Date = DecreaseDateByOneMillennium (Date);
    cout << "\n14-Subtracting One Millennium Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    return 0;
}