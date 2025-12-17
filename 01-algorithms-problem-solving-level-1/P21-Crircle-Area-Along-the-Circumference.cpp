#include <iostream>
#include <string>
#include <cmath>
using namespace std;

float ReadCircumference ()
{
float L;
cout << "Enter The Circumference" << endl;
cin >> L;
return L;
}

float CalculateArea (float L)
{
    const float PI = 3.14;
    float Area = (pow(L , 2)) / (4 * PI);
    return Area;
}

void PrintArea (float Area)
{
    cout << "\nArea Of Circle Is: " << Area << endl;
}

int main()
{
    PrintArea(CalculateArea(ReadCircumference()));
    return 0;
}
