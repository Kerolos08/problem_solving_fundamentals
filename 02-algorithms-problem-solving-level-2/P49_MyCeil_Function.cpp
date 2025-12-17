#include <iostream>
#include <string>
#include <cmath>
using namespace std;


float ReadNumber (string msg)
{
    float number;
    cout << msg << endl;
    cin >> number;
    return number;
}


float GetFraction (float number)
{
    return number - int(number);
}

int MyCeil (float number)
{
    if(abs(GetFraction(number)) > 0)
    {
        if (number > 0)
        return int(number) + 1;
        else 
        return int(number);
    }
    else
    return int(number);
}

int main ()
{
    float x = ReadNumber("Your number?");
    cout << "My ceil Result : " << MyCeil(x) << endl;
    cout << "C++ ceil Result: " << ceil(x) << endl;
    return 0;
}