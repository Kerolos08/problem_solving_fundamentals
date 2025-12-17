#include <iostream>
#include <cmath>
#include <string>
using namespace std;

float ReadDiameter ()
{
    int D;
    cout << "Enter The Diameter" << endl;
    cin >> D;
    return D;
}

float CalculateAreaByDiameter (int D)
{
    const float PI = 3.14;
    float Area = PI * (pow(D , 2) / 4);
    return Area;
}

void PrintResult (float Area)
{
    cout << "\nThe Area Of Circle Is: " << Area << endl;
}

int main()
{
    PrintResult(CalculateAreaByDiameter(ReadDiameter()));
    return 0;
}