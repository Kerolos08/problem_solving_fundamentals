#include <iostream>
using namespace std;

void Dimentions (float& a, float& h)
{
    cout << "Enter Base Lengh Of The Tringle" << endl;
    cin >> a;

    cout << "Enter Hight Of The Tringle" << endl;
    cin >> h;
}

float CalculateArea (float a, float h)
{
    float Area = .5 * (a * h);
    return Area;
}

void PrintArea (float Area)
{

    cout << "The Area Of The Tringle Is: " << Area << endl;
}

int main ()
{
    float b;
    float t;
    Dimentions(b,t);
    PrintArea (CalculateArea(b,t));
    return 0;
}