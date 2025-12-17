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

float MySqrt (float number)
{
    return pow(number, 0.5);
}

int main()
{
    float Number = ReadNumber("Your number?");
    cout << "My MySqrt Result : " << MySqrt(Number) << endl;
    cout << "C++ sqrt Result: " << sqrt(Number) << endl;
    return 0;

}