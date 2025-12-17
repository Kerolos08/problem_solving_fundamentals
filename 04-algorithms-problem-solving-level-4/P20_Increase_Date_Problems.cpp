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

stDate IncreaseDateByXDays (stDate Date, short Days)
{
    while (Days != 0)
    {
        Date = AddingOneDayToDate(Date);
        Days--;
    }
    return Date;
}

stDate IncreaseDateByOneWeekDays (stDate Date)
{
    short Days = 7;
        while (Days != 0)
    {
        Date = AddingOneDayToDate(Date);
        Days--;
    }
    return Date;
}

stDate IncreaseDateBy10Weeks (stDate Date, short Weeks)
{;
    while (Weeks != 0)
    {
        Date = IncreaseDateByOneWeekDays(Date);
        Weeks--;
    }
    return Date;
}

stDate IncreaseDateByOneMonth (stDate Date)
{
    if (Date.Month == 12)
    {
        Date.Month = 1;
        Date.Year++;
    }
    else
    {
        Date.Month++;
    }
    short DaysInMonth = NumberOfDaysInMonth(Date.Year, Date.Month);
    if (Date.Day > DaysInMonth)
    {
        Date.Day = DaysInMonth;
    }
    return Date;
}

stDate IncreaseDateByXMonths (stDate Date, short Months)
{
    while(Months != 0)
    {
        Date = IncreaseDateByOneMonth(Date);
        Months--;
    }
    return Date;
}

stDate IncreaseDateByOneYear (stDate Date)
{
    Date.Year++;
    return Date;
}

stDate IncreaseDateByXYears (stDate Date, short Years)
{
    while (Years != 0)
    {
        Date = IncreaseDateByOneYear(Date);
        Years--;
    }
    return Date;
}

stDate IncreaseDateByXYearsFaster (stDate Date, short Years)
{
    Date.Year += Years;
    return Date;
}

stDate IncreaseDateByOneDecade (stDate Date)
{
    Date = IncreaseDateByXYears(Date, 10);
    return Date;
}

stDate IncreaseDateByXDecades (stDate Date, short Decades)
{
    while (Decades != 0)
    {
        Date = IncreaseDateByOneDecade(Date);
        Decades--;
    }
    return Date;
}

stDate IncreaseDateByXDecadesFaster (stDate Date, short Decades)
{
    Date.Year += (Decades * 10);
    return Date;
}

stDate IncreaseDateByOneCentury (stDate Date)
{
    Date.Year += 100;
    return Date;
}

stDate IncreaseDateByOneMillennium (stDate Date)
{
    Date.Year += 1000;
    return Date;
}

int main ()
{
    stDate Date = ReadDate();
    cout << "\n\nDate After:\n\n";

    Date = AddingOneDayToDate(Date);
    cout << "01-Adding one Day Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    Date = IncreaseDateByXDays(Date, 10);
    cout << "\n02-Adding 10 Day Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    Date = IncreaseDateByOneWeekDays (Date);
    cout << "\n03-Adding One Week Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    Date = IncreaseDateBy10Weeks (Date, 10);
    cout << "\n04-Adding 10 Weeks Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    Date = IncreaseDateByOneMonth (Date);
    cout << "\n05-Adding One Month Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    Date = IncreaseDateByXMonths(Date, 5);
    cout << "\n06-Adding 5 Months Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    Date = IncreaseDateByOneYear (Date);
    cout << "\n07-Adding One Year Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    Date = IncreaseDateByXYears (Date, 10);
    cout << "\n08-Adding 10 Years Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    Date = IncreaseDateByXYearsFaster (Date, 10);
    cout << "\n09-Adding 10 Years Is (Faster) : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    Date = IncreaseDateByOneDecade(Date);
    cout << "\n10-Adding Decade Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    Date = IncreaseDateByXDecades (Date, 10);
    cout << "\n11-Adding 10 Decades Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    Date = IncreaseDateByXDecadesFaster (Date, 10);
    cout << "\n12-Adding 10 Decades Is (Faster) : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    Date = IncreaseDateByOneCentury (Date);
    cout << "\n13-Adding One Century Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    Date = IncreaseDateByOneMillennium (Date);
    cout << "\n14-Adding One Millennium Is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    return 0;
}