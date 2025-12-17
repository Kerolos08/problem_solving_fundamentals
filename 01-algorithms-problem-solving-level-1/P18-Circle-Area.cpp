#include <iostream>
using namespace std;

float ReadRadius()
{
    float R;
    cout << "Enter The Diameter Of The Circle" << endl;
    cin >> R;
    return R;
}

float CalculateCircleArea(float R)
{
    const float PI = 3.14;
    float Area = PI * R * R;
    return Area;
}

void PrintArea(float Area)
{
    cout << "\nThe Area Of Circle Is: " << Area << endl;
}

int main()
{
    PrintArea(CalculateCircleArea(ReadRadius()));
    return 0;
}