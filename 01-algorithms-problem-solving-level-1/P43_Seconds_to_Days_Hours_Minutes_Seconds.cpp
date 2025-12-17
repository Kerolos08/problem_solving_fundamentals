#include <iostream>
using namespace std;

enum enWeekDays {sat = 1, sun = 2, mon = 3, tue = 4, wed = 5, thu = 6, fri = 7};

int ReadNumberInRange (string msg, int from, int to)
{
    int number;
    do{
        cout << msg << endl;
        cin >> number;
    }while (number < from || number > to);
    return number;
}

enWeekDays ReadDayOfTheWeek ()
{
    return (enWeekDays) ReadNumberInRange("Please Enter Day Number", 1 , 7);
}

string GetDayOfWeek (enWeekDays day)
{
    switch (day)
    {
    case enWeekDays::sat:
    return "Saturday";
    
    case enWeekDays::sun:
    return "Sunday";

    case enWeekDays::mon:
    return "Monday";

    case enWeekDays::tue:
    return "Tuesday";

    case enWeekDays::wed:
    return "Wednesday";

    case enWeekDays::thu:
    return "Thursday";

    case enWeekDays::fri:
    return "Friday";

    default:
    return "Not A Valid Day";
    }
}

int main ()
{
    cout << GetDayOfWeek(ReadDayOfTheWeek ()) << endl;
    return 0;
}