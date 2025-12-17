#include <iostream>
using namespace std;

void Dimentions (float& b, float& t)
{
    cout << "Enter Wedth Of The Rectangel" << endl;
    cin >> b;

    cout << "Enter Hight Of The Rectangel" << endl;
    cin >> t;
}

float CalculateArea (float b, float t)
{
    return b * t;
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