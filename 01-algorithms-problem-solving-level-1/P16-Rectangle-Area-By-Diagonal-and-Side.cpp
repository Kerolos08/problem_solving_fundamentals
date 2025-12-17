#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void Dimentions (float& a, float& d)
{
    cout << "Enter Side Lengh Of The Rectangel" << endl;
    cin >> a;

    cout << "Enter Diagonal Lengh Of The Rectangel" << endl;
    cin >> d;
}

float CalculateArea (float a, float d)
{
    float Area = a * sqrt(pow(d , 2) - pow(a , 2));
    return Area;
}

void PrintArea (float Area)
{

    cout << "The Area Of The Rectangel Is: " << Area << endl;
}

int main ()
{
    float b;
    float t;
    Dimentions(b,t);
    PrintArea (CalculateArea(b,t));
    return 0;
}