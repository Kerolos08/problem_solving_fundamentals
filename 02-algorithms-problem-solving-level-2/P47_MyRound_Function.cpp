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

float MyAbs (int number)
{
    if (number > 0)
    return number;
    else
    return number * -1;
}


// int MyRound (float number)
// {
//     int NonFrictionNumber = number * 10;
//     int Remainder = NonFrictionNumber % 10;
//     if (MyAbs(Remainder) >= 5)
//     {
//         if (Remainder < 0)
//         return (NonFrictionNumber / 10) - 1;
//         else
//         return (NonFrictionNumber / 10) + 1;
//     }
//     else
//     return NonFrictionNumber / 10;
// }

float GetFractionNumber (float number)
{
    return number - int(number);
}

int MyRound (float number)
{
    int integerpart = int (number);
    float FractionPart = GetFractionNumber(number);
    if (MyAbs(FractionPart) >= .5)
    {
        if (integerpart > 0)
        return ++integerpart;
        else
        return --integerpart;
    }
    else
    return integerpart;
}

int main ()
{
    float x = ReadNumber("Your number?");
    cout << "My Round Result : " << MyRound(x) << endl;
    cout << "C++ Round Result: " << round(x) << endl;
    return 0;
}