#include <iostream>
using namespace std;

enum enYearMonths {jan = 1, feb = 2, mar = 3, apr = 4, may = 5, jun = 6, jul = 7, aug = 8, sep = 9, oct = 10, nov = 11, dec = 12};

int ReadNumberInRange (string msg, int from, int to)
{
    int number;
    do{
        cout << msg << endl;
        cin >> number;
    }while (number < from || number > to);
    return number;
}

enYearMonths ReadMonthsOfTheYear ()
{
    return (enYearMonths) ReadNumberInRange("Please Enter Month number", 1 , 12);
}

string GetMonthsOfTheYear (enYearMonths month)
{
    switch (month)
    {
    case enYearMonths::jan:
    return "January";
    
    case enYearMonths::feb:
    return "February";

    case enYearMonths::mar:
    return "March";

    case enYearMonths::apr:
    return "April";

    case enYearMonths::may:
    return "May";

    case enYearMonths::jun:
    return "June";

    case enYearMonths::jul:
    return "July";

    case enYearMonths::aug:
    return "August";

    case enYearMonths::sep:
    return "September";

    case enYearMonths::oct:
    return "October";

    case enYearMonths::nov:
    return "November";

    case enYearMonths::dec:
    return "December";

    default:
    return "Not a valid Month";
    }
}

int main ()
{
    cout << GetMonthsOfTheYear(ReadMonthsOfTheYear ()) << endl;
    return 0;
}