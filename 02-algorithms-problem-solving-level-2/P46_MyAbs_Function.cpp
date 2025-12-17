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

int main ()
{
    float X = ReadNumber("Your number?");
    cout << "My abs Result : " << MyAbs(X) << endl;
    cout << "C++ abs Result : " << abs(X) << endl;
    return 0;
}