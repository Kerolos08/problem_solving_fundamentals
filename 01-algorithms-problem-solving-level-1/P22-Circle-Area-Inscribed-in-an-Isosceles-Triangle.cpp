#include <iostream>
#include <cmath>
using namespace std;

void Dimentions (float& A, float& B)
{
    cout << "Enter Base Lengh Of The Tringle" << endl;
    cin >> A;

    cout << "Enter Hight Of The Tringle" << endl;
    cin >> B;
}

float CalculateArea (float A, float B)
{
    const float PI = 3.14;
    float Area = PI * (pow(B,2) / 4) * ((2 * A - B) / (2 * A + B));
    return Area;
}

void PrintArea (float Area)
{

    cout << "The Area Of The Tringle Is: " << Area << endl;
}

int main ()
{
    float A;
    float B;
    Dimentions(A,B);
    PrintArea (CalculateArea(A,B));
    return 0;
}