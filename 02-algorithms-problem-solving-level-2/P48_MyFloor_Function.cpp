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


int MyFloor (float number)
{
    if (number < 0)
    return int(number) - 1;
    else
    return int(number);
}

int main ()
{
    float x = ReadNumber("Your number?");
    cout << "My Floor Result : " << MyFloor(x) << endl;
    cout << "C++ Floor Result: " << floor(x) << endl;
    return 0;
}