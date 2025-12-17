#include <iostream>
using namespace std;

float ReadPossitiveNumber (string msg)
{
    float number;
    do
    {
    cout << msg << endl;
    cin >> number;
    } while (number < 0);
    return number;
}

float CalculateNumberOfDays (int numberofhours) 
{
    return (float) numberofhours / 24;
}

float CalculateNumberOfWeeks (int numberofhours)
{
    return (float)numberofhours / 24 / 7;
}

int main ()
{
    float numberofhours = ReadPossitiveNumber("Enter Number Of Hours");
    float numberofdays = CalculateNumberOfDays(numberofhours);
    float numberofweeks = CalculateNumberOfWeeks(numberofhours);

    cout << endl;
    cout << "Number Of Hours = " << numberofhours << endl;
    cout << "Number Of Days = " << numberofdays << endl;
    cout << "Number Of Weeks = " << numberofweeks << endl;

return 0;
}